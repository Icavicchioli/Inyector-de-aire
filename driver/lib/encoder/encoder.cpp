typedef struct encoder
{
	int pin_outputA;
	int pin_outputB;
	int pin_button;
	int state;
  	int factor_correccion;//el encoder que usamos se traba de a 2 y suma o resta 2
}encoder_t;


//inicializa la instancia de la estructura, usalo en el void setup con los pines
encoder_t initialize_encoder(int pin_outputA, int pin_outputB, int pin_button, int factor_correccion)
{
  	pinMode(pin_outputA,INPUT);
  	pinMode(pin_outputB,INPUT);
  	pinMode(pin_button,INPUT);
	encoder_t encoder_local;//objeto local, le metemos los datos
	encoder_local.pin_outputA = pin_outputA;
	encoder_local.pin_outputB = pin_outputB;
	encoder_local.pin_button = pin_button;
  	encoder_local.state = 2*digitalRead(pin_outputA)+digitalRead(pin_outputB);
  	encoder_local.factor_correccion = factor_correccion; 
	return encoder_local;//que pise el objeto afuera, podria hacerse con punteros??
}



int get_encoder_direction(encoder_t * encoder_local)
{
  //recibe el puntero al objeto, el error anterios era que el estado actrual se guardaba aca adentro y no afuera. 
	//chequea para donde giró el encoder. Si avanzó en el gray, tipo de 0 -> 1 -> 3 -> 2 -> 0 devuelve 1. si retrocede devuelve -1, si es igual devuelve 0;

	int current_value = 2*digitalRead(encoder_local -> pin_outputA)+digitalRead(encoder_local -> pin_outputB);//calculo el valor actual con el mismo criterio que antes, uso binario grey
	int result = 0;
	int old_value = encoder_local -> state;//opimizable creo
  
	if(old_value == current_value)
	{
		result = 0; //funciona
	}
	else
	{
		switch(current_value){
			case 0:
				if(old_value==2){result=1;}else if(old_value==1){result=-1;}//si el actual es cero y viene de 2 avanza, si viene de 1 retrocede
				break;
			case 1:
				if(old_value==0){result=1;}else if(old_value==3){result=-1;}
				break;
			case 2:
				if(old_value==3){result=1;}else if(old_value==0){result=-1;}
				break;
			case 3:
				if(old_value==1){result=1;}else if(old_value==2){result=-1;}
				break;
			}	
	}
  encoder_local -> state = current_value;// asi sirve después
  return result;
}

bool get_button_state(encoder_t encoder_local)
{
	return digitalRead(encoder_local.pin_button);
}

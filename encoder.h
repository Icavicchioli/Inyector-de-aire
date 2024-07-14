//creo una instancia del encoder que va a contener su información
struct encoder
{
	int pin_outputA;
	int pin_outputA;
	int pin_button;
	int state;
};

//inicializa la instancia de la estructura, usalo en el void setup con los pines
struct encoder initialize_encoder(pin_outputA, pin_outputB,pin_button)
{
	struct encoder local;
	local.pin_outputA = pin_outputA;
	local.pin_outputA = pin_outputB;
	local.pin_outputA = pin_button;
	local.state = 2*digitalRead(pin_outputA)+digitalRead(pin_outputB);
	return encoder;
}


int get_encoder_direction(struct encoder)
{
	//chequea para donde giró el encoder. Si avanzó en el gray, tipo de 0 -> 1 -> 3 -> 2 -> 0 devuelve 1. si retrocede devuelve -1, si es igual devuelve 0;

	unsigned int current_value = 2*digitalRead(pin_outputA)+digitalRead(pin_outputB);//calculo el valor actual con el mismo criterio que antes, uso binario grey
	int result = 0;
	int old_value = encoder.state;//opimizable creo
	if(old_value == current_value)
	{
		return result;
	}
	else
	{
		switch(current_value){
			case 0:
				if(old_value==2){result=1;}else{result=-1;}//si el actual es cero y viene de 2 avanza, si viene de 1 retrocede
				break;
			case 1:
				if(old_value==0){result=1;}else{result=-1;}
				break;
			case 2:
				if(old_value==3){result=1;}else{result=-1;}
				break;
			case 3:
				if(old_value==1){result=1;}else{result=-1;}
				break;
			}
		encoder.state = current_value;// asi sirve después
	return result;
	}

bool get_button_state(struct encoder)
{
	return digitalRead(encoder.pin_button);
}
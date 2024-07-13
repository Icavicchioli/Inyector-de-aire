
#define D2 2  //dir, en 0 retrocede, 1 avanza
#define D5 5  //enable, 0 funca
#define D7 7  //boton avance
#define D8 8  //boton retroceso
#define D3 3  //step

void paso() {
  digitalWrite(D3, 1);
 delay(1);
  digitalWrite(D3, 0);
 delay(1);
}

void avanzar(){
  delay(50);
  if (digitalRead(D7) == 1) {
    digitalWrite(D2, 1);
    while (digitalRead(D7) == HIGH) {
      paso();
    }
  }else{
    return;
  }
}

void retroceder(){
  delay(50);
  if (digitalRead(D8) == 1) {
    digitalWrite(D2, 0);
    while (digitalRead(D8) == HIGH) {
      paso();
    }
  }else{
    return;
  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D7, INPUT);
  pinMode(D8, INPUT);
  digitalWrite(D2, 1);
  digitalWrite(D5, 1);  //enable en cero anda
}

void loop() {
  //put your main code here, to run repeatedly:
  if (digitalRead(D7) == 1) {
    avanzar();
  }

  if (digitalRead(D8) == 1) {
    retroceder();
  }


}




#include <Arduino.h>

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



/* 
#include <Arduino.h>
#include "limit_switch.h"

#define D2_DIR 2       // dir: BACKWARD => 0, FORWARD => 1, starts in 1 (FORWARD)
#define D3_STEP 3      // step
#define D4_SLEEP 4     // sleep
#define D5_ENABLE 5    // enable: MOTOR_ON => 0, MOTOR_OFF => 1, starts in 1 (MOTOR_OFF)
#define D7_FORWARD 7   // forward button
#define D8_BACKWARD 8  // backward button

// Limit Switches, active: from LOW to HIGH
#define D9_HEAD_LS 8   // head limit switch
#define D10_TAIL_LS 8  // tail limit switch

// direction
#define FORWARD 1
#define BACKWARD 0

// step pulse, in milliseconds
#define TIME_HIGH 1
#define TIME_LOW 1

ls_t head_limit_switch = NULL;
ls_t tail_limit_switch = NULL;

void setup() {
  // put your setup code here, to run once:
  pinMode(D2_DIR, OUTPUT);
  pinMode(D3_STEP, OUTPUT);
  pinMode(D4_SLEEP, OUTPUT);
  pinMode(D5_ENABLE, OUTPUT);

  pinMode(D7_FORWARD, INPUT);
  pinMode(D8_BACKWARD, INPUT);

  digitalWrite(D2_DIR, HIGH);     // starts in 1 (FORWARD)
  digitalWrite(D5_ENABLE, HIGH);  // starts in 1 (MOTOR_OFF)

  head_limit_switch = setup_limit_switch();
  tail_limit_switch = setup_limit_switch();

  Serial.begin(9600);
}

void step() {
  digitalWrite(D3_STEP, HIGH);
  delay(TIME_HIGH);
  digitalWrite(D3_STEP, LOW);
  delay(TIME_LOW);
}

void plunger_move_forward() {
  delay(50);
  if (digitalRead(D7_FORWARD) == HIGH) {
    digitalWrite(D2_DIR, FORWARD);
    while (digitalRead(D9_HEAD_LS) == LOW && digitalRead(D7_FORWARD) == HIGH) {
      step();
    }
  }
}

void plunger_reset_position() {
  digitalWrite(D2_DIR, BACKWARD);
  while (digitalRead(D10_TAIL_LS) == LOW) {
    step();
  }
}

void loop() {
  //put your main code here, to run repeatedly:
  if (!head_ls_state && digitalRead(D7_FORWARD) == HIGH) 
    plunger_move_forward();

  if (!tail_ls_state && digitalRead(D8_BACKWARD) == HIGH) 
    plunger_reset_position();

  if (digitalRead(D10_TAIL_LS) == LOW)
}


*/
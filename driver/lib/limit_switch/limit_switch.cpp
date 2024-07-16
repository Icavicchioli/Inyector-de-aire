#include "limit_switch.h"

volatile bool is_limit_reached = false;

void limit_switch_active_interrupt(){
  Serial.println("Limit Switch active");

  is_limit_reached = true;
}

void limit_switch_create(int limit_switch_pin){
  pinMode(limit_switch_pin, INPUT);

  attachInterrupt(digitalPinToInterrupt(limit_switch_pin), limit_switch_active_interrupt, CHANGE);
}
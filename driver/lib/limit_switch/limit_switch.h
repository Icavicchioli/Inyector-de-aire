#ifndef LIMIT_SWITCH_H
#define LIMIT_SWITCH_H

#include <Arduino.h>

typedef struct limit_switch {
  int pin;
  bool is_limit_reached;
} ls_t;

// Funciones para configurar los interruptores de límite
void setup_limit_switch();

// Funciones para manejar los estados de los interruptores de límite
bool isLimitReached1();
bool isLimitReached2();
void resetLimitReached1();
void resetLimitReached2();
bool shouldExitLoops();

#endif

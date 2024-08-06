#include "encoder.h"

typedef enum 
{
	STATE_0 = 0,
	STATE_1 = 1,
	STATE_2 = 2,
	STATE_3 = 3
} encoder_state_t;

typedef struct encoder
{
	int pin_outputA;
	int pin_outputB;
	int pin_button;
	encoder_state_t state;
  	int factor_correccion; // El encoder que usamos se traba de a 2 y suma o resta 2
} encoder_t;

// Inicializa la instancia de la estructura, úsalo en el void setup con los pines
void initialize_encoder(encoder_t *encoder, int pin_outputA, int pin_outputB, int pin_button, int factor_correccion)
{
	// Configuración de los pines de salida A y B del encoder como entradas
  	pinMode(pin_outputA, INPUT);
  	pinMode(pin_outputB, INPUT);
	// Configuración del pin del botón
  	pinMode(pin_button, INPUT);
	
	// Creación de una instancia local de la estructura encoder_t
	encoder->pin_outputA = pin_outputA;
	encoder->pin_outputB = pin_outputB;
	encoder->pin_button = pin_button;
  	encoder->state = (encoder_state_t)(2 * digitalRead(pin_outputA) + digitalRead(pin_outputB));
  	encoder->factor_correccion = factor_correccion; 
}

int get_encoder_direction(encoder_t *encoder)
{
	// Recibe el puntero al objeto, el error anterior era que el estado actual se guardaba acá adentro y no afuera.
	// Chequea para dónde giró el encoder. Si avanzó en el gray, tipo de 0 -> 1 -> 3 -> 2 -> 0 devuelve 1.
	// Si retrocede devuelve -1, si es igual devuelve 0;

	encoder_state_t current_value = (encoder_state_t)(2 * digitalRead(encoder->pin_outputA) + digitalRead(encoder->pin_outputB)); // Cálculo del valor actual con el mismo criterio que antes, uso binario gray
	int result = 0;
	encoder_state_t old_value = encoder->state;

	if (old_value != current_value) 
	{
		// Verifica el cambio de estado del encoder para determinar la dirección del movimiento
		switch (current_value)
		{
		case STATE_0:
			if (old_value == STATE_2)
			{
				result = 1; // Movimiento hacia adelante
			}
			else if (old_value == STATE_1)
			{
				result = -1; // Movimiento hacia atrás 
			}
			break;
		case STATE_1:
			if (old_value == STATE_0)
			{
				result = 1;
			}
			else if (old_value == STATE_3)
			{
				result = -1;
			}
			break;
		case STATE_2:
			if (old_value == STATE_3)
			{
				result = 1;
			}
			else if (old_value == STATE_0)
			{
				result = -1;
			}
			break;
		case STATE_3:
			if (old_value == STATE_1)
			{
				result = 1;
			}
			else if (old_value == STATE_2)
			{
				result = -1;
			}
			break;
		}
	}

	// Actualiza el estado del encoder
	encoder->state = current_value;
	return result;
}

bool get_button_state(encoder_t *encoder)
{
	return digitalRead(encoder->pin_button);
}

//creo una instancia del encoder que va a contener su información
typedef struct encoder encoder_t;


//inicializa la instancia de la estructura, usalo en el void setup con los pines
encoder_t initialize_encoder(int pin_outputA, int pin_outputB, int pin_button);


int get_encoder_direction(encoder_t encoder_local);

bool get_button_state(encoder_t encoder_local);
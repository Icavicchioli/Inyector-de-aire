typedef enum sentido{left=0, right=1}sentido_t;

class Stepper_driver{
    public:
    void set_enable_pin(int pin_enable);
    void set_direction_pin(int pin_direction);
    void set_reset_pin(int pin_reset);
    void set_sleep_pin(int pin_sleep);
    void set_step_pin(int pin_step);
    void set_M0_pin(int pin_M0);
    void set_M1_pin(int pin_M1);
    void set_M2_pin(int pin_M2);
    void step();
    void set_direction(int dir);

    private:
        pin_enable_;
        pin_direction_;
        pin_reset_;
        pin_sleep_;
        pin_step_;
        pin_M0_;
        pin_M1_;
        pin_M2_;
};

void Stepper_driver::set_enable_pin(pin_enable){
    pin_enable_ = pin_enable;
    pinMode(pin_enable,OUTPUT);
};

void Stepper_driver::set_direction_pin(pin_direction){
    pin_direction_ = pin_direction;
    pinMode(pin_direction,OUTPUT);
};

void Stepper_driver::set_reset_pin(pin_reset){
    pin_reset_ = pin_reset;
    pinMode(pin_reset,OUTPUT);
};

void Stepper_driver::set_sleep_pin(pin_sleep){
    pin_sleep_=pin_sleep;
    pinMode(pin_sleep,OUTPUT);
};

void Stepper_driver::set_step_pin(pin_step){
    pin_step_=pin_step;
    pinMode(pin_step,OUTPUT);
};

void Stepper_driver::set_M0_pin(pin_M0){
    pin_M0_=pin_M0;
    pinMode(pin_M0,OUTPUT);
};

void Stepper_driver::set_M1_pin(pin_M1){
    pin_M1_=pin_M1;
    pinMode(pin_M1,OUTPUT);
};

void Stepper_driver::set_M2_pin(pin_M2){
|   pin_M2_=pin_M2;
    pinMode(pin_M2,OUTPUT);
};

void Stepper_driver::step(){
    digitalWrite(pin_step_, 1);
    delay(1);
    digitalWrite(pin_step_, 0);
    delay(1);
};

void Stepper_driver::set_direction(sentido_t dir){
    digitalWrite(pin_direction_,dir);
};
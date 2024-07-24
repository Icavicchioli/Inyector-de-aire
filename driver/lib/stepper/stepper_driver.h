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
};

void Stepper_driver::set_direction_pin(pin_direction){
    pin_direction_ = pin_direction;
};

void Stepper_driver::set_reset_pin(pin_reset){
    pin_reset_ = pin_reset;
};

void Stepper_driver::set_sleep_pin(pin_sleep){
    pin_sleep_=pin_sleep;
};

void Stepper_driver::set_step_pin(pin_step){
    pin_step_=pin_step;
};

void Stepper_driver::set_M0_pin(pin_M0){
    pin_M0_=pin_M0;
};

void Stepper_driver::set_M1_pin(pin_M1){
    pin_M1_=pin_M1;
};

void Stepper_driver::set_M2_pin(pin_M2){
|   pin_M2_=pin_M2;
};

void Stepper_driver::step(){
    digitalWrite(pin_step_, 1);
    delay(1);
    digitalWrite(pin_step_, 0);
    delay(1);
};

void Stepper_driver::set_direction(int dir){


};
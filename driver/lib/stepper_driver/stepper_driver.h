typedef enum sentido{retrocede=0, avanza=1}sentido_t;
//dir, en 0 retrocede, 1 avanza
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
        void move_steps(sentido_t dir, int steps);

    private:
        void step();
        void set_direction(sentido_t dir);    
        int pin_enable_;
        int pin_direction_;
        int pin_reset_;
        int pin_sleep_;
        int pin_step_;
        int pin_M0_;
        int pin_M1_;
        int pin_M2_;
};

void Stepper_driver::set_enable_pin(int pin_enable){
    this->pin_enable_ = pin_enable;
    pinMode(pin_enable,OUTPUT);
};

void Stepper_driver::set_direction_pin(int pin_direction){
    this->pin_direction_ = pin_direction;
    pinMode(pin_direction,OUTPUT);
};

void Stepper_driver::set_reset_pin(int pin_reset){
    this->pin_reset_ = pin_reset;
    pinMode(pin_reset,OUTPUT);
};

void Stepper_driver::set_sleep_pin(int pin_sleep){
    this->pin_sleep_=pin_sleep;
    pinMode(pin_sleep,OUTPUT);
};

void Stepper_driver::set_step_pin(int pin_step){
    this->pin_step_=pin_step;
    pinMode(pin_step,OUTPUT);
};

void Stepper_driver::set_M0_pin(int pin_M0){
    this->pin_M0_=pin_M0;
    pinMode(pin_M0,OUTPUT);
};

void Stepper_driver::set_M1_pin(int pin_M1){
    this->pin_M1_=pin_M1;
    pinMode(pin_M1,OUTPUT);
};

void Stepper_driver::set_M2_pin(int pin_M2){
   this->pin_M2_=pin_M2;
    pinMode(pin_M2,OUTPUT);
};

void Stepper_driver::step(){
    digitalWrite(this->pin_step_, 1);
    delay(1);
    digitalWrite(this->pin_step_, 0);
    delay(1);
};

void Stepper_driver::set_direction(sentido_t dir){
    digitalWrite(this->pin_direction_,dir);
};


void Stepper_driver::move_steps(sentido_t dir, int steps){
    this->set_direction(dir);
    for(int x=0; x < steps ; x++){
        this->step();
    };
};

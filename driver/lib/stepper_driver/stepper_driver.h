typedef enum sentido{retrocede=0, avanza=1}sentido_t;
//dir, en 0 retrocede, 1 avanza
class Stepper_driver{
    public:
        void move_steps(sentido_t dir, int steps);
        void initialize_stepper(char pin_enable,char pin_direction,char pin_reset,char pin_sleep,char pin_step,char pin_M0,char pin_M1,char pin_M2);

    private:
        void set_enable_pin(char pin_enable);
        void set_direction_pin(char pin_direction);
        void set_reset_pin(char pin_reset);
        void set_sleep_pin(char pin_sleep);
        void set_step_pin(char pin_step);
        void set_M0_pin(char pin_M0);
        void set_M1_pin(char pin_M1);
        void set_M2_pin(char pin_M2);
        void step();
        void set_direction(sentido_t dir);
        void enable_motor();
        void disable_motor();   
        void reset_motor();
        void sleep_motor();
        void wake_motor();
        int pin_enable_;
        int pin_direction_;
        int pin_reset_;
        int pin_sleep_;
        int pin_step_;
        int pin_M0_;
        int pin_M1_;
        int pin_M2_;
};

void Stepper_driver::set_enable_pin(char pin_enable){
    this->pin_enable_ = pin_enable;
    pinMode(pin_enable,OUTPUT);
    digitalWrite(pin_enable,0);
};

void Stepper_driver::set_direction_pin(char pin_direction){
    this->pin_direction_ = pin_direction;
    pinMode(pin_direction,OUTPUT);
    digitalWrite(pin_direction,0);
};

void Stepper_driver::set_reset_pin(char pin_reset){
    this->pin_reset_ = pin_reset;
    pinMode(pin_reset,OUTPUT);
    digitalWrite(pin_reset,0);
};

void Stepper_driver::set_sleep_pin(char pin_sleep){
    this->pin_sleep_=pin_sleep;
    pinMode(pin_sleep,OUTPUT);
    digitalWrite(pin_sleep,0);
};

void Stepper_driver::set_step_pin(char pin_step){
    this->pin_step_=pin_step;
    pinMode(pin_step,OUTPUT);
    digitalWrite(pin_step,0);
};

void Stepper_driver::set_M0_pin(char pin_M0){
    this->pin_M0_=pin_M0;
    pinMode(pin_M0,OUTPUT);
    digitalWrite(pin_M0,0);
};

void Stepper_driver::set_M1_pin(char pin_M1){
    this->pin_M1_=pin_M1;
    pinMode(pin_M1,OUTPUT);
    digitalWrite(pin_M1,0);
};

void Stepper_driver::set_M2_pin(char pin_M2){
   this->pin_M2_=pin_M2;
    pinMode(pin_M2,OUTPUT);
    digitalWrite(pin_M2,0);
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


void Stepper_driver::enable_motor(){
    digitalWrite(this->pin_enable_,0);
};

void Stepper_driver::disable_motor(){
    digitalWrite(this->pin_enable_,1);
};

void Stepper_driver::reset_motor(){
    digitalWrite(this->pin_reset_,0);
    delay(5);
    digitalWrite(this->pin_reset_,1);

};

void Stepper_driver::sleep_motor(){
    digitalWrite(this->pin_sleep_,0);
};

void Stepper_driver::wake_motor(){
    digitalWrite(this->pin_sleep_,1);
};

void Stepper_driver::initialize_stepper(char pin_enable,char pin_direction,char pin_reset,char pin_sleep,char pin_step,char pin_M0,char pin_M1,char pin_M2){
    this->set_enable_pin(pin_enable);

    this->disable_motor();

    this->set_direction_pin(pin_direction);

    this->set_reset_pin(pin_reset);

    this->set_sleep_pin(pin_sleep);

    this->set_step_pin(pin_step);

    this->set_M0_pin(pin_M0);

    this->set_M1_pin(pin_M1);

    this->set_M2_pin(pin_M2);
    this->wake_motor();
    this->reset_motor();
};
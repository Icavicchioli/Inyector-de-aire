class Stepper{
    public:
    void set_enable_pin();
    void set_direction_pin();
    void set_reset_pin();
    void set_sleep_pin();
    void set_step_pin();
    void set_M0_pin();
    void set_M1_pin();
    void set_M2_pin();

    private:
        pin_enable;
        pin_direction;
        pin_reset;
        pin_sleep;
        pin_step;
        pin_M0;
        pin_M1;
        pin_M2;
};

void Stepper::set_enable_pin();

void Stepper::set_direction_pin();

void Stepper::set_reset_pin();

void Stepper::set_sleep_pin();

void Stepper::set_step_pin();


void Stepper::set_M0_pin();

void Stepper::set_M1_pin();

void Stepper::set_M2_pin();

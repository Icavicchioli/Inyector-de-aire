/* Main.ino file generated by New Project wizard
 *
 * Created:   mar. ago. 6 2024
 * Processor: Arduino Nano
 * Compiler:  Arduino AVR (Proteus)
 */

// Peripheral Configuration Code (do not edit)
//---CONFIG_BEGIN---
#pragma GCC push_options
#pragma GCC optimize ("Os")

#include <Core.h> // Required by cpu
#include <cpu.h>

#pragma GCC pop_options

// Peripheral Constructors
CPU &cpu = Cpu;

void peripheral_setup () {
}

void peripheral_loop() {
}
//---CONFIG_END---

#pragma GCC push_optionss
#pragma GCC optimize ("O1")


#include "stepper_driver.h"
#include "encoder.h"
#include <wire.h>
#include <LiquidCrystal_I2C.h>
//#include <params_maquina.h>
#include <menu.h>
#include "params_maquina.h"

//el stepper
Stepper_driver mi_stepper;

//el encoder
Encoder mi_encoder;


//funciones del menu
void setear_pasos();
void ejecutar();

//otras funciones
unsigned int calcular_pasos(float volumen);
void clearRow(int row);
void asignar_interrupcion(int pin);
const float resolucion = 0.05;
const int pin_final_carrera_1 = 2;//para las interrupciones
const int pin_final_carrera_2 = 3;//para las interrupciones
void interrupcion_FC1(void);
void interrupcion_FC2(void);
volatile int int_flag=0;
void reinicio();


//estructura del menu
const MenuItem menuItems[] = {
    {"Volumen Burbuja", setear_volumen},
    {"Ejecutar", ejecutar},
};

const size_t numMenuItems = sizeof(menuItems) / sizeof(menuItems[0]);//el tamanio del menu?

Menu menu(menuItems, numMenuItems, lcd);//el objeto menu

int a;
unsigned int pasos = 1;
float volumen_actual;

//parametros
Parametros_Maquina mi_params;


void setup () {
peripheral_setup();

// TODO: put your setup code here, to run once:
	mi_stepper.initialize_stepper(11,4,7,6,5,10,9,8);//(char pin_enable,char pin_direction,char pin_reset,char pin_sleep,char pin_step,char pin_M0,char pin_M1,char pin_M2)
	mi_encoder.initialize_encoder(A0,A1,A2,1);
  
	mi_params.set_resolucion_driver(200);// pasos/rev
	mi_params.set_avance(0.004);//0.004mm/paso
	mi_params.set_volumen_jeringa(20);//20 ml
	mi_params.set_volumen_por_paso(0.001265);//20ml/62mm = 0,32258064516129032258064516129032 ml/mm *0.004mm/paso =  0,00129032258064516129032258064516 ml/paso
	mi_params.set_volumen_burbuja(1);//0.2 ml
	volumen_actual=mi_params.get_volumen_burbuja();

	attachInterrupt(digitalPinToInterrupt(pin_final_carrera_1),interrupcion_FC1, FALLING); 
	attachInterrupt(digitalPinToInterrupt(pin_final_carrera_2), interrupcion_FC2, FALLING); 
//Serial.begin(9600);
	lcd.init();       // Initialize the LCD
	lcd.backlight();  // Turn on the LCD backlight
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Iniciando...");
    delay(2000);
    menu.next_Item();
}


void loop() {
//peripheral_loop();
// TODO: put your main code here, to run repeatedly:

   a = mi_encoder.get_encoder_direction();
   if(a!=0){
      if(a==-1){menu.next_Item();}else{menu.previous_Item();}//recorremos el menu
      delay(10);
 }
 
 if(mi_encoder.get_button_state()==false){
 while(mi_encoder.get_button_state()==false);
   menu.select_Current_Item();//entramos al menu
 }
	if(int_flag==1){
		reinicio();
	}
}



//acciones del menu
void setear_volumen(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ingrese volumen:");	
    lcd.setCursor(0,1);
	lcd.print(volumen_actual);
	lcd.print(" ml");
    while(true){   
       a = mi_encoder.get_encoder_direction();
	if(a!=0){
	    
	    volumen_actual =volumen_actual + a*resolucion;//no leo de vuelta
	    if(volumen_actual<=0){volumen_actual=0;}//para que no desborde para el otro lado
		if(volumen_actual>2){volumen_actual=2;}//para que no desborde para el otro lado
		clearRow(1);
	    lcd.setCursor(0,1);
	    lcd.print(volumen_actual);
		lcd.print(" ml");
	 }
	 if(mi_encoder.get_button_state()==false){ while(mi_encoder.get_button_state()==false);break;}//salimos
    }
	mi_params.set_volumen_burbuja(volumen_actual);
    menu.display_Current_Item();//para que vuelva bien
}

void ejecutar(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ejecutar");
    pasos = calcular_pasos(mi_params.get_volumen_burbuja());
    mi_stepper.move_steps(avanza,pasos);
    menu.display_Current_Item();//para que vuelva bien
};


unsigned int calcular_pasos(float volumen){
      unsigned int a = volumen/mi_params.get_volumen_por_paso();
      return a;

};


void clearRow(int row) {
  if (row < 0 || row >= 2) {
    // If the row is out of bounds (LCDs are usually 2-row displays)
    return;
  }
  lcd.setCursor(0, row); // Move the cursor to the beginning of the specified row
  // Print spaces to clear the row
  for (int i = 0; i < 16; i++) { // Assuming a 16-column display
    lcd.print(" ");
  }
  
};



void interrupcion_FC1(void){
	if(int_flag==0){
		int_flag=1;
	}
};


void interrupcion_FC2(void){
	if(int_flag==1){
		int_flag=0;
	}
};

void reinicio(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Reiniciando");
	while(int_flag==1){
		mi_stepper.move_steps(retrocede,25);//sale con la interrupcion 2
	}
	delay(100);
	mi_stepper.move_steps(avanza,1000);//nos movemos hasta que dejamos de tocar	
	menu.display_Current_Item();//para que vuelva bien
	int_flag=0;
}

#pragma GCC pop_options

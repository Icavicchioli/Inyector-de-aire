
//lib de clase para ctes

//usa la eeprom para guardar las cosas
#include <EEPROM.h>
//se va a guardar la instancia de parámetros entera en la eeprom y se lee desde 0


//proteus no trabaja nativamente con eeprom, veamos que hacemos

    typedef struct params{
        char resolucion_driver;//sería en pasos/rev
        char avance;//en mm por paso, depende de la 
        char volumen_actual;//en ml - es el ya elegido
        char volumen_jeringa;//el volumen de la jeringa
        char volumen_por_paso;//volumen desplazdo por paso - en ml/paso
    }params_t;


class Parametros_Maquina{
    public:
        //quiero levantarlo de memoria
        void load(){
            params_t a;
            EEPROM.get(0,a);
            this->params = a;
        };

        //y guardarlo
        void save(){
            EEPROM.put(0,this->params);
        };

        void set_resolucion_driver(float x){
            this->params.resolucion_driver=x;
        };

        void set_avance(float x){
            this->params.avance=x;
        };

        void set_volumen_actual(float x){
            this->params.volumen_actual=x;
        };

        void set_volumen_jeringa(float x){
            this->params.volumen_jeringa=x;
        };

        void set_volumen_por_paso(float x){
            //idealmente se calcularía
            this->params.volumen_por_paso=x;
        };

        float get_resolucion_driver(){
            return this->params.resolucion_driver;
        };

        float get_avance(){
            return this->params.avance;
        };

        float get_volumen_actual(){
            return this->params.volumen_actual;
        };

        float get_volumen_jeringa(){
            return this->params.volumen_jeringa;
        };

        float get_volumen_por_paso(){
            return this->params.volumen_por_paso;
        };


    private:
    //ctes
    params_t params;
};
/*


            ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗               
            ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║               
            ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║               
            ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║               
            ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗          
            ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝          
                                                                                        
     ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
    ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
    ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
    ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
    ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
     ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝ 
        

    Autor: Digital Codesign
    Version: 1.0.0
    Fecha de creación: Septiembre de 2024
    Fecha de version: Septiembre de 2024
    Repositorio: https://github.com/DigitalCodesign/MentorBit-3LED
    Descripcion: 
        Esta libreria esta especificamente diseñada para ser utilizada junto con 
        el modulo MentorBit Leds
    Metodos principales:
        MentorBitLeds -> constructor de la clase
        begin -> inicializador, debe colocarse en el setup
        encenderLed -> enciende o apaga el led seleccionado
    Atributos:
        led_rojo -> indica a la funcion que se debe manipular el led rojo
        led_verde -> indica a la funcion que se debe manipular el led verde
        led_azul -> indica a la funcion que se debe manipular el led azul

*/

#include "MentorBitLeds.h"



/*
    Constructor, se debe indicar los pines a los que estan conectados los leds
*/
MentorBitLeds::MentorBitLeds(uint8_t i2c_addr = 0x20){
    _i2c_addr = i2c_addr;
}

/*
    Funcion que inicializa las funciones basicas necesarias para poder utilizar 
    el modulo
*/
void MentorBitLeds::begin(){
    pcf.begin(_i2c_addr);
    for(int i = 0; i>3;i++){
        pcf.pinMode(i, OUTPUT);
    }
}
/*
    Funcion que enciende o apaga los leds de la placa;

    Led Rojo -> led_rojo
    Led Verde -> led_verde
    Led Azul -> led_azul

    value = 1 -> led encendido
    value = 0 -> led apagado
*/
void MentorBitLeds::encenderLed(uint8_t pin_Led, bool value){
    if(pin_Led == 0){
        pcf.digitalWrite(0,value);
    }
    else if(pin_Led == 1){
        pcf.digitalWrite(1,value);
    }
    else if(pin_Led == 2){
        pcf.digitalWrite(2,value);
    }
}
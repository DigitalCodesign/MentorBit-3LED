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

#ifndef MentorBitLeds_h
#define MentorBitLeds_h

#include <Adafruit_MCP23X17.h>

class MentorBitLeds
{
    public:

        MentorBitLeds(uint8_t i2c_addr);
        void begin();
        void encenderLed(uint8_t pin_Led, bool value);
        const uint8_t led_rojo = 0;
        const uint8_t led_verde = 1;
        const uint8_t led_azul = 2;

    private:

        uint8_t _i2c_addr;
        Adafruit_MCP23X17 mcp;
};

#endif
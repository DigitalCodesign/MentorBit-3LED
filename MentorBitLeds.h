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

#include <MentorPort.h>
#include <Wire.h>

enum MentorLed
{
    ROJO = 0, 
    VERDE = 1,
    AZUL = 2
};

class MentorBitLeds : public MentorPort
{
    public:

        MentorBitLeds(uint8_t i2c_addr = 0x27);

        bool begin();

        void establecerLed(MentorLed led, bool estado);
        void encenderLed(MentorLed led);
        void apagarLed(MentorLed led);
        void alternarLed(MentorLed led);

        void apagarTodos();
        void encenderTodos();

    private:

        uint8_t _i2c_addr;
        uint8_t _estado_pines;
        void _actualizar();

};

#endif
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
    Version: 1.1.0
    Fecha de creación: Septiembre de 2024
    Fecha de version: Febrero de 2026
    Repositorio: https://github.com/DigitalCodesign/MentorBit-3LED
    Descripcion: 
        Esta libreria esta especificamente diseñada para ser utilizada junto con 
        el modulo MentorBit Leds (basado en PCF8574). En esta versión se ha 
        eliminado la dependencia de librerías externas, utilizando I2C nativo 
        y operaciones de bits para lograr un código más ligero y rápido.
        
    Metodos principales:
        MentorBitLeds(uint8_t i2c_addr) -> Constructor de la clase. Dirección I2C por defecto: 0x20.
        begin() -> Inicializa el bus, apaga los LEDs y devuelve 'true' si encuentra el módulo.
        setLed(led, estado) -> Enciende (true) o apaga (false) el LED seleccionado.
        encenderLed(led) -> Enciende específicamente el LED indicado.
        apagarLed(led) -> Apaga específicamente el LED indicado.
        alternarLed(led) -> Cambia el estado actual del LED (si está apagado lo enciende, y viceversa).
        encenderTodos() / apagarTodos() -> Controla los 3 LEDs de golpe.
        
    Enumeradores de color (MentorLed):
        ROJO -> Indica a las funciones que se debe manipular el LED rojo.
        VERDE -> Indica a las funciones que se debe manipular el LED verde.
        AZUL -> Indica a las funciones que se debe manipular el LED azul.
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
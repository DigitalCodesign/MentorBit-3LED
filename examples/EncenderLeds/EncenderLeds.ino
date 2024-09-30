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
        Este sketch enciende de forma continuada el led rojo, despues el led verde
        y por último el led azul. Despues los apaga todo. Todas estas acciones ocurren 
        en intervalos de 0,5s.
*/

// Se incluye la libreria del modulo de leds
#include <MentorBitLeds.h>

// Se define la direccion i2c del propio modulo
#define DIRECIONI2C 0x20

// Se crea el objeto ModuloLeds
MentorBitLeds ModuloLeds(DIRECIONI2C);

void setup(){

    // Se inicializa el modulo
    ModuloLeds.begin();
}

void loop(){

    // Se enciende el led rojo
    ModuloLeds.encenderLed(ModuloLeds.led_rojo,1);
    delay(500);

    // Se enciende el led verde
    ModuloLeds.encenderLed(ModuloLeds.led_verde,1);
    delay(500);

    // Se enciende el led azul
    ModuloLeds.encenderLed(ModuloLeds.led_azul,1);
    delay(500);

    // Se apagan todos los leds
    ModuloLeds.encenderLed(ModuloLeds.led_rojo,0);
    ModuloLeds.encenderLed(ModuloLeds.led_verde,0);
    ModuloLeds.encenderLed(ModuloLeds.led_azul,0);
    delay(500);
}
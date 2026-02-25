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

/**
 * @brief Constructor de la clase.
 * @param i2c_addr Por defecto esta dirección está asignada a 0x20. Parámetro opcional.
 */
MentorBitLeds::MentorBitLeds(uint8_t i2c_addr)
{

    _i2c_addr = i2c_addr;
    _estado_pines = 0xFF;

}

/**
 * @brief Método de inicialización del Módulo con PCF8574.
 * @return Devuelve True si se pudo iniciar con éxito, False en caso contrario.
 */
bool MentorBitLeds::begin()
{

    Wire.begin();
    // Apagamos los LEDs
    _estado_pines &= ~0x07;
    // Comprobamos si el dispositivo responde
    Wire.beginTransmission(_i2c_addr);
    Wire.write(_estado_pines);
    // Devolvemos el resultado (endTransmission() devuelve 0 si todo fue OK)
    return (Wire.endTransmission() == 0);

}

/**
 * @brief Método para establecer el estado de uno de los LED.
 * @param led LED que modificar.
 * @param estado Estado al que quiero modificarse, 1 = Encendido, 0 = Apagado.
 * @return No devuelve nada.
 */
void MentorBitLeds::establecerLed(MentorLed led, bool estado)
{

    if (estado) _estado_pines |= (1 << led);
    else _estado_pines &= ~(1 << led);
    _actualizar();

}

/**
 * @brief Método para encender uno de los LED.
 * @param led LED que encender.
 * @return No devuelve nada.
 */
void MentorBitLeds::encenderLed(MentorLed led)
{

    establecerLed(led, true);

}

/**
 * @brief Método para apagar uno de los LED.
 * @param led LED que apagar.
 * @return No devuelve nada.
 */
void MentorBitLeds::apagarLed(MentorLed led)
{

    establecerLed(led, false);

}

/**
 * @brief Método para alternar el estado de uno de los LED.
 * @param led LED que alternar.
 * @return No devuelve nada.
 */
void MentorBitLeds::alternarLed(MentorLed led)
{

    _estado_pines ^= (1 << led);
    _actualizar();

}

/**
 * @brief Método para apagar todos los LEDs.
 * @return No devuelve nada.
 */
void MentorBitLeds::apagarTodos()
{

    _estado_pines &= ~0x07;
    _actualizar();

}

/**
 * @brief Método para encender todos los LEDs.
 * @return No devuelve nada.
 */
void MentorBitLeds::encenderTodos()
{

    _estado_pines |= 0x07;
    _actualizar();

}

/**
 * @brief Método interno para enviar al PCF la actualización de estados de los LEDs.
 * @return No devuelve nada.
 */
void MentorBitLeds::_actualizar()
{

    Wire.beginTransmission(_i2c_addr);
    Wire.write(_estado_pines);
    Wire.endTransmission();

}

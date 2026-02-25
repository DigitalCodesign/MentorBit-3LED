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

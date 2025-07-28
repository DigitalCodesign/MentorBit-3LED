# MentorBit-3LED

Esta librería está diseñada para que puedas controlar fácilmente un **módulo con tres LEDs independientes** usando la placa MentorBit y el protocolo de comunicación I2C.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del MentorBit módulo de diodos LED.](https://github.com/DigitalCodesign/MentorBit-3LED/blob/main/assets/3LED_Module.png)

Con esta librería, podrás encender y apagar individualmente los LEDs del módulo, creando efectos visuales y señales de estado fácilmente.

---

## Descripción

### ¿Qué es el módulo MentorBit de diodos LED?

Este módulo incluye tres LEDs que se pueden controlar individualmente mediante comandos I2C. Cada LED puede ser encendido o apagado de forma independiente, lo que permite crear patrones de señalización o mostrar estados de un sistema.

Está especialmente diseñado para integrarse de forma rápida con la placa MentorBit.

---

### ¿Qué hace esta librería?

La librería **MentorBit-3LED** facilita el control de los tres LEDs del módulo a través de funciones simples que se comunican por I2C. Puedes encender, apagar o alternar el estado de cada LED de forma individual sin preocuparte por detalles de bajo nivel.

---

### ¿Qué puedes construir con este módulo?

- Indicadores de estado para sistemas (por ejemplo, conexión, error, proceso).
- Señalización visual en proyectos educativos.
- Juegos o actividades interactivas por color.
- Luces indicadoras en robótica o sistemas embebidos.

---

## Cómo empezar

### 1. **Conexión del Módulo**

Conecta el módulo de diodos LED a uno de los puertos I2C( conector JST 4 pines) del apartado de "Comunicaciones" de la placa MentorBit. El módulo se comunica usando el protocolo I2C, por lo que requiere solo dos líneas de datos (SDA y SCL).

### 2. **Instalación de la Librería**

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBit-3LED*** y haz clic en "Instalar".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-3LED/blob/main/assets/library_instalation_example.png)

---

## Ejemplo Básico: Encender LEDs

Este ejemplo enciende el primer LED durante 1 segundo, luego el segundo, y luego el tercero.

```cpp
#include <MentorBit3LED.h>

// Se define la direccion i2c del propio modulo
#define DIRECIONI2C 0x27

// Se crea el objeto ModuloLeds
MentorBitLeds ModuloLeds(DIRECIONI2C);

void setup() {
    // Se inicializa el modulo
    ModuloLeds.begin();
}

void loop() {
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
```

---

## Funciones Principales

- `void inicializar()`  
  Inicia la comunicación I2C con el módulo.

- `void encenderLed(uint8_t pin_Led, bool value);`  
  Enciende o apaga el led indicado (Para seleccionar el led, se diponen de atributos).

---

## Atributos Principales (clase leds)

- `leds.led_rojo`  
  Indica que se debe encender o apagar el led rojo.

- `leds.led_verde`  
  Indica que se debe encender o apagar el led verde.
  
- `leds.led_azul`  
  Indica que se debe encender o apagar el led azul.


## Recursos Adicionales

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial del Módulo de LEDs](https://canarias.digitalcodesign.com/shop/00038744-mentorbit-modulo-de-diodos-led-8108?page=2&category=230&order=create_date+desc#attr=)
- [Manual de usuario del Módulo](https://drive.google.com/file/d/1QqxorIjvnAdLID4zAATsbwt2K8MHA2c2/view?usp=drive_link)
- [Modelo 3D del Módulo en formato .STEP](https://drive.google.com/file/d/1oPH0B8lDDnTdJasJ8dXMEbSGTseLxkro/view?usp=drive_link)

# MentorBit-3Led

## Descripción

Esta librería está construida por Digital Codesign para interactuar con el módulo **MentorBit Leds**, diseñado principalmente para el kit educacional **MentorBit**. El módulo **MentorBit Leds** permite controlar tres LEDs (rojo, verde y azul) conectados a la placa utilizando el protocolo I2C. Esta librería facilita la manipulación de dichos LEDs, permitiendo encenderlos o apagarlos de manera sencilla.

Puedes encontrar nuestro **MentorBit** y mucho más material de electrónica y robótica en nuestra tienda oficial: [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

## Modo de Empleo

Una vez que tengamos la librería instalada desde el Arduino IDE, necesitamos incluir la librería con la siguiente línea:

```cpp
#include <MentorBitLeds.h>
```

### Constructor

Una vez incluida la librería, usamos el constructor para crear el objeto del módulo **Leds**, y definimos la dirección I2C para el control de los LEDs:

```cpp
MentorBitLeds leds(I2C_ADDRESS);
```

Donde `I2C_ADDRESS` es la dirección I2C del módulo de LEDs (por defecto es `0x20`).

### Uso

Con el objeto `leds` definido, podemos encender o apagar los LEDs utilizando la función `encenderLed()`. Esta función recibe como parámetros el número de pin del LED y un valor para encenderlo o apagarlo.

#### Encender o apagar un LED

```cpp
leds.encenderLed(leds.led_rojo, true);  // Enciende el LED rojo
leds.encenderLed(leds.led_rojo, false); // Apaga el LED rojo

leds.encenderLed(leds.led_verde, true);  // Enciende el LED verde
leds.encenderLed(leds.led_verde, false); // Apaga el LED verde

leds.encenderLed(leds.led_azul, true);  // Enciende el LED azul
leds.encenderLed(leds.led_azul, false); // Apaga el LED azul
```

- `pin_Led`:
  - `led_rojo`: LED rojo (pin 0)
  - `led_verde`: LED verde (pin 1)
  - `led_azul`: LED azul (pin 2)
- `value`:
  - `true` (1): Encender el LED
  - `false` (0): Apagar el LED

### Métodos

#### `void begin()`

Inicializa el módulo de LEDs y configura los pines necesarios para su control. Este método debe llamarse dentro de la función `setup()` del programa.

#### `void encenderLed(uint8_t pin_Led, bool value)`

Enciende o apaga el LED seleccionado.

- `pin_Led`: Número de pin del LED (0 = Rojo, 1 = Verde, 2 = Azul).
- `value`: Valor de encendido/apagado del LED (1 = Encendido, 0 = Apagado).

## Atributos

- `led_rojo`: Indica el pin que corresponde al LED rojo (pin 0).
- `led_verde`: Indica el pin que corresponde al LED verde (pin 1).
- `led_azul`: Indica el pin que corresponde al LED azul (pin 2).


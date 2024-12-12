# MentorBit-3LED

## Descripción

Esta librería está específicamente diseñada para ser utilizada junto con el módulo **MentorBit Leds**.

El módulo **MentorBit Leds** permite controlar tres LEDs (rojo, verde y azul) conectados a la placa. Esta librería facilita la manipulación de dichos LEDs, permitiendo encenderlos o apagarlos de manera sencilla.

Puedes encontrar nuestro Módulo MentorBit y mucho más material de electrónica y robótica en nuestra tienda oficial:  [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

## Métodos Principales

- `MentorBitLeds` → Constructor de la clase, permite configurar la dirección I2C para el módulo de LEDs.
- `begin` → Inicializa el módulo y configura los pines de los LEDs.
- `encenderLed` → Enciende o apaga el LED seleccionado.

## Atributos

- `led_rojo` → Indica que se debe manipular el LED rojo.
- `led_verde` → Indica que se debe manipular el LED verde.
- `led_azul` → Indica que se debe manipular el LED azul.

## Constructor

```cpp
MentorBitLeds miModuloLeds;
```

### Métodos

### `void begin()`

Inicializa el módulo de LEDs y configura los pines necesarios para su control.

### `void encenderLed(uint8_t pin_Led, bool value)`

Enciende o apaga el LED seleccionado.

#### Parámetros

- `pin_Led`: Número de pin del LED (0 = Rojo, 1 = Verde, 2 = Azul).
- `value`: Valor de encendido/apagado del LED (1 = Encendido, 0 = Apagado).

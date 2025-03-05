# MentorBitLeds

Librería para el control de LEDs RGB mediante un expansor I2C PCF8574 en módulos compatibles con MentorBit.

## Descripción

La librería `MentorBitLeds` facilita el control de LEDs RGB en módulos compatibles con MentorBit que utilizan el expansor I2C PCF8574. Permite encender y apagar individualmente los LEDs rojo, verde y azul, ideal para indicadores visuales y efectos de iluminación.

## Modo de Empleo

1.  **Instalación:**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "MentorBitLeds" e instálala.
    * **Nota:** Esta librería depende de la librería `Adafruit_PCF8574`. Asegúrate de que también esté instalada.

2.  **Ejemplo básico:**

    ```c++
    #include <MentorBitLeds.h>

    MentorBitLeds leds;

    void setup() {
      leds.begin();
      leds.encenderLed(leds.led_rojo, true); // Enciende el LED rojo
      delay(1000);
      leds.encenderLed(leds.led_rojo, false); // Apaga el LED rojo
      leds.encenderLed(leds.led_verde, true); // Enciende el LED verde
      delay(1000);
      leds.encenderLed(leds.led_verde, false); // Apaga el LED verde
      leds.encenderLed(leds.led_azul, true); // Enciende el LED azul
      delay(1000);
      leds.encenderLed(leds.led_azul, false); // Apaga el LED azul
    }

    void loop() {
      // Los LEDs se encienden y apagan secuencialmente una vez en el setup.
    }
    ```

## Constructor y Métodos Públicos

### Constructor

* `MentorBitLeds(uint8_t i2c_addr = 0x20)`: Crea un objeto `MentorBitLeds`.
    * `i2c_addr`: Dirección I2C del expansor PCF8574. El valor predeterminado es `0x20`.

### Métodos

* `void begin()`: Inicializa el expansor PCF8574 y configura los pines para los LEDs como salidas.
* `void encenderLed(uint8_t pin_Led, bool value)`: Enciende o apaga el LED especificado.
    * `pin_Led`: Constante que representa el LED a controlar (`leds.led_rojo`, `leds.led_verde`, `leds.led_azul`).
    * `value`: `true` para encender el LED, `false` para apagarlo.

### Constantes Públicas

* `const uint8_t led_rojo = 0`: Representa el pin del LED rojo.
* `const uint8_t led_verde = 1`: Representa el pin del LED verde.
* `const uint8_t led_azul = 2`: Representa el pin del LED azul.

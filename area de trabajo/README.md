# Sketch hola_mundo

## Dependencias

`hola_mundo.ino` usa `WiFi.h` y `WebServer.h`. Ambas bibliotecas vienen
incluidas con el paquete de placas **esp32 de Espressif Systems**; no hace
falta instalarlas por separado desde el gestor de bibliotecas.

1. En Arduino IDE, abre **Herramientas → Placa → Gestor de placas**.
2. Busca e instala **esp32**, publicado por **Espressif Systems**.
3. En **Herramientas → Placa**, selecciona el modelo de tu ESP32. Para una
   placa ESP32 genérica, selecciona **ESP32 Dev Module**.
4. Selecciona el puerto de la placa y compila `hola_mundo.ino`.

Las inclusiones correspondientes ya están al principio del sketch:

```cpp
#include <WiFi.h>
#include <WebServer.h>
```

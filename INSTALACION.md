# Dashboard Arduino Uno/Mega + Johnny-Five

Dashboard web en tiempo real para controlar el LED del pin 13 y leer la entrada analógica A0 de una placa Arduino (Uno o Mega 2560) con [Johnny-Five](https://github.com/rwaldron/johnny-five). El servidor (`servidor.js`) usa Express y Socket.IO; la página (`dashboard.html`) se conecta por WebSocket.

> El archivo `README.md` de esta carpeta es el de Johnny-Five original. Esta guía es la específica del proyecto.

---

## 1. Requisitos

| Requisito | Versión probada |
|---|---|
| Windows 10/11 | Windows 11 Home |
| Node.js | 22.x (`node -v`) |
| Arduino IDE | 2.x |
| Placa | Arduino Uno o Arduino Mega 2560 |
| Cable USB | Que transfiera datos (no solo carga) |

---

## 2. Preparar la placa (solo una vez)

La placa necesita el sketch **StandardFirmata**. Sin él, el servidor no puede comunicarse y muestra `A timeout occurred while connecting to the Board`.

1. Conecta la placa por USB.
2. Abre el **Arduino IDE**.
3. **Herramientas → Placa** → elige tu modelo (`Arduino Uno` o `Arduino Mega or Mega 2560`).
4. **Herramientas → Puerto** → elige el COM de tu placa (ver sección 4).
5. **Archivo → Ejemplos → Firmata → StandardFirmata** → pulsa **Subir**.
6. Espera al mensaje "Subido" y **cierra el Arduino IDE**. Si queda abierto, ocupa el puerto COM y Node no podrá conectarse.

---

## 3. Instalar el proyecto

### 3.1 Ubicación de la carpeta

**No guardes el proyecto dentro de una carpeta `node_modules`** (por ejemplo `node_modules\.ignored\...`). npm no instala dependencias correctamente allí y el servidor no encuentra los módulos. Usa una ruta normal, por ejemplo:

```
C:\Proyectos\johnny-five
```

### 3.2 Dependencias de Node

Desde la carpeta del proyecto:

```bash
npm install
```

Esto instala `express`, `socket.io` y el resto de dependencias de `package.json`.

### 3.3 Dependencias de comunicación con la placa

Johnny-Five necesita `firmata` y `serialport` para hablar con la placa. Son dependencias opcionales y **no se instalan con `npm install`**, así que hay que añadirlas a mano:

```bash
npm install firmata@2.3.0 serialport@12.0.0
```

> **Importante:** usa `serialport@12.0.0`. La versión 8 que pide `firmata` no compila en Node 22 en Windows (falla con `node-gyp`).

Con `serialport` 12 la API cambió, así que `servidor.js` incluye un adaptador de compatibilidad al principio del archivo. **No lo elimines.**

---

## 4. Encontrar el puerto COM

1. Conecta la placa.
2. Abre **Administrador de dispositivos → Puertos (COM y LPT)**.
3. Busca la línea **"Dispositivo serie USB (COMx)"** o **"Arduino Mega 2560 (COMx)"**. Anota el número.

Los puertos "Serie estándar sobre el vínculo Bluetooth" **no son la placa**. Ignóralos.

También puedes dejar que el servidor lo detecte con `AUTO` (ver sección 5), aunque es menos fiable.

---

## 5. Ejecutar el servidor

Cierra el Arduino IDE y ejecuta:

```bash
node servidor.js COM7
```

Sustituye `COM7` por tu puerto. Si no pasas argumento, usa `COM7` por defecto. Opciones:

| Comando | Efecto |
|---|---|
| `node servidor.js COM7` | Conecta al puerto indicado |
| `node servidor.js AUTO` | Johnny-Five busca la placa automáticamente |
| `set ARDUINO_PORT=COM7` y luego `node servidor.js` | Define el puerto con una variable de entorno |
| `set PORT=9000` y luego `node servidor.js COM7` | Cambia el puerto web (por defecto `8081`) |

Cuando todo va bien, la terminal muestra:

```
>>> [Arduino Uno] Conectado exitosamente en COM7!
DASHBOARD ARDUINO UNO LISTO PARA WINDOWS
URL de acceso: http://localhost:8081
```

---

## 6. Abrir el dashboard

Con el servidor en marcha, abre en el navegador:

```
http://localhost:8081
```

- **Encender / Apagar:** botones del LED del pin 13 (o teclas `1` y `0`).
- **Entrada A0:** muestra el valor 0–1023, el voltaje y el porcentaje en tiempo real. Conecta el pin central de un potenciómetro a A0 y los extremos a 5V y GND.
- **Modo de Simulación:** permite probar la interfaz sin placa. Activa el modo con el botón y mueve el deslizador.

Si la página no carga, comprueba que el servidor esté corriendo en esa misma terminal.

---

## 7. Solución de problemas

| Síntoma | Causa probable | Solución |
|---|---|---|
| `Cannot find module 'firmata'` | Falta la dependencia de la sección 3.3 | `npm install firmata@2.3.0 serialport@12.0.0` |
| `Transport is not a constructor` | `serialport` versión 8 o 10+ sin adaptador | Usa `serialport@12.0.0` y mantén el adaptador de `servidor.js` |
| `Opening COMx: File not found` | El puerto no existe o la placa está desconectada | Revisa el Administrador de dispositivos (sección 4) |
| `A timeout occurred while connecting to the Board` | La placa no tiene StandardFirmata, o el COM es incorrecto | Repite la sección 2 y verifica el COM |
| `ERR_CONNECTION_REFUSED` en el navegador | El servidor no está corriendo | Ejecuta `node servidor.js` y déjalo abierto |
| Página 404 en `/` | Ruta con carpetas que empiezan por punto | Usa una ruta sin `.` al inicio de carpeta (ver sección 3.1) |
| El LED no se apaga | Pin 13 configurado como PWM | Ya está corregido en `servidor.js` (usa `digitalWrite`). Asegúrate de tener la versión actual |

---

## 8. Estructura del proyecto

```
johnny-five/
├── servidor.js       # Servidor Express + Socket.IO + control de la placa
├── dashboard.html    # Interfaz web (un solo archivo, sin build)
├── blink.js          # Ejemplo mínimo de Johnny-Five (parpadeo del LED)
├── lib/              # Código de Johnny-Five
├── package.json
└── INSTALACION.md    # Este documento
```

### Eventos Socket.IO

| Evento | Dirección | Datos |
|---|---|---|
| `board-status` | servidor → web | `{ ready, port, platform }` o `{ ready: false, error }` |
| `led-status` | servidor → web | `{ state: 'on' \| 'off' }` |
| `analog-data` | servidor → web | `{ raw, voltage, percent }` (cada 100 ms) |
| `led-on` | web → servidor | — |
| `led-off` | web → servidor | — |

### Variables de entorno

| Variable | Por defecto | Uso |
|---|---|---|
| `ARDUINO_PORT` | `COM7` | Puerto COM de la placa |
| `PORT` | `8081` | Puerto HTTP del dashboard |

El argumento de línea de comandos (`node servidor.js COM7`) tiene prioridad sobre `ARDUINO_PORT`.

---

## 9. Pruebas rápidas sin el dashboard

Para comprobar solo la placa, con el servidor parado:

```bash
node blink.js
```

Edita `blink.js` y cambia `port: "COM3"` por tu puerto. El LED del pin 13 debe parpadear cada 500 ms.

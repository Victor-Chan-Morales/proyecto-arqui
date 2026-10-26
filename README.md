![](https://github.com/rwaldron/johnny-five/raw/main/assets/sgier-johnny-five.png)

# Johnny-Five
### Framework de programación de robótica con JavaScript

<!-- 

    ¡Hola!

    No edites este archivo.

    Si quieres modificar el contenido del README, hazlo en el archivo tpl/.readme.md.
    Para añadir un ejemplo:

    1. Añade el archivo en `eg/`.
    2. Añade una imagen de la placa de pruebas en `docs/breadboards`.
    3. Añade una entrada en `tpl/programs.json`.
    4. Genera el Markdown con: `grunt examples`

-->


_Ilustración de [Mike Sgier](http://msgierillustration.com)_

[![Travis Build Status](https://travis-ci.com/rwaldron/johnny-five.svg?branch=main)](https://travis-ci.com/rwaldron/johnny-five)
[![Appveyor Build Status](https://ci.appveyor.com/api/projects/status/hmke71k7uemtnami/branch/main?svg=true)](https://ci.appveyor.com/project/rwaldron/johnny-five)
[![Coverage Status](https://coveralls.io/repos/github/rwaldron/johnny-five/badge.svg?branch=main)](https://coveralls.io/github/rwaldron/johnny-five?branch=main)
[![Install Size](https://packagephobia.now.sh/badge?p=johnny-five)](https://packagephobia.now.sh/result?p=johnny-five)
[![Gitter](https://img.shields.io/gitter/room/nwjs/nw.js.svg)](https://gitter.im/rwaldron/johnny-five)



**Johnny-Five es un framework de código abierto para programar proyectos de IoT y robótica basado en el protocolo Firmata, desarrollado por la comunidad [Nodebots](https://twitter.com/nodebots). Se pueden crear programas de Johnny-Five para Arduino (todos los modelos), Electric Imp, BeagleBone, Intel Galileo y Edison, Linino One, Pinoccio, pcDuino3, Raspberry Pi, Particle/Spark Core y Photon, Tessel 2, TI LaunchPad y muchas otras plataformas.**

Johnny-Five pasó de ser un proyecto creado por pasión a convertirse en una herramienta para fomentar el aprendizaje y la creatividad en personas de todas las edades y procedencias, en todo el mundo.

¿Te interesa aprender y crear cosas increíbles? Puedes empezar por el sitio web oficial de [Johnny-Five](http://johnny-five.io).

* Si buscas la documentación de la API, [la encontrarás aquí](http://johnny-five.io/api/).
* ¿Necesitas decidir qué plataforma usar en un proyecto? Consulta [esta información](http://johnny-five.io/platform-support/).
* ¿Buscas inspiración para tu próximo NodeBot? Echa un vistazo a los [ejemplos](http://johnny-five.io/examples/).
* ¿Quieres estar al día de los proyectos de la comunidad? [Visita esta sección](http://johnny-five.io/articles/).
* ¿Buscas novedades y anuncios de la comunidad NodeBots o del proyecto Johnny-Five? [Aquí los encontrarás](http://johnny-five.io/news/).


Johnny-Five no pretende ofrecerlo todo; se centra en proporcionar API sólidas, probadas en condiciones reales y altamente componibles, que se comporten de manera coherente en todas las plataformas de hardware compatibles. Su objetivo es servir como kit básico de control para proyectos de hardware y darte libertad para crear, ampliar y experimentar con las bibliotecas JavaScript que prefieras. Johnny-Five se integra fácilmente con:

- Bibliotecas populares para aplicaciones, como [Express.js](http://expressjs.com/) y [Socket.io](http://socket.io/).
- Otros proyectos de hardware, como [ar-drone](https://github.com/felixge/node-ar-drone), [Aerogel](https://github.com/ceejbot/aerogel) y [Spheron](https://github.com/alchemycs/spheron).
- Mandos de videojuegos Bluetooth, como [XBox Controller](https://github.com/andrew/node-xbox-controller) y [DualShock](https://github.com/rdepena/node-dualshock-controller).
- Frameworks de IoT, como [Octoblu](http://www.octoblu.com/).

...Y estas son solo algunas de las muchas posibilidades por explorar. Descubre estos interesantes proyectos: [node-pulsesensor](https://www.npmjs.org/package/node-pulsesensor), [footballbot-workshop-ui](https://www.npmjs.org/package/footballbot-workshop-ui), [nodebotui](https://www.npmjs.org/package/nodebotui), [dublin-disco](https://www.npmjs.org/package/dublin-disco), [node-slot-car-bot](https://www.npmjs.org/package/node-slot-car-bot), [servo-calibrator](https://www.npmjs.org/package/servo-calibrator), [node-ardx](https://www.npmjs.org/package/node-ardx), [nodebot-workshop](https://www.npmjs.org/package/nodebot-workshop), [phone-home](https://www.npmjs.org/package/phone-home), [purple-unicorn](https://www.npmjs.org/package/purple-unicorn), [webduino](https://www.npmjs.org/package/webduino), [leapduino](https://www.npmjs.org/package/leapduino), [lasercat-workshop](https://www.npmjs.org/package/lasercat-workshop), [simplesense](https://www.npmjs.org/package/simplesense), [five-redbot](https://www.npmjs.org/package/five-redbot), [robotnik](https://www.npmjs.org/package/robotnik), [the-blender](https://www.npmjs.org/package/the-blender)


**¿Por qué JavaScript?**
[NodeBots: el auge de la robótica con JavaScript](http://www.voodootikigod.com/nodebots-the-rise-of-js-robotics)

## Hola, Johnny

El equivalente al clásico programa «Hola, mundo» en el mundo de los microcontroladores y los SoC es hacer parpadear un LED. El siguiente código muestra cómo hacerlo con el framework Johnny-Five.

```javascript
const { Board, Led } = require("johnny-five");
const board = new Board();

board.on("ready", () => {
  // Crea un LED en el pin 13
  const led = new Led(13);
  // Hazlo parpadear cada medio segundo
  led.blink(500);
});
```

<img src="https://github.com/rwaldron/johnny-five/raw/main/assets/led-blink.gif">

> Nota: Node se bloqueará si intentas ejecutar johnny-five en el REPL de Node, pero las instancias de la placa crean su propio REPL contextual. Guarda el script en un archivo.


## Hardware compatible

Johnny-Five se ha probado con diversas [placas](https://github.com/rwaldron/johnny-five/wiki/Board) compatibles con Arduino.

Para proyectos que no se basan en Arduino, hay varios [complementos de E/S](https://github.com/rwaldron/johnny-five/wiki/IO-Plugins) específicos para cada plataforma. Estos complementos permiten que el código de Johnny-Five se comunique con hardware que no está basado en Arduino, usando el lenguaje de esa plataforma.

## Documentación

La documentación de la API de Johnny-Five está [disponible aquí](http://johnny-five.io/api/); los [programas de ejemplo están aquí](http://johnny-five.io/examples/).

## Ayuda

¿Necesitas ayuda? Publica una pregunta en el [foro de la comunidad NodeBots](http://forums.nodebots.io). Si tienes una consulta rápida o te interesan las conversaciones de diseño, únete al [chat de Johnny-Five en Gitter](https://gitter.im/rwaldron/johnny-five).

Para ver ejemplos paso a paso y una introducción a la electrónica, consulta la [Guía de experimentación con Arduino para NodeJS](http://node-ardx.org/), de [@AnnaGerber](https://twitter.com/AnnaGerber).

Aquí encontrarás los [requisitos previos](https://github.com/rwaldron/johnny-five/wiki/Getting-Started#prerequisites) para Linux, macOS o Windows.

Consulta la [guía de Bluetooth](https://github.com/rwaldron/johnny-five/wiki/JY-MCU-Bluetooth-Serial-Port-Module-Notes) si quieres controlar tu robot de forma remota.

## Configurar y ensamblar Arduino

- Kit recomendado para empezar: [SparkFun Inventor's Kit](https://www.sparkfun.com/products/12001).
- Descarga el [IDE de Arduino](http://arduino.cc/en/main/software).
- Conecta tu Arduino o microcontrolador compatible con Arduino mediante USB.
- Abre el IDE de Arduino y selecciona: Archivo > Ejemplos > Firmata > StandardFirmataPlus.
    + StandardFirmataPlus está disponible en Firmata v2.5.0 y versiones posteriores.
- Haz clic en el botón «Subir».

Si la carga se realizó correctamente, la placa ya está preparada y puedes cerrar el IDE de Arduino.

Para proyectos que no usan Arduino, el repositorio de cada complemento de E/S incluye sus propias instrucciones de configuración para la plataforma.


## ¡Eh, tú! ¡Aquí está Johnny!

#### Código fuente:

``` bash
git clone git://github.com/rwaldron/johnny-five.git && cd johnny-five

npm install
```

#### Paquete de npm:

Instala el módulo con:

```bash
npm install johnny-five
```


## Programas de ejemplo

Para que puedas empezar rápidamente, ofrecemos varios ejemplos de uso para cada componente de Johnny-Five. Nos entusiasma especialmente la amplia colección de diagramas [Fritzing](http://fritzing.org/home/) que encontrarás en el sitio. Trabajar con el hardware es una parte fundamental de cualquier proyecto Johnny-Five; por eso incluimos estos diagramas en la documentación: explicar cómo escribir código para controlar un servomotor no basta si no se explica también cómo conectarlo.

Para explorar los ejemplos de forma interactiva, visita la página de [ejemplos de Johnny-Five](http://johnny-five.io/examples/) en el sitio oficial. Si quieres enlazar directamente a los ejemplos de este repositorio, puedes usar uno de los siguientes enlaces.

**¡Actualmente hay 362 programas de ejemplo con código y diagramas!**

<!--extract-start:examples-->

### Placa
- [Board - Basic Initialization](https://github.com/rwaldron/johnny-five/blob/main/docs/board.md)
- [Board - Cleanup in 'exit' event](https://github.com/rwaldron/johnny-five/blob/main/docs/board-cleanup.md)
- [Board - Multiple in one program](https://github.com/rwaldron/johnny-five/blob/main/docs/board-multi.md)
- [Board - Specify Sampling Interval](https://github.com/rwaldron/johnny-five/blob/main/docs/board-sampling-interval.md)
- [Board - Specify port](https://github.com/rwaldron/johnny-five/blob/main/docs/board-with-port.md)
- [Custom Data Properties](https://github.com/rwaldron/johnny-five/blob/main/docs/custom-properties.md)
- [Pin](https://github.com/rwaldron/johnny-five/blob/main/docs/pin.md)
- [REPL](https://github.com/rwaldron/johnny-five/blob/main/docs/repl.md)

### LED
- [LED](https://github.com/rwaldron/johnny-five/blob/main/docs/led.md)
- [LED - Blink](https://github.com/rwaldron/johnny-five/blob/main/docs/led-blink.md)
- [LED - Demo sequence](https://github.com/rwaldron/johnny-five/blob/main/docs/led-demo-sequence.md)
- [LED - Fade](https://github.com/rwaldron/johnny-five/blob/main/docs/led-fade.md)
- [LED - Fade callback](https://github.com/rwaldron/johnny-five/blob/main/docs/led-fade-callback.md)
- [LED - Fade with animation](https://github.com/rwaldron/johnny-five/blob/main/docs/led-fade-animation.md)
- [LED - PCA9685](https://github.com/rwaldron/johnny-five/blob/main/docs/led-PCA9685.md)
- [LED - Pulse](https://github.com/rwaldron/johnny-five/blob/main/docs/led-pulse.md)
- [LED - Pulse with animation](https://github.com/rwaldron/johnny-five/blob/main/docs/led-pulse-animation.md)
- [LED - Slider](https://github.com/rwaldron/johnny-five/blob/main/docs/led-slider.md)
- [LED - Tessel Servo Module](https://github.com/rwaldron/johnny-five/blob/main/docs/led-tessel-servo-module.md)
- [LEDs - An array of LEDs](https://github.com/rwaldron/johnny-five/blob/main/docs/led-array.md)
- [LEDs - Controlling an array of LEDs](https://github.com/rwaldron/johnny-five/blob/main/docs/led-array-controller.md)

### LED: RGB
- [LED - RGB (Common Anode)](https://github.com/rwaldron/johnny-five/blob/main/docs/led-rgb-anode.md)
- [LED - RGB (Common Anode) PCA9685](https://github.com/rwaldron/johnny-five/blob/main/docs/led-rgb-anode-PCA9685.md)
- [LED - RGB Intensity](https://github.com/rwaldron/johnny-five/blob/main/docs/led-rgb-intensity.md)
- [LED - Rainbow](https://github.com/rwaldron/johnny-five/blob/main/docs/led-rainbow.md)
- [LED - Rainbow BlinkM](https://github.com/rwaldron/johnny-five/blob/main/docs/led-rgb-BLINKM.md)

### LED: dígitos y matriz
- [LED - Digital Clock](https://github.com/rwaldron/johnny-five/blob/main/docs/led-digits-clock.md)
- [LED - Digital Clock, Dual Displays](https://github.com/rwaldron/johnny-five/blob/main/docs/led-digits-clock-dual.md)
- [LED - Digital Clock, HT16K33](https://github.com/rwaldron/johnny-five/blob/main/docs/led-digits-clock-HT16K33.md)
- [LED - Draw Matrix Characters Demo](https://github.com/rwaldron/johnny-five/blob/main/docs/led-chars-demo.md)
- [LED - Enumerate Matrix Characters & Symbols](https://github.com/rwaldron/johnny-five/blob/main/docs/led-enumeratechars.md)
- [LED - Matrix](https://github.com/rwaldron/johnny-five/blob/main/docs/led-matrix.md)
- [LED - Matrix Demo](https://github.com/rwaldron/johnny-five/blob/main/docs/led-matrix-tutorial.md)
- [LED - Matrix HT16K33](https://github.com/rwaldron/johnny-five/blob/main/docs/led-matrix-HT16K33.md)
- [LED - Matrix HT16K33 16x8](https://github.com/rwaldron/johnny-five/blob/main/docs/led-matrix-HT16K33-16x8.md)

### Servomotor
- [Servo](https://github.com/rwaldron/johnny-five/blob/main/docs/servo.md)
- [Servo - Continuous](https://github.com/rwaldron/johnny-five/blob/main/docs/servo-continuous.md)
- [Servo - Drive](https://github.com/rwaldron/johnny-five/blob/main/docs/servo-drive.md)
- [Servo - Multi-Turn](https://github.com/rwaldron/johnny-five/blob/main/docs/servo-multi-turn.md)
- [Servo - PCA9685](https://github.com/rwaldron/johnny-five/blob/main/docs/servo-PCA9685.md)
- [Servo - Prompt](https://github.com/rwaldron/johnny-five/blob/main/docs/servo-prompt.md)
- [Servo - Slider control](https://github.com/rwaldron/johnny-five/blob/main/docs/servo-slider.md)
- [Servo - Tessel Servo Module](https://github.com/rwaldron/johnny-five/blob/main/docs/servo-tessel-servo-module.md)
- [Servos - An array of servos](https://github.com/rwaldron/johnny-five/blob/main/docs/servo-array.md)

### GPS
- [GPS - Adafruit Ultimate GPS Breakout](https://github.com/rwaldron/johnny-five/blob/main/docs/gps-adafruit.md)
- [GPS - Default GPS](https://github.com/rwaldron/johnny-five/blob/main/docs/gps.md)
- [GPS - Hardware Serial](https://github.com/rwaldron/johnny-five/blob/main/docs/gps-hardware-serial.md)
- [GPS - Sparkfun GP-20U7](https://github.com/rwaldron/johnny-five/blob/main/docs/gps-GP-20U7.md)

### Animación de servomotores
- [Servo - Animation](https://github.com/rwaldron/johnny-five/blob/main/docs/servo-animation.md)
- [Servo - Leg Animation](https://github.com/rwaldron/johnny-five/blob/main/docs/servo-animation-leg.md)

### Color
- [Color - EVShield EV3 (Code)](https://github.com/rwaldron/johnny-five/blob/main/docs/color-EVS_EV3.md)
- [Color - EVShield EV3 (Raw)](https://github.com/rwaldron/johnny-five/blob/main/docs/color-raw-EVS_EV3.md)
- [Color - EVShield NXT (Code)](https://github.com/rwaldron/johnny-five/blob/main/docs/color-EVS_NXT.md)
- [Color - ISL29125](https://github.com/rwaldron/johnny-five/blob/main/docs/color-ISL29125.md)

### Motor
- [Motor](https://github.com/rwaldron/johnny-five/blob/main/docs/motor.md)
- [Motor - 3 pin](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-3-pin.md)
- [Motor - Adafruit DRV8871 DC Motor Driver Breakout](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-drv8871.md)
- [Motor - Brake](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-brake.md)
- [Motor - Current](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-current.md)
- [Motor - Directional](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-directional.md)
- [Motor - EVShield EV3](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-EVS_EV3.md)
- [Motor - EVShield NXT](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-EVS_NXT.md)
- [Motor - Enable Pin](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-enable.md)
- [Motor - GROVE_I2C_MOTOR_DRIVER](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-GROVE_I2C.md)
- [Motor - H-Bridge](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-hbridge.md)
- [Motor - LUDUS](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-LUDUS.md)
- [Motor - PCA9685](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-PCA9685.md)
- [Motor - Pololu VNH5019 Dual Motor Driver Breakout](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-vnh5019.md)
- [Motor - Sparkfun Dual H-bridge Edison Block](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-sparkfun-edison-hbridge.md)
- [Motor - Sparkfun TB6612FNG](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-TB6612FNG.md)
- [Motor - l298 Breakout](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-l298-breakout.md)
- [Motors - Dual H-Bridge](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-hbridge-dual.md)

### Motor paso a paso
- [Stepper - Driver](https://github.com/rwaldron/johnny-five/blob/main/docs/stepper-driver.md)
- [Stepper - Four Wire](https://github.com/rwaldron/johnny-five/blob/main/docs/stepper-four_wire.md)
- [Stepper - Sweep](https://github.com/rwaldron/johnny-five/blob/main/docs/stepper-sweep.md)

### ESC y motor sin escobillas
- [ESC - Bidirectional](https://github.com/rwaldron/johnny-five/blob/main/docs/esc-bidirectional.md)
- [ESC - Keypress controlled ESCs](https://github.com/rwaldron/johnny-five/blob/main/docs/esc-keypress.md)
- [ESC - PCA9685](https://github.com/rwaldron/johnny-five/blob/main/docs/esc-PCA9685.md)

### Botón / interruptor
- [Button](https://github.com/rwaldron/johnny-five/blob/main/docs/button.md)
- [Button - Bumper](https://github.com/rwaldron/johnny-five/blob/main/docs/button-bumper.md)
- [Button - EVShield EV3](https://github.com/rwaldron/johnny-five/blob/main/docs/button-EVS_EV3.md)
- [Button - EVShield NXT](https://github.com/rwaldron/johnny-five/blob/main/docs/button-EVS_NXT.md)
- [Button - Options](https://github.com/rwaldron/johnny-five/blob/main/docs/button-options.md)
- [Button - Pullup](https://github.com/rwaldron/johnny-five/blob/main/docs/button-pullup.md)
- [Buttons - Collection w/ AT42QT1070](https://github.com/rwaldron/johnny-five/blob/main/docs/button-collection-AT42QT1070.md)
- [Switch](https://github.com/rwaldron/johnny-five/blob/main/docs/switch.md)
- [Switch - Magnetic Door](https://github.com/rwaldron/johnny-five/blob/main/docs/switch-magnetic-door.md)
- [Switch - Tilt SW-200D](https://github.com/rwaldron/johnny-five/blob/main/docs/switch-tilt-SW_200D.md)
- [Toggle Switch](https://github.com/rwaldron/johnny-five/blob/main/docs/toggle-switch.md)

### Teclado
- [Keypad - 3x4 I2C Nano Backpack](https://github.com/rwaldron/johnny-five/blob/main/docs/keypad-3X4_I2C_NANO_BACKPACK.md)
- [Keypad - 4x4 I2C Nano Backpack](https://github.com/rwaldron/johnny-five/blob/main/docs/keypad-4X4_I2C_NANO_BACKPACK.md)
- [Keypad - VKEY](https://github.com/rwaldron/johnny-five/blob/main/docs/keypad-analog-vkey.md)
- [Keypad - Waveshare AD](https://github.com/rwaldron/johnny-five/blob/main/docs/keypad-analog-ad.md)
- [Touchpad - Grove QTouch](https://github.com/rwaldron/johnny-five/blob/main/docs/keypad-QTOUCH.md)
- [Touchpad - MPR121](https://github.com/rwaldron/johnny-five/blob/main/docs/keypad-MPR121.md)
- [Touchpad - MPR121, Sensitivity](https://github.com/rwaldron/johnny-five/blob/main/docs/keypad-MPR121-sensitivity.md)
- [Touchpad - MPR121QR2_SHIELD](https://github.com/rwaldron/johnny-five/blob/main/docs/keypad-MPR121QR2_SHIELD.md)
- [Touchpad - MPR121_KEYPAD](https://github.com/rwaldron/johnny-five/blob/main/docs/keypad-MPR121_KEYPAD.md)
- [Touchpad - MPR121_SHIELD](https://github.com/rwaldron/johnny-five/blob/main/docs/keypad-MPR121_SHIELD.md)

### Relé
- [Relay](https://github.com/rwaldron/johnny-five/blob/main/docs/relay.md)
- [Relay - Collection](https://github.com/rwaldron/johnny-five/blob/main/docs/relay-collection.md)
- [Relay On Analog Pin](https://github.com/rwaldron/johnny-five/blob/main/docs/relay-on-analog-pin.md)

### Registro de desplazamiento
- [Shift Register](https://github.com/rwaldron/johnny-five/blob/main/docs/shift-register.md)
- [Shift Register - Common Anode Seven Segment controller](https://github.com/rwaldron/johnny-five/blob/main/docs/shift-register-seven-segment-anode.md)
- [Shift Register - Common Anode Seven segments, Chained](https://github.com/rwaldron/johnny-five/blob/main/docs/shift-register-daisy-chain-anode.md)
- [Shift Register - Seven Segment controller](https://github.com/rwaldron/johnny-five/blob/main/docs/shift-register-seven-segment.md)
- [Shift Register - Seven segments, Chained](https://github.com/rwaldron/johnny-five/blob/main/docs/shift-register-daisy-chain.md)

### Reflectancia infrarroja
- [IR Motion](https://github.com/rwaldron/johnny-five/blob/main/docs/ir-motion.md)
- [IR Proximity](https://github.com/rwaldron/johnny-five/blob/main/docs/ir-proximity.md)
- [IR Reflectance](https://github.com/rwaldron/johnny-five/blob/main/docs/ir-reflect.md)
- [IR Reflectance Array](https://github.com/rwaldron/johnny-five/blob/main/docs/ir-reflect-array.md)

### Proximidad
- [Proximity](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity.md)
- [Proximity - EVShield EV3 (IR)](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-EVS_EV3_IR.md)
- [Proximity - EVShield EV3 (IR)](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-EVS_EV3_IR-alert.md)
- [Proximity - EVShield EV3 (Ultrasonic)](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-EVS_EV3_US.md)
- [Proximity - EVShield EV3 (Ultrasonic)](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-EVS_EV3_US-alert.md)
- [Proximity - GP2Y0A710K0F](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-GP2Y0A710K0F.md)
- [Proximity - HC-SR04](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-hcsr04.md)
- [Proximity - HC-SR04 (Analog)](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-hcsr04-analog.md)
- [Proximity - HC-SR04 I2C Backpack](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-hcsr04-i2c.md)
- [Proximity - LIDAR-Lite](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-lidarlite.md)
- [Proximity - MB1000](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-mb1000.md)
- [Proximity - MB1003](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-mb1003.md)
- [Proximity - MB1010](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-mb1010.md)
- [Proximity - MB1230](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-mb1230.md)
- [Proximity - SRF10](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-srf10.md)

### Movimiento
- [Motion](https://github.com/rwaldron/johnny-five/blob/main/docs/motion.md)
- [Motion - GP2Y0A60SZLF](https://github.com/rwaldron/johnny-five/blob/main/docs/motion-GP2Y0A60SZLF.md)
- [Motion - GP2Y0D805Z0F](https://github.com/rwaldron/johnny-five/blob/main/docs/motion-gp2y0d805z0f.md)
- [Motion - GP2Y0D810Z0F](https://github.com/rwaldron/johnny-five/blob/main/docs/motion-gp2y0d810z0f.md)
- [Motion - GP2Y0D810Z0F](https://github.com/rwaldron/johnny-five/blob/main/docs/motion-gp2y0d815z0f.md)

### Joystick
- [Joystick](https://github.com/rwaldron/johnny-five/blob/main/docs/joystick.md)
- [Joystick - Esplora](https://github.com/rwaldron/johnny-five/blob/main/docs/joystick-esplora.md)
- [Joystick - Pan + Tilt control](https://github.com/rwaldron/johnny-five/blob/main/docs/joystick-pantilt.md)
- [Joystick - Sparkfun Shield](https://github.com/rwaldron/johnny-five/blob/main/docs/joystick-shield.md)

### LCD
- [Grove - RGB LCD Color Previewer](https://github.com/rwaldron/johnny-five/blob/main/docs/lcd-rgb-bgcolor-previewer.md)
- [LCD](https://github.com/rwaldron/johnny-five/blob/main/docs/lcd.md)
- [LCD - Enumerate characters](https://github.com/rwaldron/johnny-five/blob/main/docs/lcd-enumeratechars.md)
- [LCD - I2C](https://github.com/rwaldron/johnny-five/blob/main/docs/lcd-i2c.md)
- [LCD - I2C PCF8574](https://github.com/rwaldron/johnny-five/blob/main/docs/lcd-i2c-PCF8574.md)
- [LCD - I2C Runner](https://github.com/rwaldron/johnny-five/blob/main/docs/lcd-i2c-runner.md)
- [LCD - Runner 16x2](https://github.com/rwaldron/johnny-five/blob/main/docs/lcd-runner.md)
- [LCD - Runner 20x4](https://github.com/rwaldron/johnny-five/blob/main/docs/lcd-runner-20x4.md)
- [LCD - Tessel 2 16x2](https://github.com/rwaldron/johnny-five/blob/main/docs/lcd-16x2-tessel.md)
- [Tessel 2 + Grove - RGB LCD Color Previewer](https://github.com/rwaldron/johnny-five/blob/main/docs/lcd-rgb-bgcolor-previewer-tessel.md)
- [Tessel 2 + Grove - RGB LCD Display](https://github.com/rwaldron/johnny-five/blob/main/docs/lcd-rgb-tessel-grove-JHD1313M1.md)

### Brújula / magnetómetro
- [Compass - Find north](https://github.com/rwaldron/johnny-five/blob/main/docs/magnetometer-north.md)
- [Compass - HMC5883L](https://github.com/rwaldron/johnny-five/blob/main/docs/compass-hmc5883l.md)
- [Compass - HMC6352](https://github.com/rwaldron/johnny-five/blob/main/docs/compass-hmc6352.md)
- [Compass - Logger](https://github.com/rwaldron/johnny-five/blob/main/docs/magnetometer-log.md)
- [Compass - MAG3110](https://github.com/rwaldron/johnny-five/blob/main/docs/compass-MAG3110.md)
- [Compass - MAG3110 on Tessel 2](https://github.com/rwaldron/johnny-five/blob/main/docs/compass-MAG3110-tessel.md)
- [Compass / Magnetometer](https://github.com/rwaldron/johnny-five/blob/main/docs/magnetometer.md)

### Piezoeléctrico
- [Piezo](https://github.com/rwaldron/johnny-five/blob/main/docs/piezo.md)

### IMU / multisensor
- [IMU - BNO055](https://github.com/rwaldron/johnny-five/blob/main/docs/imu-bno055.md)
- [IMU - BNO055 (Orientation)](https://github.com/rwaldron/johnny-five/blob/main/docs/imu-bno055-orientation.md)
- [IMU - LSM303C](https://github.com/rwaldron/johnny-five/blob/main/docs/imu-lsm303c.md)
- [IMU - MPU6050](https://github.com/rwaldron/johnny-five/blob/main/docs/imu-mpu6050.md)
- [Multi - BME280](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-BME280.md)
- [Multi - BMP085](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-bmp085.md)
- [Multi - BMP180](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-bmp180.md)
- [Multi - DHT11_I2C_NANO_BACKPACK](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-DHT11_I2C_NANO_BACKPACK.md)
- [Multi - DHT21_I2C_NANO_BACKPACK](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-DHT21_I2C_NANO_BACKPACK.md)
- [Multi - DHT22_I2C_NANO_BACKPACK](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-DHT22_I2C_NANO_BACKPACK.md)
- [Multi - HIH6130](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-HIH6130.md)
- [Multi - HTU21D](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-htu21d.md)
- [Multi - MPL115A2](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-mpl115a2.md)
- [Multi - MPL3115A2](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-mpl3115a2.md)
- [Multi - MS5611](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-MS5611.md)
- [Multi - SHT31D](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-sht31d.md)
- [Multi - SI7020](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-SI7020.md)
- [Multi - SI7021](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-SI7021.md)
- [Multi - TH02](https://github.com/rwaldron/johnny-five/blob/main/docs/multi-TH02.md)

### Sensores
- [Accelerometer](https://github.com/rwaldron/johnny-five/blob/main/docs/accelerometer.md)
- [Accelerometer - ADXL335](https://github.com/rwaldron/johnny-five/blob/main/docs/accelerometer-adxl335.md)
- [Accelerometer - ADXL345](https://github.com/rwaldron/johnny-five/blob/main/docs/accelerometer-adxl345.md)
- [Accelerometer - LIS3DH](https://github.com/rwaldron/johnny-five/blob/main/docs/accelerometer-LIS3DH.md)
- [Accelerometer - MMA7361](https://github.com/rwaldron/johnny-five/blob/main/docs/accelerometer-mma7361.md)
- [Accelerometer - MMA8452](https://github.com/rwaldron/johnny-five/blob/main/docs/accelerometer-MMA8452.md)
- [Accelerometer - MPU6050](https://github.com/rwaldron/johnny-five/blob/main/docs/accelerometer-mpu6050.md)
- [Accelerometer - Pan + Tilt](https://github.com/rwaldron/johnny-five/blob/main/docs/accelerometer-pan-tilt.md)
- [Altimeter - BMP085](https://github.com/rwaldron/johnny-five/blob/main/docs/altimeter-BMP085.md)
- [Altimeter - BMP180](https://github.com/rwaldron/johnny-five/blob/main/docs/altimeter-BMP180.md)
- [Altimeter - MPL3115A2](https://github.com/rwaldron/johnny-five/blob/main/docs/altimeter-mpl3115a2.md)
- [Altimeter - MS5611](https://github.com/rwaldron/johnny-five/blob/main/docs/altimeter-MS5611.md)
- [Barometer - BMP085](https://github.com/rwaldron/johnny-five/blob/main/docs/barometer-BMP085.md)
- [Barometer - BMP180](https://github.com/rwaldron/johnny-five/blob/main/docs/barometer-BMP180.md)
- [Barometer - MPL115A2](https://github.com/rwaldron/johnny-five/blob/main/docs/barometer-mpl115a2.md)
- [Barometer - MPL3115A2](https://github.com/rwaldron/johnny-five/blob/main/docs/barometer-mpl3115a2.md)
- [Barometer - MS5611](https://github.com/rwaldron/johnny-five/blob/main/docs/barometer-MS5611.md)
- [Gyro](https://github.com/rwaldron/johnny-five/blob/main/docs/gyro.md)
- [Gyro - Analog LPR5150AL](https://github.com/rwaldron/johnny-five/blob/main/docs/gyro-lpr5150l.md)
- [Gyro - I2C MPU6050](https://github.com/rwaldron/johnny-five/blob/main/docs/gyro-mpu6050.md)
- [Hygrometer - DHT11_I2C_NANO_BACKPACK](https://github.com/rwaldron/johnny-five/blob/main/docs/hygrometer-DHT11_I2C_NANO_BACKPACK.md)
- [Hygrometer - DHT21_I2C_NANO_BACKPACK](https://github.com/rwaldron/johnny-five/blob/main/docs/hygrometer-DHT21_I2C_NANO_BACKPACK.md)
- [Hygrometer - DHT22_I2C_NANO_BACKPACK](https://github.com/rwaldron/johnny-five/blob/main/docs/hygrometer-DHT22_I2C_NANO_BACKPACK.md)
- [Hygrometer - HIH6130](https://github.com/rwaldron/johnny-five/blob/main/docs/hygrometer-HIH6130.md)
- [Hygrometer - HTU21D](https://github.com/rwaldron/johnny-five/blob/main/docs/hygrometer-htu21d.md)
- [Hygrometer - SHT31D](https://github.com/rwaldron/johnny-five/blob/main/docs/hygrometer-sht31d.md)
- [Hygrometer - SI7021](https://github.com/rwaldron/johnny-five/blob/main/docs/hygrometer-SI7021.md)
- [Hygrometer - TH02](https://github.com/rwaldron/johnny-five/blob/main/docs/hygrometer-TH02.md)
- [Sensor](https://github.com/rwaldron/johnny-five/blob/main/docs/sensor.md)
- [Sensor - Digital Microwave](https://github.com/rwaldron/johnny-five/blob/main/docs/sensor-digital-microwave.md)
- [Sensor - Flex sensor](https://github.com/rwaldron/johnny-five/blob/main/docs/flex.md)
- [Sensor - Force sensitive resistor](https://github.com/rwaldron/johnny-five/blob/main/docs/sensor-fsr.md)
- [Sensor - Microphone](https://github.com/rwaldron/johnny-five/blob/main/docs/microphone.md)
- [Sensor - Photoresistor](https://github.com/rwaldron/johnny-five/blob/main/docs/photoresistor.md)
- [Sensor - Potentiometer](https://github.com/rwaldron/johnny-five/blob/main/docs/potentiometer.md)
- [Sensor - Slide potentiometer](https://github.com/rwaldron/johnny-five/blob/main/docs/sensor-slider.md)
- [Thermometer - BMP085](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-bmp085.md)
- [Thermometer - BMP180](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-BMP180.md)
- [Thermometer - DHT11_I2C_NANO_BACKPACK](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-DHT11_I2C_NANO_BACKPACK.md)
- [Thermometer - DHT21_I2C_NANO_BACKPACK](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-DHT21_I2C_NANO_BACKPACK.md)
- [Thermometer - DHT22_I2C_NANO_BACKPACK](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-DHT22_I2C_NANO_BACKPACK.md)
- [Thermometer - DS18B20](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-ds18b20.md)
- [Thermometer - Dual DS18B20](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-dual-ds18b20.md)
- [Thermometer - HIH6130](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-HIH6130.md)
- [Thermometer - HTU21D](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-htu21d.md)
- [Thermometer - LM335](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-lm335.md)
- [Thermometer - LM35](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-lm35.md)
- [Thermometer - MAX31850](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-max31850k.md)
- [Thermometer - MCP9808](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-MCP9808.md)
- [Thermometer - MPL115A2](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-mpl115a2.md)
- [Thermometer - MPL3115A2](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-mpl3115a2.md)
- [Thermometer - MPU6050](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-mpu6050.md)
- [Thermometer - MS5611](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-MS5611.md)
- [Thermometer - SHT31D](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-sht31d.md)
- [Thermometer - SI7020](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-SI7020.md)
- [Thermometer - SI7021](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-SI7021.md)
- [Thermometer - TH02](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-TH02.md)
- [Thermometer - TMP102](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-tmp102.md)
- [Thermometer - TMP36](https://github.com/rwaldron/johnny-five/blob/main/docs/temperature-tmp36.md)

### Expansor
- [Expander - 74HC595](https://github.com/rwaldron/johnny-five/blob/main/docs/expander-74HC595.md)
- [Expander - CD74HC4067, 16 Channel Analog Input Breakout](https://github.com/rwaldron/johnny-five/blob/main/docs/expander-CD74HC4067_NANO_BACKPACK.md)
- [Expander - LIS3DH](https://github.com/rwaldron/johnny-five/blob/main/docs/expander-LIS3DH.md)
- [Expander - MCP23008](https://github.com/rwaldron/johnny-five/blob/main/docs/expander-MCP23008.md)
- [Expander - MCP23017](https://github.com/rwaldron/johnny-five/blob/main/docs/expander-MCP23017.md)
- [Expander - MUXSHIELD2, Analog Sensors](https://github.com/rwaldron/johnny-five/blob/main/docs/expander-MUXSHIELD2-analog-read.md)
- [Expander - MUXSHIELD2, Digital Input and Output](https://github.com/rwaldron/johnny-five/blob/main/docs/expander-MUXSHIELD2-mixed.md)
- [Expander - PCA9685](https://github.com/rwaldron/johnny-five/blob/main/docs/expander-PCA9685.md)
- [Expander - PCF8574](https://github.com/rwaldron/johnny-five/blob/main/docs/expander-PCF8574.md)
- [Expander - PCF8575](https://github.com/rwaldron/johnny-five/blob/main/docs/expander-PCF8575.md)
- [Expander - PCF8591](https://github.com/rwaldron/johnny-five/blob/main/docs/expander-PCF8591.md)

### Shield meteorológico Photon
- [Photon Weather Shield: Moisture](https://github.com/rwaldron/johnny-five/blob/main/docs/sensor-photon-weather-shield-moisture.md)

### EVShield de LEGO
- [Button - EVShield EV3](https://github.com/rwaldron/johnny-five/blob/main/docs/button-EVS_EV3.md)
- [Button - EVShield NXT](https://github.com/rwaldron/johnny-five/blob/main/docs/button-EVS_NXT.md)
- [Color - EVShield EV3 (Code)](https://github.com/rwaldron/johnny-five/blob/main/docs/color-EVS_EV3.md)
- [Color - EVShield EV3 (Raw)](https://github.com/rwaldron/johnny-five/blob/main/docs/color-raw-EVS_EV3.md)
- [Color - EVShield NXT (Code)](https://github.com/rwaldron/johnny-five/blob/main/docs/color-EVS_NXT.md)
- [Light - BH1750](https://github.com/rwaldron/johnny-five/blob/main/docs/light-ambient-BH1750.md)
- [Light - EVShield EV3 (Ambient)](https://github.com/rwaldron/johnny-five/blob/main/docs/light-ambient-EVS_EV3.md)
- [Light - EVShield EV3 (Reflected)](https://github.com/rwaldron/johnny-five/blob/main/docs/light-reflected-EVS_EV3.md)
- [Light - EVShield NXT (Ambient)](https://github.com/rwaldron/johnny-five/blob/main/docs/light-ambient-EVS_NXT.md)
- [Light - EVShield NXT (Reflected)](https://github.com/rwaldron/johnny-five/blob/main/docs/light-reflected-EVS_NXT.md)
- [Light - TSL2561](https://github.com/rwaldron/johnny-five/blob/main/docs/light-ambient-TSL2561.md)
- [Motor - EVShield EV3](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-EVS_EV3.md)
- [Motor - EVShield NXT](https://github.com/rwaldron/johnny-five/blob/main/docs/motor-EVS_NXT.md)
- [Proximity - EVShield EV3 (IR)](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-EVS_EV3_IR-alert.md)
- [Proximity - EVShield EV3 (Ultrasonic)](https://github.com/rwaldron/johnny-five/blob/main/docs/proximity-EVS_EV3_US-alert.md)

### Intel Edison + kit IoT Grove
- [Intel Edison + Grove - Accelerometer (ADXL345)](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-accelerometer-adxl345-edison.md)
- [Intel Edison + Grove - Accelerometer (MMA7660)](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-accelerometer-mma7660-edison.md)
- [Intel Edison + Grove - Air quality sensor](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-gas-tp401-edison.md)
- [Intel Edison + Grove - Barometer (BMP180)](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-barometer-edison.md)
- [Intel Edison + Grove - Button](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-button-edison.md)
- [Intel Edison + Grove - Compass (HMC588L)](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-compass-edison.md)
- [Intel Edison + Grove - Flame Sensor](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-flame-sensor-edison.md)
- [Intel Edison + Grove - Gas (MQ2)](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-gas-mq2-edison.md)
- [Intel Edison + Grove - Humidity & Temperature (TH02)](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-humidity-temperature-edison.md)
- [Intel Edison + Grove - I2C Motor Driver](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-i2c-motor-driver-edison.md)
- [Intel Edison + Grove - Joystick](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-joystick-edison.md)
- [Intel Edison + Grove - LED](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-led-edison.md)
- [Intel Edison + Grove - Light Sensor (TSL2561)](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-light-sensor-edison.md)
- [Intel Edison + Grove - Moisture Sensor](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-moisture-edison.md)
- [Intel Edison + Grove - Q Touch](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-q-touch.md)
- [Intel Edison + Grove - RGB LCD](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-lcd-rgb-edison.md)
- [Intel Edison + Grove - RGB LCD Color Previewer](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-lcd-rgb-bgcolor-previewer-edison.md)
- [Intel Edison + Grove - RGB LCD temperature display](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-lcd-rgb-temperature-display-edison.md)
- [Intel Edison + Grove - Relay](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-relay-edison.md)
- [Intel Edison + Grove - Rotary Potentiometer](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-rotary-potentiometer-edison.md)
- [Intel Edison + Grove - Servo](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-servo-edison.md)
- [Intel Edison + Grove - Touch](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-touch-edison.md)

### Kit IoT Grove (Seeed Studio)
- [Grove - Button](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-button.md)
- [Grove - Joystick](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-joystick.md)
- [Grove - LED](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-led.md)
- [Grove - Motor (I2C Driver)](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-i2c-motor-driver.md)
- [Grove - RGB LCD](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-lcd-rgb.md)
- [Grove - RGB LCD temperature display](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-lcd-rgb-temperature-display.md)
- [Grove - Rotary Potentiometer](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-rotary-potentiometer.md)
- [Grove - Servo](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-servo.md)
- [Grove - Touch](https://github.com/rwaldron/johnny-five/blob/main/docs/grove-touch.md)

### Micro Magician V2
- [Micro Magician V2 - Accelerometer](https://github.com/rwaldron/johnny-five/blob/main/docs/micromagician-accelerometer.md)
- [Micro Magician V2 - Motor](https://github.com/rwaldron/johnny-five/blob/main/docs/micromagician-motor.md)
- [Micro Magician V2 - Servo](https://github.com/rwaldron/johnny-five/blob/main/docs/micromagician-servo.md)

### TinkerKit
- [TinkerKit - Accelerometer](https://github.com/rwaldron/johnny-five/blob/main/docs/tinkerkit-accelerometer.md)
- [TinkerKit - Blink](https://github.com/rwaldron/johnny-five/blob/main/docs/tinkerkit-blink.md)
- [TinkerKit - Button](https://github.com/rwaldron/johnny-five/blob/main/docs/tinkerkit-button.md)
- [TinkerKit - Combo](https://github.com/rwaldron/johnny-five/blob/main/docs/tinkerkit-combo.md)
- [TinkerKit - Continuous servo](https://github.com/rwaldron/johnny-five/blob/main/docs/tinkerkit-continuous-servo.md)
- [TinkerKit - Gyro](https://github.com/rwaldron/johnny-five/blob/main/docs/tinkerkit-gyroscope.md)
- [TinkerKit - Joystick](https://github.com/rwaldron/johnny-five/blob/main/docs/tinkerkit-joystick.md)
- [TinkerKit - Linear potentiometer](https://github.com/rwaldron/johnny-five/blob/main/docs/tinkerkit-linear-pot.md)
- [TinkerKit - Rotary potentiometer](https://github.com/rwaldron/johnny-five/blob/main/docs/tinkerkit-rotary.md)
- [TinkerKit - Temperature](https://github.com/rwaldron/johnny-five/blob/main/docs/tinkerkit-thermistor.md)
- [TinkerKit - Tilt](https://github.com/rwaldron/johnny-five/blob/main/docs/tinkerkit-tilt.md)
- [TinkerKit - Touch](https://github.com/rwaldron/johnny-five/blob/main/docs/tinkerkit-touch.md)

### Wii
- [Wii Classic Controller](https://github.com/rwaldron/johnny-five/blob/main/docs/classic-controller.md)
- [Wii Nunchuck](https://github.com/rwaldron/johnny-five/blob/main/docs/nunchuk.md)

### Robots y proyectos completos
- [Bug](https://github.com/rwaldron/johnny-five/blob/main/docs/bug.md)
- [Kinect Robotic Arm Controller](https://github.com/rwaldron/johnny-five/blob/main/docs/kinect-arm-controller.md)
- [Laser Trip Wire](https://github.com/rwaldron/johnny-five/blob/main/docs/laser-trip-wire.md)
- [Line Follower](https://github.com/rwaldron/johnny-five/blob/main/docs/line-follower.md)
- [Lynxmotion Biped BRAT](https://github.com/rwaldron/johnny-five/blob/main/docs/brat.md)
- [Motobot](https://github.com/rwaldron/johnny-five/blob/main/docs/motobot.md)
- [Navigator](https://github.com/rwaldron/johnny-five/blob/main/docs/navigator.md)
- [Nodebot](https://github.com/rwaldron/johnny-five/blob/main/docs/nodebot.md)
- [Phoenix Hexapod](https://github.com/rwaldron/johnny-five/blob/main/docs/phoenix.md)
- [Radar](https://github.com/rwaldron/johnny-five/blob/main/docs/radar.md)
- [Robotic Claw](https://github.com/rwaldron/johnny-five/blob/main/docs/claw.md)
- [Whisker](https://github.com/rwaldron/johnny-five/blob/main/docs/whisker.md)

### Plantilla de complemento de componentes
- [Example plugin](https://github.com/rwaldron/johnny-five/blob/main/docs/plugin.md)

### Complementos de E/S
- [Led Blink on Electric Imp](https://github.com/rwaldron/johnny-five/blob/main/docs/imp-io.md)
- [Led Blink on Intel Edison Arduino Board](https://github.com/rwaldron/johnny-five/blob/main/docs/edison-io-arduino.md)
- [Led Blink on Intel Edison Mini Board](https://github.com/rwaldron/johnny-five/blob/main/docs/edison-io-miniboard.md)
- [Led Blink on Intel Galileo Gen 2](https://github.com/rwaldron/johnny-five/blob/main/docs/galileo-io.md)
- [Led Blink on Raspberry Pi](https://github.com/rwaldron/johnny-five/blob/main/docs/raspi-io.md)
- [Led Blink on Spark Core](https://github.com/rwaldron/johnny-five/blob/main/docs/spark-io.md)
- [Led Blink on pcDuino3](https://github.com/rwaldron/johnny-five/blob/main/docs/pcduino-io.md)

<!--extract-end:examples-->

## Muchos proyectos: algunos grandes y otros pequeños

#### [NodeBot inalámbrico](http://jsfiddle.net/rwaldron/88M6b/show/light)
#### [Brazo robótico controlado con Kinect](http://jsfiddle.net/rwaldron/XMsGQ/show/light/)
#### [NodeBot bípedo](http://jsfiddle.net/rwaldron/WZkn5/show/light/)
#### [Hombre corriendo en LCD](http://jsfiddle.net/rwaldron/xKwaU/show/light/)
#### [Servomotor panorámico controlado con un deslizador](http://jsfiddle.net/rwaldron/kZakv/show/light/)
#### [Láser controlado con joystick (panorámica/inclinación) 1](http://jsfiddle.net/rwaldron/HPqms/show/light/)
#### [Láser controlado con joystick (panorámica/inclinación) 2](http://jsfiddle.net/rwaldron/YHb7A/show/light/)
#### [Pinza controlada con joystick](http://jsfiddle.net/rwaldron/6ZXFe/show/light/)
#### [Pinza robótica](http://jsfiddle.net/rwaldron/CFSZJ/show/light/)
#### [Joystick, motor y LED](http://jsfiddle.net/rwaldron/gADSz/show/light/)
#### [Construye tu propio dron](http://github.com/darioodiaz/node-open-pilot/)



## Make: JavaScript Robotics

[![](http://ecx.images-amazon.com/images/I/91ae8ZZDQ2L.jpg)](http://shop.oreilly.com/product/0636920031390.do)




## Contribuir
Todas las contribuciones deben seguir la [guía de estilo Idiomatic.js](https://github.com/rwaldron/idiomatic.js) y mantener el estilo de código existente. Añade pruebas unitarias para cualquier funcionalidad nueva o modificada. Ejecuta el linter y las pruebas con [grunt](https://github.com/gruntjs/grunt).


## Licencia
Copyright (c) 2012, 2013, 2014 Rick Waldron <waldron.rick@gmail.com>
Publicado bajo la licencia MIT.
Copyright (c) 2014, 2015 The Johnny-Five Contributors
Publicado bajo la licencia MIT.

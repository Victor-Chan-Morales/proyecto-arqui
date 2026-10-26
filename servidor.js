const hostname = '127.0.0.1';
const port = 8081;

// cargar el módulo express
const express = require('express');
// crear un objeto para la aplicación web
const app = express();

// crear el websocket utilizando el puerto 8081
var io = require('socket.io')(app.listen(port));

// cargar la api de johnny-5
var five = require('johnny-five');

const path = require('path');
const router = express.Router();

router.get('/', function (req, res) {
  res.sendFile(path.join(__dirname+'/dashboard.html'));
});

app.use('/', router);

// Declaración de la tarjeta a utilizar y funciones de control
var board = new five.Board({port: "/dev/ttyACM0", repl:false});

// Declaración de los objetos conectados a la tarjeta
board.on('ready', function(){
  var led = new five.Led(13);
  // funciones de conexión a través del websocket
  commands = null;

  io.on('connection', function(socket){
    socket.on('Encender', function(){
      led.on();
    });

    socket.on('Apagar', function(){
      led.off();
    });
  });
});
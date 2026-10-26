#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Nombre_red";
const char* password = "password";

WebServer servidor(80);
int pinLed = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(10);
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, LOW);
  // Conectar a la red inalámbrica
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
   Serial.println("");
   Serial.println("Conectando a la red WiFi");
   servidor.begin();
   Serial.println("Dirección IP para conexión: ");
   Serial.println("http://");
   Serial.println(WiFi.localIP());
}

void loop() {
  //verificar si se conecta el cliente
  WifiClient cliente = servidor.available();
  if (!cliente) {
    return;
  }
  // Esperar a que el cliente envíe algo
    Serial.println("Cliente conectado");
    while(!cliente.available()){
      delay(1);
    }
}

// leer el contenido del REQUEST
String request = cliente.readStringUntil('\r');
Serial.println(request);
cliente.flush();
//Verificar la peticion del cliente
int value = LOW;
if (request.indexOf("/LED=ON") != -1) {
  digitalWrite(pinLed, HIGH);
  value = HIGH;
}
if (request.indexOf("/LED=OFF") != -1) {
  digitalWrite(pinLed, LOW);
  value = LOW;
}
// Devolver al cliente una respuesta 
cliente.println("HTTP/1.1 200 OK");
cliente.println("Content-Type: text/html");
cliente.println(""); // No olvidar esta linea
cliente.println("<!DOCTYPE HTML>");
cliente.println("<html>");
cliente.print("Estado del LED: ");
if(value == HIGH) {
  cliente.print("Encendido");
} else {
  cliente.print("Apagado");
}
cliente.println("<br><br>");
cliente.println("<a href=\"/LED=ON\"><button>Encender</button/> LED</a>");
cliente.println("<a href=\"/LED=OFF\"><button>Apagar</button/> LED</a>");
cliente.println("</html>");
delay(1);
Serial.println("Cliente desconectado");


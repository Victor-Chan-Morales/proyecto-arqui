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

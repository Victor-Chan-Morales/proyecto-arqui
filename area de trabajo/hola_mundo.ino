#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Nombre_red";
const char* password = "password";

WebServer servidor(80);
const int pinLed = 2;

void setup() {
  Serial.begin(9600);
  delay(10);

  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, LOW);

  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Conectado a la red WiFi");

  servidor.on("/", HTTP_GET, []() {
    servidor.send(200, "text/html",
      "<!doctype html><html><body>"
      "<p>El LED ahora se encuentra:</p>"
      "<a href=\"/LED=ON\"><button>Encender</button></a>"
      "<a href=\"/LED=OFF\"><button>Apagar</button></a>"
      "</body></html>");
  });

  servidor.on("/LED=ON", HTTP_GET, []() {
    digitalWrite(pinLed, HIGH);
    servidor.send(200, "text/plain", "LED encendido");
  });

  servidor.on("/LED=OFF", HTTP_GET, []() {
    digitalWrite(pinLed, LOW);
    servidor.send(200, "text/plain", "LED apagado");
  });

  servidor.onNotFound([]() {
    servidor.send(404, "text/plain", "Ruta no encontrada");
  });

  servidor.begin();
  Serial.print("Abre http://");
  Serial.println(WiFi.localIP());
}

void loop() {
  servidor.handleClient();
}

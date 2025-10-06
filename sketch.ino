#include <WiFi.h>
#include <PubSubClient.h>

// ======= CONFIGURAÇÃO WIFI =======
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// ======= CONFIGURAÇÃO MQTT =======
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;
const char* topic = "passaabola/sensores";

WiFiClient espClient;
PubSubClient client(espClient);

// ======= SENSOR ULTRASSÔNICO =======
#define TRIG_PIN 18
#define ECHO_PIN 19


// ======= POTENCIÔMETRO =======
#define POT_PIN 34

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    if (client.connect("ESP32_PassaBola")) {
      Serial.println(" Conectado!");
    } else {
      Serial.print(" Falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5s...");
      delay(5000);
    }
  }
}

float medirDistancia() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  float duracao = pulseIn(ECHO_PIN, HIGH);
  float distancia = duracao * 0.034 / 2; // cm
  return distancia;
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(POT_PIN, INPUT);

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  // ======= LÊ SENSORES =======
  float distancia = random(10, 35) + random(0, 99) / 100.0;
  int potValor = analogRead(POT_PIN);
  float rotacao = map(potValor, 0, 4095, 0, 500); // Simula RPM

  // ======= MONTA JSON =======
  String payload = "{\"dispositivo\":\"bola\",\"velocidade\":" + String(distancia, 2) +
                   ",\"rotacao\":" + String(rotacao, 2) + "}";

  // ======= ENVIA VIA MQTT =======
  client.publish(topic, payload.c_str());
  Serial.println("📡 Enviado: " + payload);

  delay(2000);
}

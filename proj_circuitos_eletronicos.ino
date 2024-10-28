/*
Projeto de Circuitos Eletrônicos

Neste projeto, simulando uma estufa de hortaliças, deve ser desenvolvido no simulador TinkerCad um circuito eletrônico envolvendo um sensor de temperatura, uma buzina, um LED e um motor, controlados por meio de um Arduino
*/

// Definição de pinos
#define TEMP_SENSOR A0
#define FAN_PIN 3
#define LED_PIN 4
#define BUZZER_PIN 5

void setup() {
  // Configuração dos pinos
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);  // Para monitoramento
}

void loop() {
  // Leitura da temperatura (fornece 10mV por °C)
  int sensorValue = analogRead(TEMP_SENSOR);
  float temperature = sensorValue * (5.0 / 1023.0) * 100;

  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" \u00B0C");

  // Acionamento do ventilador
  if (temperature >= 30) {
    digitalWrite(FAN_PIN, HIGH);
  } else {
    digitalWrite(FAN_PIN, LOW);
  }

  // Acionamento do LED e buzina em caso de emergência
  if (temperature > 50) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(1000);  // Intervalo de 1 segundo entre leituras
}

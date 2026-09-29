#include <Arduino.h>

// ============================================================================
// DEFINIÇÃO DOS PINOS
// ============================================================================
const int SENSOR_PIN = A0; // Entrada analógica onde o sinal do sensor está ligado
const int LED1_PIN   = 12; // LED 1 (Pino 12) - Simula o Relé
const int LED2_PIN   = 11; // LED 2 (Pino 11) - Indicador de leitura

// ============================================================================
// PARÂMETROS DE CONFIGURAÇÃO
// ============================================================================
const int LIMIAR_DISPARO = 500; // Limite de acionamento do sensor (0 a 1023)

// Temporizador sem bloqueio (millis)
unsigned long tempoAnteriorLeitura = 0;
const unsigned long INTERVALO_LEITURA = 500; // Lê o sensor a cada 500ms (0.5s)

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);

  Serial.begin(9600);
  Serial.println("=============================================");
  Serial.println(" SISTEMA DE LEITURA E CONTROLO DE SENSOR ");
  Serial.println("=============================================");
}

void loop() {
  unsigned long tempoAtual = millis();

  // Leitura do sensor a cada 500ms usando millis()
  if (tempoAtual - tempoAnteriorLeitura >= INTERVALO_LEITURA) {
    tempoAnteriorLeitura = tempoAtual;

    // Pisca rapidamente o LED2 (pino 11) para demonstrar que está a ler o sensor
    digitalWrite(LED2_PIN, HIGH);

    // 1. Leitura do sinal do sensor no pino A0 (retorna de 0 a 1023)
    int valorSensor = analogRead(SENSOR_PIN);

    // 2. Cálculo do valor em Voltagem (0.0V a 5.0V)
    float voltagem = (valorSensor * 5.0) / 1023.0;

    // 3. Exibição dos dados no Serial Monitor
    Serial.print("Leitura A0 (ADC): ");
    Serial.print(valorSensor);
    Serial.print(" | Voltagem: ");
    Serial.print(voltagem, 2);
    Serial.println("V");

    digitalWrite(LED2_PIN, LOW);

    // 4. Lógica de decisão: aciona o LED1 (Relé) se ultrapassar o limiar
    if (valorSensor >= LIMIAR_DISPARO) {
      digitalWrite(LED1_PIN, HIGH); // Liga o LED (Relé)
      Serial.println("  --> [ALERTA] Limiar atingido! Saída ATIVA.");
    } else {
      digitalWrite(LED1_PIN, LOW);  // Desliga o LED (Relé)
    }
  }
}
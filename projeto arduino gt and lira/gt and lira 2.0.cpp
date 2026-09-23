#include <Arduino.h>

// Define o pino digital 2 do Arduino ligado à entrada IN1 do relé
const int relayPin = 2;  

void setup() {
  // Configura o pino do relé como saída
  pinMode(relayPin, OUTPUT);
}

void loop() {
  // Liga o relé (e consequentemente a fita de LED de 24V)
  digitalWrite(relayPin, HIGH);  
  delay(2000); // Mantém ligado por 1 segundo (1000 milissegundos)

  // Desliga o relé
  digitalWrite(relayPin, LOW);  
  delay(2000); // Mantém desligado por 1 segundo
}
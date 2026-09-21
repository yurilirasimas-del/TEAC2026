#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT); // Define o pino 13 como saída
}

void loop() {
  digitalWrite(2, HIGH); // Liga o LED
  delay(2000);              // Espera 1 segundo
  digitalWrite(2, LOW);  // Desliga o LED
  delay(2000);              // Espera 1 segundo
}
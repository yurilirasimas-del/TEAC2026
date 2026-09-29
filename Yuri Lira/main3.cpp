// #include <Arduino.h>

// // Definição dos Pinos dos LEDs
// const int LED1_PIN = 12; // Cabo laranja COMPRIDO na breadboard
// const int LED2_PIN = 11; // Cabo laranja CURTO na breadboard

// // Configuração do Temporizador (millis)
// unsigned long tempoAnterior = 0;
// const unsigned long INTERVALO_TIMER = 1000; // Tempo em milissegundos (1000 ms = 1 segundo)
// bool estadoLeds = false;

// void setup() {
//   // Configura os pinos dos LEDs como saída
//   pinMode(LED1_PIN, OUTPUT);
//   pinMode(LED2_PIN, OUTPUT);
// }

// void loop() {
//   unsigned long tempoAtual = millis();

//   // Verifica se passou o intervalo de 1 segundo sem usar delay()
//   if (tempoAtual - tempoAnterior >= INTERVALO_TIMER) {
//     tempoAnterior = tempoAtual; // Atualiza a marcação de tempo

//     // Alterna o estado (ligado/desligado)
//     estadoLeds = !estadoLeds;

//     // Aplica os estados aos LEDs de forma alternada
//     digitalWrite(LED1_PIN, estadoLeds);
//     digitalWrite(LED2_PIN, !estadoLeds);
//   }
// }
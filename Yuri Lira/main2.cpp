// #include <Arduino.h>

// // ============================================================================
// // DEFINIÇÃO DOS PINOS
// // ============================================================================
// const int LED1_PIN   = 12; // SIMULA O RELÉ (Liga por 5 segundos quando dispara)
// const int LED2_PIN   = 11; // INDICADOR DE LEITURA (Pisca a cada leitura)
// const int SENSOR_PIN = A0; // Entrada do Sensor V1

// // ============================================================================
// // PARÂMETROS E TEMPORIZADORES (millis)
// // ============================================================================
// // Alterado para 10 para acionar facilmente no teste
// const int LIMIAR_DISPARO = 10; 

// unsigned long tempoAnteriorLeitura = 0;
// unsigned long tempoAnteriorRele    = 0;

// const unsigned long INTERVALO_LEITURA = 5000; // 1 segundo
// const unsigned long TEMPO_RELE_LIGADO = 5000; // 5 segundos

// bool releAtivo = false;

// void setup() {
//   pinMode(LED1_PIN, OUTPUT);
//   pinMode(LED2_PIN, OUTPUT);
  
//   digitalWrite(LED1_PIN, LOW);
//   digitalWrite(LED2_PIN, LOW);

//   Serial.begin(9600);
// }

// void loop() {
//   unsigned long tempoAtual = millis();

//   // 1. Temporizador: Leitura do Sensor a cada 1 segundo
//   if (tempoAtual - tempoAnteriorLeitura >= INTERVALO_LEITURA) {
//     tempoAnteriorLeitura = tempoAtual;

//     // Pisca rapidamente o LED2 (pino 11) para confirmar visualmente que o loop está a rodar
//     digitalWrite(LED2_PIN, HIGH);
    
//     int valorSensor = analogRead(SENSOR_PIN);
//     Serial.print("Valor do Sensor A0: ");
//     Serial.println(valorSensor);

//     digitalWrite(LED2_PIN, LOW);

//     // Se o valor for maior que o limiar e o relé estiver desligado -> LIGA
//     if (valorSensor > LIMIAR_DISPARO && !releAtivo) {
//       digitalWrite(LED1_PIN, HIGH); // LIGA O RELÉ (LED 12)
//       releAtivo = true;
//       tempoAnteriorRele = tempoAtual;
//       Serial.println("-> LIMIAR ATINGIDO! Relé (LED 12) LIGADO.");
//     }
//   }

//   // 2. Temporizador: Desliga o Relé após 5 segundos
//   if (releAtivo && (tempoAtual - tempoAnteriorRele >= TEMPO_RELE_LIGADO)) {
//     digitalWrite(LED1_PIN, LOW); // DESLIGA O RELÉ (LED 12)
//     releAtivo = false;
//     Serial.println("-> TEMPO ESGOTADO! Relé (LED 12) DESLIGADO.");
//   }
// }
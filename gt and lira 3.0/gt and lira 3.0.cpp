#include <Arduino.h>

// Definição dos pinos e constantes do termistor NTC 10K (KY-013)
const int sensorPin = A0;             // Pino de sinal ligado a A0
const float SERIES_RESISTOR = 10000.0;  // Resistor fixo de 10k ohms no módulo
const float NOMINAL_RESISTANCE = 10000.0; // Resistência do termistor a 25°C
const float NOMINAL_TEMPERATURE = 25.0;   // Temperatura nominal em Celsius
const float B_COEFFICIENT = 3435.0;       // Coeficiente Beta típico para NTC 10K

void setup() {
  // Inicializa a comunicação série a 9600 baud conforme requisito
  Serial.begin(9600);
}

void loop() {
  // 1. Lê o valor bruto do conversor analógico-digital (ADC: 0 a 1023)
  int rawADC = analogRead(sensorPin);

  // Proteção contra divisão por zero ou leituras inválidas extremas
  if (rawADC <= 0 || rawADC >= 1023) {
    Serial.println("Erro: Leitura fora do intervalo válido!");
    delay(1000);
    return;
  }

  // 2. Calcula a resistência atual do termistor NTC
  // Fórmula baseada na estrutura do divisor de tensão do KY-013
  float resistencia = SERIES_RESISTOR / ((1023.0 / (float)rawADC) - 1.0);

  // 3. Aplica a equação de Steinhart-Hart (Versão do Parâmetro Beta)
  float steinhart;
  steinhart = resistencia / NOMINAL_RESISTANCE;     // (R / Ro)
  steinhart = log(steinhart);                      // ln(R / Ro)
  steinhart /= B_COEFFICIENT;                      // (1 / B) * ln(R / Ro)
  steinhart += 1.0 / (NOMINAL_TEMPERATURE + 273.15); // + (1 / To)
  steinhart = 1.0 / steinhart;                     // Inverte para obter Kelvin
  float temperaturaC = steinhart - 273.15;         // Converte de Kelvin para Celsius

  // 4. Imprime a leitura bruta e a temperatura convertida no Monitor Série
  Serial.print("ADC Bruto: ");
  Serial.print(rawADC);
  Serial.print(" | Temperatura: ");
  Serial.print(temperaturaC, 2); // Mostra a temperatura com 2 casas decimais
  Serial.println(" °C");

  // Aguarda 1 segundo antes da próxima leitura
  delay(1000);
}
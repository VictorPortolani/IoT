# Sensor de Umidade do Solo

Sistema IoT de monitoramento da umidade do solo utilizando Arduino, que emite alertas sonoros e visuais quando o solo está muito seco.

## 📋 Descrição

O projeto utiliza um sensor de umidade do solo para medir a condição do solo e aciona um LED e um buzzer quando a leitura fica abaixo do limite definido, indicando a necessidade de irrigação.

## 🎯 Funcionalidades

- Leitura da umidade do solo via sensor analógico
- Alerta visual com LED
- Alerta sonoro com buzzer
- Exibição da umidade no Serial Monitor
- Verificação a cada 1 segundo

## 🔧 Componentes

- 1x Arduino Uno R3
- 1x Sensor de umidade do solo
- 1x Piezo
- 1x LED Vermelho
- 1x Resistor 150 Ω
- 1x Resistor 1 kΩ

## 📡 Pinagem

- Sensor de umidade: A0
- LED: D2
- Buzzer: D4

## 💻 Como Funciona

1. O Arduino lê o valor analógico do sensor de umidade no pino A0.
2. Exibe a leitura no Serial Monitor a 9600 bps.
3. Se o valor for menor que 400, considera o solo muito seco.
4. Aciona o LED e o buzzer como alerta.
5. Caso contrário, informa que o solo está com umidade adequada.
6. O ciclo se repete a cada 1 segundo.
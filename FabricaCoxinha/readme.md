
# Fábrica de Coxinha

Sistema IoT de controle de qualidade para monitoramento do tamanho de coxinhas utilizando Arduino.

## 📋 Descrição

O projeto implementa um sistema automatizado que valida o tamanho das coxinhas produzidas usando um sensor ultrassônico. O sistema emite alertas visuais (LED) e sonoros (buzzer) quando o produto sai das especificações.

## 🎯 Funcionalidades

| Tamanho (cm) | Ação |
|---|---|
| **> 10** | Aciona LED e buzzer - Coxinha muito grande (desperdício de massa) |
| **5 - 10** | LED desligado - Tamanho dentro do permitido ✓ |
| **< 5** | Aciona LED e buzzer - Coxinha muito pequena (desperdício de massa) |

## 🔧 Componentes

- 1x Arduino Uno R3
- 1x Sensor Ultrassônico (4 pinos)
- 1x LED Vermelho
- 1x Buzzer/Piezo
- 1x Resistor 150Ω
- 1x Resistor 1kΩ

## 📡 Pinagem

| Componente | Pino Arduino |
|---|---|
| Sensor TRIG | D10 |
| Sensor ECHO | D11 |
| LED | D7 |
| Buzzer | D9 |

## 💻 Como Funciona

1. O sensor ultrassônico mede a distância até a coxinha
2. O valor é convertido para centímetros
3. Comparado com os limites (10cm e 20cm)
4. Se fora dos limites, aciona LED e emite som de alerta
5. Dados são exibidos no Serial Monitor a cada 2 segundos

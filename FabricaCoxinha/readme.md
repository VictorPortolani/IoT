
# Fábrica de Coxinha

Sistema IoT de controle de temperatura para monitoramento do forno de fritura de coxinhas utilizando Arduino.

## 📋 Descrição

O projeto implementa um sistema automatizado que monitora a temperatura do óleo de fritura. O sistema emite alertas visuais (LED) e sonoros (buzzer) quando a temperatura sai da faixa ideal para fritar coxinhas.

## 🎯 Funcionalidades

| Temperatura (°C) | Ação |
|---|---|
| **> 180** | Aciona LED e buzzer - Temperatura muito alta (risco de queimar a coxinha) |
| **150 - 180** | LED desligado - Temperatura ideal para o forno ✓ |
| **< 150** | Aciona LED e buzzer - Temperatura muito baixa (coxinha não frita direito) |

## 🔧 Componentes

- 1x Arduino Uno R3
- 1x Sensor de Temperatura TMP36
- 1x LED Vermelho
- 1x Buzzer/Piezo
- 1x Resistor 150Ω
- 1x Resistor 1kΩ

## 📡 Pinagem

| Componente | Pino Arduino |
|---|---|
| Sensor Temperatura | A0 |
| LED | D7 |
| Buzzer | D9 |

## 💻 Como Funciona

1. O sensor TMP36 mede a temperatura do óleo
2. O valor é convertido para graus Celsius
3. Comparado com os limites (150°C e 180°C)
4. Se fora dos limites, aciona LED e emite som de alerta
5. Dados são exibidos no Serial Monitor a cada 2 segundos


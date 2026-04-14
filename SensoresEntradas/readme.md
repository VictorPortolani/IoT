
# Aula1004 - Sensores e Entradas

## Descrição
Projeto de Arduino com dois sensores ultrassônicos para medição de distância em modo digital e analógico.

## Componentes
- 1x Arduino Uno R3 (U1)
- 1x Sensor de distância ultrassônico (PINGDigital)
- 1x Sensor de distância ultrassônico 4 pinos (DISTAnalógico)

## Conexões
- **Pino 12**: Trigger sensor analógico (OUTPUT)
- **Pino 11**: Echo sensor analógico (INPUT)
- **Pino 7**: Signal sensor digital (OUTPUT/INPUT)

## Funcionalidades
- `distanciaAnalog()`: Lê distância do sensor analógico
- `distanciaDigital()`: Lê distância do sensor digital
- Saída via Serial (9600 baud)

## Como usar
1. Carregar o código no Arduino
2. Abrir Monitor Serial
3. Visualizar leituras de distância em cm

## Data
14/04/2026

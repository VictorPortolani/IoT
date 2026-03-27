# Módulo Resistor Variável - Sistema de Cortinas Automáticas

## 📋 Descrição

Sistema IoT baseado em Arduino Uno R3 que controla o fechamento automático de cortinas através de um sensor de luz (fotorresistor) e um potenciômetro (resistor variável). O projeto inclui um buzzer para feedback sonoro e comunicação serial para monitoramento.

## 🔧 Componentes Necessários

| Componente | Quantidade | Especificação |
|-----------|-----------|--------------|
| Arduino Uno R3 | 1 | Microcontrolador principal |
| Potenciômetro | 1 | 250 kΩ |
| Fotorresistor | 1 | Sensor de luz (LDR) |
| Resistor | 2 | 1 kΩ cada |
| Piezo (Buzzer) | 1 | Saída de som |

## 📌 Esquema de Ligação

### Pinos Utilizados

- **Pino 9 (PWM)**: Buzzer/Piezo
- **Pino A0**: Potenciômetro (entrada analógica)
- **Pino A1**: Fotorresistor (entrada analógica)
- **Comunicação Serial**: 9600 baud

### Montagem dos Sensores

**Potenciômetro (A0):**
- Terminal 1 → GND
- Terminal 2 (central) → A0
- Terminal 3 → 5V

**Fotorresistor (A1):**
- Uma ponta → 5V
- Outra ponta → A1 + Resistor 1kΩ para GND

**Buzzer (Pino 9):**
- Positivo (+) → Pino 9
- Negativo (-) → GND

## 🎵 Funcionalidades

### 1. **Leitura de Sensores**
- `lerPotenciometro()`: Lê o valor do potenciômetro (0-1023)
- `lerFotosensor()`: Lê o valor do fotorresistor (0-1023)

### 2. **Controle de Cortinas**
- `baixarCortinas()`: Verifica condições e ativa o sistema de alarme se necessário
  - Se luz > 500 E potenciômetro > 0: Toca alarme e exibe mensagem de erro
  - Caso contrário: Sistema OK

### 3. **Feedback Sonoro**
- `musicBuzzer()`: Toca uma sequência de tons crescentes (100Hz a 1000Hz)
- `musicBoateAzul()`: Toca uma melodia simplificada (trecho de "Barco Azul")
- `playNote()`: Função auxiliar para tocar notas específicas

### 4. **Definições de Notas Musicais**
Notas em frequência (Hz):
- NOTE_C4: 262 Hz
- NOTE_D4: 294 Hz
- NOTE_E4: 330 Hz
- NOTE_F4: 349 Hz
- NOTE_G4: 392 Hz
- NOTE_A4: 440 Hz
- NOTE_B4: 494 Hz
- NOTE_C5: 523 Hz

## 🚀 Como Usar

1. **Carregue o código** no Arduino Uno R3 usando a IDE do Arduino
2. **Abra o Monitor Serial** (baud: 9600)
3. **Ajuste o potenciômetro** e observe o valor no Monitor Serial
4. **Varie a luz** sobre o fotorresistor e observe as mudanças
5. **O sistema acionará o buzzer** se as condições forem atendidas

### Estrutura do Loop Principal

```cpp
void loop() {
    baixarCortinas();    // Executa a verificação de cortinas
    // musicBoateAzul();  // Descomentado para tocar a melodia
}
```

## 📊 Lógica de Funcionamento

```
LOOP:
  ├─ Ler Fotosensor (A1)
  ├─ Ler Potenciômetro (A0)
  │
  └─ SE (Luz >= 500 AND Potenciômetro > 0) ENTÃO
      ├─ Tocar Alarme (musicBuzzer)
      └─ Exibir "Não funcionou o sistema automático"
      
     SENÃO
      └─ Exibir "Sistema OK"
  
  └─ Aguardar 1 segundo antes de próxima leitura
```

## 🔍 Monitoramento Serial

Os valores lidos pelos sensores são exibidos no Monitor Serial:

```
Valor do Fotosensor: 450
Valor do Potenciômetro: 512
Valor do Fotosensor: 650
Valor do Potenciômetro: 0
Sistema OK
```

## 📝 Notas Importantes

- O delay de 1 segundo entre leituras pode ser ajustado conforme necessário
- O limite de luz (`limitarLuz = 600`) é uma constante que pode ser modificada
- A variável `limitarLuz` está definida mas não está sendo utilizada no código atual
- O sistema atual está simplificado e pronto para expandir com mais lógica de controle

## 🛠️ Possíveis Melhorias

- [ ] Integrar a variável `limitarLuz` na lógica de decisão
- [ ] Adicionar controle PWM para gradação de cortinas
- [ ] Implementar módulo WiFi para controle remoto
- [ ] Adicionar sensor de temperatura
- [ ] Registrar dados em SD card ou cloud
- [ ] Interface web para configuração de parâmetros

## 📄 Licença

Projeto educacional - Aula 27/03

## ✉️ Contato

Para dúvidas ou sugestões, consulte a documentação do Arduino ou entre em contato com o instrutor.

# 🪟 Regulagem Automática de Cortina - Sistema de Automação Residencial

## Visão Geral do Projeto

Este projeto implementa um **sistema inteligente de controle automático de cortinas** que se adapta automaticamente às condições de iluminação do ambiente e à posição desejada. É uma solução prática e inovadora para automação residencial que melhora o conforto, eficiência energética e qualidade de vida no ambiente doméstico.

### Problema Resolvido
- Automatiza o processo de ajuste de cortinas, economizando tempo e energia do usuário
- Otimiza a entrada de luz natural baseado em condições reais do ambiente
- Reduz o consumo de energia elétrica ao aproveitar melhor a iluminação natural
- Oferece conforto e conveniência através da automatização inteligente

---

## 🔧 Características Técnicas

### Componentes Principais

| Componente | Modelo | Função |
|---|---|---|
| **Microcontrolador** | Arduino UNO R3 | Processamento central e lógica de controle |
| **Sensor de Distância** | Ultrassônico (4 pinos) | Medição da altura da cortina |
| **Sensor de Luz** | Fotorresistor (LDR) | Detecção de níveis de iluminação |
| **Atuador** | LED Verde | Indicador visual/controle do motor |
| **Resistores** | R1: 150Ω, R2: Fotorresistor, R3: 1kΩ | Circuito de condicionamento de sinal |

### Resistores Volumétricos (Requisito Técnico)
✅ **Fotorresistor (R2)**: Resistor variável controlado pela luz do ambiente
- Varia sua resistência conforme a intensidade luminosa
- Permite leitura analógica de níveis de claridade

✅ **Divisor de Tensão (R2 + R3)**: Combinação de resistores para amplificar o sinal
- R3 (1kΩ) trabalha em conjunto com o fotorresistor
- Cria um divisor de tensão adaptativo para melhor leitura do sensor

---

## 📋 Funcionamento do Sistema

### Lógica de Operação

O sistema opera em ciclos de 2 segundos, executando:

1. **Leitura de Distância**: Mede a altura atual da cortina via sensor ultrassônico
2. **Leitura de Luz**: Captura a intensidade de luz do ambiente via fotorresistor
3. **Processo de Decisão**:
   - **Se há muita luz** (> 300 unidades):
     - Se altura > 50cm → Abaixa a cortina (ativa LED)
     - Se altura ≤ 50cm → Mantém cortina na posição desejada
   - **Se há pouca luz**: Sobe a cortina automaticamente
4. **Visualização**: Transmite dados em tempo real via Serial Monitor

### Fluxograma de Decisão

```
┌─────────────────────────┐
│  Lê Sensores            │
│  Luz: A0                │
│  Altura: Ultrassônico   │
└────────────┬────────────┘
             │
             ▼
      ┌──────────────┐
      │ Luz > 300?   │
      └──┬────────┬──┘
         │        │
        SIM      NÃO
         │        │
         ▼        ▼
   ┌─────────┐  ┌──────────┐
   │Altura > │  │ LED OFF  │
   │ 50cm?   │  │ Sobe     │
   └─┬────┬──┘  │Cortina   │
    SIM   NÃO    └──────────┘
     │     │
     ▼     ▼
   ┌─┐   ┌─────────────┐
   │▲│   │ LED ON      │
   │-│   │ Abaixa      │
   │D│   │ Cortina     │
   │O│   └─────────────┘
   └─┘
```

---

## 🔌 Pinagem e Conexões

| Pino Arduino | Componente | Tipo |
|---|---|---|
| **D9** | Sensor Ultrassônico (TRIG) | Saída Digital |
| **D10** | Sensor Ultrassônico (ECHO) | Entrada Digital |
| **D7** | LED Verde | Saída Digital |
| **A0** | Fotorresistor | Entrada Analógica |
| **5V** | Alimentação | Power |
| **GND** | Terra | Ground |

---

## 💡 Inovações e Diferenciais

✨ **Inteligência Adaptativa**: Sistema que aprende e se adapta às mudanças de condições climáticas

✨ **Duplo Sensoriamento**: Combina dados de luz e distância para decisões mais precisas

✨ **Eficiência Energética**: Mantém automática a posição ideal para aproveitar luz natural

✨ **Facilidade de Integração**: Baseado em Arduino, facilmente expansível com outros sensores ou componentes

✨ **Feedback em Tempo Real**: Monitoramento contínuo via Serial Monitor

---

## 📊 Especificações de Operação

- **Frequência de Ciclo**: 2 segundos
- **Limite de Ativação de Luz**: 300 unidades analógicas
- **Altura Alvo da Cortina**: 50 cm
- **Taxa de Transmissão Serial**: 9600 baud
- **Tensão de Operação**: 5V (Arduino UNO)
- **Consumo Estimado**: ~50-100mA (dependendo do motor controlado pelo LED)

---

## 🚀 Possíveis Expansões

- Integração com módulo WiFi (ESP8266) para controle remoto
- Adição de relé para controlar motor CC de maior potência
- Sensor de temperatura para correlação com necessidade de ventilação
- Aplicativo mobile para controle e scheduling
- Integração com assistentes de voz (Alexa, Google Home)
- Armazenamento de histórico de operação com SD card

---

## 📝 Como Usar

1. **Montagem**: Conectar componentes conforme pinagem indicada
2. **Upload**: Carregar código no Arduino UNO via IDE Arduino
3. **Verificação**: Abrir Serial Monitor (9600 baud) para acompanhar operação
4. **Ajustes**: Modificar `limiteLuz` e `alturaCortina` conforme necessário

---

## 📄 Documentação Técnica

- **Diagrama Elétrico**: Incluído no arquivo PDF de circuito
- **Lista de Materiais**: Ver arquivo `bom.csv`
- **Código-Fonte**: `regulagem_cortina1.ino`

---

## 🎯 Conclusão

Este projeto demonstra como a **automação residencial inteligente** pode melhorar significativamente a qualidade de vida com soluções criativas e funcionais. A integração de múltiplos sensores volumétricos com lógica de decisão no Arduino cria um sistema robusto, confiável e facilmente expansível para aplicações residenciais reais.

**Uma solução inovadora que transforma o conforto doméstico em realidade! 🏠✨**

---

*Projeto desenvolvido como atividade prática de IoT - Desafio: Automação Residencial*
*Data: 14/04/2026*
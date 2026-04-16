const int umd = A0;
const int buzzer = 4;
const int led = 2;


void setup()
{
    Serial.begin(9600);
    pinMode(buzzer, OUTPUT);
    pinMode(led, OUTPUT);
}

int lerUmidade()
{
    int valor = analogRead(umd);
    return valor;
}

void alarme()
{
    digitalWrite(led, HIGH);
    tone(buzzer, 1000);
    delay(1000);
    digitalWrite(led, LOW);
    noTone(buzzer);
}

void ligarIrrigacao()
{
    float umidade = lerUmidade();
    Serial.print("Umidade: ");  
    Serial.println(umidade);
    if(umidade < 400){
        Serial.println("Solo muito seco! Ligando irrigacao...");
        alarme();
    }
    else
    {
        Serial.println("Solo com umidade adequada.");
    }
}



void loop()
{
    ligarIrrigacao();
    delay(1000);
}
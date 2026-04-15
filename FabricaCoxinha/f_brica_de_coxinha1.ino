//fábrica de cozinha ou bolo
const int trig = 10;
const int echo = 11;
const int led = 7;
const int buzzer = 9;

void setup()
{
    Serial.begin(9600);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);
}

float tamanhoCoxinha()
{
  float duracao, tamanho;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duracao = pulseIn(echo, HIGH);
  tamanho = (duracao * 0.034) / 2;
  return tamanho;
}

void alarme()
{
  digitalWrite(led, HIGH);
  tone(buzzer, 1000);
  delay(1000);
  digitalWrite(led, LOW);
  noTone(buzzer);
}

void alerta()
{
  float tamanho = tamanhoCoxinha();
  Serial.print("Tamanho: ");
  Serial.print(tamanho);
  Serial.println(" cm");
  
  if (tamanho > 20) {
    alarme();
    digitalWrite(led, HIGH);
    Serial.println("Coxinha excedeu o tamanho permitido! Desperdicio de massa");
  }
  else if (tamanho < 10) {
    alarme();
    digitalWrite(led, HIGH);
    Serial.println("Coxinha muito pequena! Desperdicio de massa");
  }
  else {
    digitalWrite(led, LOW);
    Serial.println("Coxinha dentro do tamanho permitido.");
  }
}


void loop()
{
    alerta();
    delay(2000); 
}
//fábrica de coxinha
const int temp = A0;
const int led = 7;
const int buzzer = 9;

void setup()
{
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);
}

float lerTemperatura()
{
  int valorAnalogico = analogRead(temp);
  
  float tensao = valorAnalogico * (5.0 / 1023.0);
  
  float temperatura = tensao * 100;

  return temperatura;
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
  float temperatura = lerTemperatura();
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" graus Celcius");
  
  if (temperatura > 180) {
    alarme();
    digitalWrite(led, HIGH);
    Serial.println("Temperatura muito alta! Risco de queimar a coxinha");
  }
  else if (temperatura < 150) {
    alarme();
    digitalWrite(led, HIGH);
    Serial.println("Temperatura muito baixa! Coxinha nao frita direito");
  }
  else {
    digitalWrite(led, LOW);
    Serial.println("Temperatura ideal para o forno");
  }
}


void loop()
{
    alerta();
    delay(2000); 
}
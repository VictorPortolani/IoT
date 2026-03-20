int ledG = 3;
int ledR = 4;
int ledY = 5;
int itr = 7;
  
void setup()
{
  pinMode(ledR,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(itr, INPUT);
  Serial.begin(9600);
}

void piscaLuzes()
{
	digitalWrite(ledR, HIGH);
    delay(500); //delay é em milisegundos
    digitalWrite(ledR,LOW);
    delay(500);
    digitalWrite(ledY, HIGH);
    delay(500); //delay é em milisegundos
    digitalWrite(ledY,LOW);
    delay(500);
    digitalWrite(ledG, HIGH);
    delay(500); //delay é em milisegundos
    digitalWrite(ledG,LOW);
    delay(500);
}

void piscaLuzesInverso()
{
  digitalWrite(ledG, HIGH);
    delay(500); //delay é em milisegundos
    digitalWrite(ledG,LOW);
    delay(500);
    digitalWrite(ledY, HIGH);
    delay(500); //delay é em milisegundos
    digitalWrite(ledY,LOW);
    delay(500);
    digitalWrite(ledR, HIGH);
    delay(500); 
    digitalWrite(ledR,LOW);
    delay(500);
}
void direitaEsquerda(bool slide)
{ 
    if(slide == 1)
    {
      piscaLuzes();
    }
  	else
    {
      piscaLuzesInverso();
    }
  
  	Serial.println(slide);
}

void loop()
{
  direitaEsquerda(digitalRead(itr));
}
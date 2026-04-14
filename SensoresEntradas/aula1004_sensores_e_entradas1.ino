const int g1 = 12;
const int r1 = 11; //echo
const int sig = 7;

void setup()
{
	Serial.begin(9600);
  	pinMode(g1, OUTPUT);
  	pinMode(r1, INPUT);
  	pinMode(sig, OUTPUT);
}

void distanciaAnalog(){
  long d1 = 0;
  float medicao = 0;
  
  digitalWrite(g1, LOW);
  delayMicroseconds(2);
  digitalWrite(g1, HIGH);
  delayMicroseconds(10);
  digitalWrite(g1,LOW);
  
  d1 = pulseIn(r1, HIGH);
  medicao = (d1 * 0.034 / 2);
  
  Serial.print("Distancia: Analogica - ");
  Serial.println(medicao);
}

void distanciaDigital(){
  long d2 = 0;
  float distancia = 0;
  
  digitalWrite(sig,HIGH);
  delayMicroseconds(2);
  digitalWrite(sig,LOW);
  delayMicroseconds(5);
  digitalWrite(sig,HIGH);
  
  pinMode(sig, INPUT);
  d2 = pulseIn(sig, HIGH);
  distancia = (d2 * 0.034 / 2);
  
  Serial.print("Distancia: Digital - ");
  Serial.println(distancia);
  
  pinMode(sig,OUTPUT);
}

void loop()
{
  distanciaAnalog();
  delay(500);
  distanciaDigital();
  delay(500);
}
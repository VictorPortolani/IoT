// Notas (frequências básicas)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

const int buzzer = 9;
int limitarLuz = 600;

void setup()
{
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void playNote(int note, int duration) {
  tone(buzzer, note, duration);
  delay(duration * 1.3);
}

void musicBoateAzul() {
  // Trecho simplificado da melodia

  playNote(NOTE_E4, 400);
  playNote(NOTE_G4, 400);
  playNote(NOTE_A4, 600);
  playNote(NOTE_G4, 400);

  playNote(NOTE_E4, 400);
  playNote(NOTE_D4, 400);
  playNote(NOTE_C4, 600);

  playNote(NOTE_E4, 400);
  playNote(NOTE_G4, 400);
  playNote(NOTE_A4, 600);
  playNote(NOTE_G4, 400);

  playNote(NOTE_E4, 400);
  playNote(NOTE_D4, 400);
  playNote(NOTE_C4, 800);

  delay(1000); // pausa
}

int lerPotenciometro(){
  Serial.println(analogRead(A0));
  delay(1000);
  return analogRead(A0);
}

int lerFotosensor(){
  Serial.println(analogRead(A1));
  delay(1000); //armazenado em milisegundos
  return analogRead(A1);
}

void musicBuzzer(){
  tone(buzzer, 100, 1000);
  delay(500);
  tone(buzzer, 250, 1000);
  delay(500);
  tone(buzzer, 500, 1000);
  delay(500);
  tone(buzzer, 700, 1000);
  delay(500);
  tone(buzzer, 800, 1000);
  delay(500);
  tone(buzzer, 1000, 1000);
  delay(500);
}

void baixarCortinas() {
  if (lerFotosensor() >= 500 && lerPotenciometro() > 0){
  	musicBuzzer();
    Serial.println("Não funcionou o sistema automático.");
  }else{
  	Serial.println("Sistema OK");
  }
  
}
  
void loop()
{
	baixarCortinas();
  	//musicBoateAzul();
}
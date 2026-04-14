int trig = 9;
int echo = 10;
int led = 7;
const int limiteLuz = 300;
int alturaCortina = 50;
float duracao, distancia;

void setup(){
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

float medirAltura(){
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    duracao = pulseIn(echo, HIGH);
    distancia = duracao * 0.034 / 2;

    return distancia;
}

int lerLuz(){
    int valorLuz = analogRead(A0);
    return valorLuz; 
}


void gerenciarCortina(int luz, int altura){
    if(luz > limiteLuz){
        if(altura > alturaCortina){
            digitalWrite(led, HIGH); 
            Serial.println("Abaixar cortina");
        } else {
            digitalWrite(led, LOW); 
            Serial.println("Cortina na altura desejada.");
        }
    } else {
        digitalWrite(led, LOW); 
        Serial.println("Subir cortina"); 
    }
}


void exibirLogs(int luz, int altura){
    Serial.print("Luz: ");
    Serial.print(luz);
    Serial.print(" | Altura da Cortina: ");
    Serial.println(altura);
}

void loop(){
    int altura = medirAltura();
    int luz = lerLuz();
    gerenciarCortina(luz, altura);
    exibirLogs(luz, altura);
    delay(2000);
}
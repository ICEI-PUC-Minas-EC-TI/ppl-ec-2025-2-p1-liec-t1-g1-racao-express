#include <ESP32Servo.h>
#include <BluetoothSerial.h>
#define soundSpeed 0.034
#define segundos(x) (x*1000)

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
Servo servo;
const int pinServo = 12;
const int aberto = 45; //Angulo aberto
const int fechado = 0; //Angulo fechado

/*-------------------------------
    SENSOR Ultrasonico 4 PINOS
-------------------------------*/
const int trigPin = 25;
const int echoPin = 26;
long duracao;
float distanciaCm;
unsigned long tempoInicial = 0;
const long espera = segundos(6); //<--- Alterar para cooldown desejado do atuador

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Racao Express - BT");
  servo.attach(pinServo);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.write(fechado);
  Serial.println("Conecte-se ao Bluetooth: \"Racao Express - BT\"");
}

void loop() {
  if(SerialBT.available() > 0){
    int op = (int)SerialBT.read();
    if(op == 1){
      servo.write(aberto);
    }
    else if(op == 0){
      servo.write(fechado);
    }
  }

  //Para sensor Ultrasonico
  unsigned long tempoAtual = millis();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duracao = pulseIn(echoPin, HIGH);
  distanciaCm = duracao * soundSpeed/2;

  if(distanciaCm < 15){
    if(tempoAtual - tempoInicial >= espera){
      tempoInicial = tempoAtual;
      servo.write(aberto);
      delay(1250);
      servo.write(fechado);
    }
  }
  delay(100);
}
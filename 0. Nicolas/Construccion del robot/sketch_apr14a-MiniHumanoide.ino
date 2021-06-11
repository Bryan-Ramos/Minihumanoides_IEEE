#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°
char c;
int vel=1000;
void setup() {
  servos.begin();  
  Serial.begin(9600);
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
  //abrir y adelante +
    setServo(0,90); //rodilla 1 | 0 +
    setServo(1,90); //pierna sagital 1  | 180 +
    setServo(2,110); //pierna frontal 1 | 180 +
    setServo(3,100); //hombro frontal 1 | 180 +
    setServo(4,100); //hombro sagital 1 | 180 +
    setServo(5,100); //codo 1 | 180 +
    
    setServo(6,90); //rodilla 2 | 180 +
    setServo(7,90); //pierna sagital 2  | 0 +
    setServo(8,100);//pierna frontal 2 | 0 +
    setServo(9,100); //hombro frontal 2 | 0 +
    setServo(10,90); //hombro sagital 2 | 0 +
    setServo(11,100); //codo 2 | 0 +
}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  
}

void loop() {
  if(Serial.available())
  {
    //c = Serial.parseInt();
    c= Serial.read();
    //Serial.println(c);
      
//    if(c!=0){
//      setServo(4,c);
//    }
  }
  if(c=='a'){
    avanzar();
  }
  if(c=='b'){
    detener();
  }
}
void avanzar(){
//step 1
    setServo(0,120); //rodilla 1 | 0 + flexionado
    setServo(1,110); //pierna sagital 1  | 180 +

    setServo(6,60); //rodilla 2 | 180 + flexionado
    setServo(7,110); //pierna sagital 2  | 0 +
delay(vel);    
//step 2
    setServo(0,90); //rodilla 1 | 0 + recta
    setServo(1,90); //pierna sagital 1  | 180 +

    setServo(6,60); //rodilla 2 | 180 + flexionado
    setServo(7,90); //pierna sagital 2  | 0 +
delay(vel); 
//step 3
    setServo(0,120); //rodilla 1 | 0 + flexionado
    setServo(1,70); //pierna sagital 1  | 180 +

    setServo(6,60); //rodilla 2 | 180 + flexionado
    setServo(7,70); //pierna sagital 2  | 0 +    
delay(vel); 
//step 4
    setServo(0,60); //rodilla 1 | 0 + flexionado
    setServo(1,90); //pierna sagital 1  | 180 +

    setServo(6,90); //rodilla 2 | 180 + recto
    setServo(7,90); //pierna sagital 2  | 0 + 
delay(vel);   
}
void detener(){
    setServo(0,90); //rodilla 1 | 0 +
    setServo(1,90); //pierna sagital 1  | 180 +
    setServo(2,110); //pierna frontal 1 | 180 +
    setServo(3,100); //hombro frontal 1 | 180 +
    setServo(4,100); //hombro sagital 1 | 180 +
    setServo(5,100); //codo 1 | 180 +
    
    setServo(6,90); //rodilla 2 | 180 +
    setServo(7,90); //pierna sagital 2  | 0 +
    setServo(8,100);//pierna frontal 2 | 0 +
    setServo(9,100); //hombro frontal 2 | 0 +
    setServo(10,90); //hombro sagital 2 | 0 +
    setServo(11,100); //codo 2 | 0 +
}

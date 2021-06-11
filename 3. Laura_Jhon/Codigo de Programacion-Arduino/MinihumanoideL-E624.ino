#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°
char c;
int vel=1000;
int pos = 0;
int pos1 = 0;
int pos2 = 0;

int p0 = 0;
int p1 = 0;
int p2 = 0;
int p3 = 0;
int p4 = 0;
int p5 = 0;

int p6 = 0;
int p7 = 0;
int p8 = 0;
int p9 = 0;
int p10 = 0;
int p11 = 0;
void setup() {
  servos.begin();  
  Serial.begin(9600);
  servos.setPWMFreq(50); //Frecuecia PWM de 60Hz o T=16,66ms
  //abrir y adelante +
    setServo(0,90); //rodilla 1 | 0 +
    setServo(1,90); //pierna sagital 1  | 180 +
    setServo(2,90); //pierna frontal 1 | 180 +
    setServo(3,90); //hombro frontal 1 | 180 +
    setServo(4,90); //hombro sagital 1 | 180 +
    setServo(5,90); //codo 1 | 180 +
    
    setServo(6,90); //rodilla 2 | 180 +
    setServo(7,90); //pierna sagital 2  | 0 +
    setServo(8,90);//pierna frontal 2 | 0 +
    setServo(9,90); //hombro frontal 2 | 0 +
    setServo(10,90); //hombro sagital 2 | 0 +
    setServo(11,90); //codo 2 | 0 +
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
  if(c=='r'){
    recoger();
  }
  if(c=='t'){
    tomar();
  }
}
void avanzar(){
//step 1

    setServo(0,90); //pierna sagital 1  | 180 +
    setServo(1,90); //pierna sagital 1  | 180 +
    setServo(3,90); //hombro frontal 1 | 180 +
    setServo(4,90); //hombro sagital 1 | 180 +
  for (pos = 90; pos <= 110; pos += 1) { 
    setServo(2,pos);
    setServo(5,pos);              
    delay(15);                      
  }
delay(vel);  

 
}
void detener(){
    setServo(0,90); //rodilla 1 | 0 +
    setServo(1,90); //pierna sagital 1  | 180 +
    setServo(2,90); //pierna frontal 1 | 180 +
    setServo(3,90); //hombro frontal 1 | 180 +
    setServo(4,90); //hombro sagital 1 | 180 +
    setServo(5,90); //codo 1 | 180 +
    
    setServo(6,90); //rodilla 2 | 180 +
    setServo(7,90); //pierna sagital 2  | 0 +
    setServo(8,90);//pierna frontal 2 | 0 +
    setServo(9,90); //hombro frontal 2 | 0 +
    setServo(10,90); //hombro sagital 2 | 0 +
    setServo(11,90); //codo 2 | 0 +
}
void recoger(){
//step 1


    setServo(2,90); //pierna sagital 1  | 180 +

    setServo(5,90); //hombro sagital 1 | 180 +
  for (pos1 = 0; pos1 <= 90; pos1 += 1) { 
    p0=90+pos1;
    p3=90-pos1;
    setServo(0,p0);
    setServo(3,p3);
  if (pos1 <= 45){
    p1=90-pos1;
    p4=90+pos1;
    setServo(1,p1);
    setServo(4,p4);
  }              
    delay(15);                      
  }
delay(vel);  

//step 2


    setServo(2,90); //pierna sagital 1  | 180 +

    setServo(5,90); //hombro sagital 1 | 180 +
  for (pos1 = 0; pos1 <= 90; pos1 += 1) { 

    setServo(0,p0-pos1);
    setServo(3,p3+pos1);
  
  if (pos1 <= 45){
    setServo(1,p1+pos1);
    setServo(4,p4-pos1);
  }              
    delay(15);                      
  }
delay(vel);
 
}

void tomar(){
//step 1


  for (pos2 = 0; pos2 <= 90; pos2 += 1) { 
    if (pos2 <=90){ //los servos que giran 45 grados ROTACION DE hombros
      p6=90-pos2;
      p9=90+pos2;
      setServo(6,p6);
      setServo(9,p9);
    }
    if (pos2 <= 30){ //hombrodd
      p10=90+pos2;
      p7=90-pos2;
      setServo(10,p10);
      setServo(7,p7);
    }       
    if (pos2 <= 20){ //CODOS
      p11=90+pos2;
      p8=90-pos2;
      setServo(11,p11);
      setServo(8,p8);
    }        
    delay(15);                      
  }
delay(vel);  
 
}

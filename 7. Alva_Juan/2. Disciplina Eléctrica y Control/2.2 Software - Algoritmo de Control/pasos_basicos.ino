#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver();

int pos0 = 172;
int pos180 = 565;
char c;

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
int p12 = 0;
int p13 = 0;
//int p13' = 0;
int p14 = 0;
int p15 = 0;

void initial_position() {
  setServo(4, 80);
  setServo(5, 95);
  
  setServo(7, 30);
  setServo(8, 90);
  
  setServo(10, 125);
  setServo(12, 110);
  setServo(14, 85 );
  
  setServo(11, 60);
  setServo(13, 60);
  setServo(15, 90);
}

void setup() {
  Serial.begin(9600);
  servos.begin();
  servos.setPWMFreq(60);
    
  delay(3000);
  initial_position();
  delay(3000);
}

void setServo(uint8_t n_servo, int angle) {
  int duty;
  duty = map(angle, 0, 180, pos0, pos180);
  servos.setPWM(n_servo, 0, duty);
    
}

void loop() {
  if(Serial.available())
  {
    c = Serial.read();
  }
  if(c =='q'){
    paso1_q();
  }
  if(c=='w'){
    paso2_w();
  }
  if(c=='s'){
    detener();
  }
  if(c=='e'){
    paso3_e();
  }
  if(c=='r'){
    paso4_r();
  }
  if(c=='t'){
    paso5_t();
  }
  if(c=='y'){
    paso6_y();
  }
  if(c=='u'){
    paso7_u();
  }
}
void paso1_q() {
  for (int i = 0; i <= 60; i++){
    if (i <= 30){
      p10 = 125+i;
      p11 = 60+i;
      p14 = 85-i;
      p15 = 90-i;
      setServo(10, p10);
      setServo(11, p11);
      setServo(14, p14);
      setServo(15, p15);
    }
    if (30 <= i){
      p13 = 90-i;
      setServo(13, p13);
    }
    Serial.print('\n');
    Serial.print("p10:  ");Serial.println(p10);
    Serial.print("p12:  ");Serial.println(p12);
    Serial.print("p14:  ");Serial.println(p14);
    Serial.print('\n');
    Serial.print("p11:  ");Serial.println(p11);
    Serial.print("p13:  ");Serial.println(p13);
    Serial.print("p15:  ");Serial.println(p15);
    Serial.print("---------");
    delay(15);
    
  }
}

void paso2_w() {
  for (int i = 0; i <= 60; i++){
    if (i <= 30){
      p11 = 90-i;
      p13 = 30-i;
      p15 = 60+i;
      setServo(11, p11);
      setServo(13, p13);
      setServo(15, p15);
    }
    if (30 <= i){
      p10 = 185-i;
      p11 = 90-i;
      p14 = 25+i;
      p15 = 60+i;
      setServo(10, p10);
      setServo(11, p11);
      setServo(14, p14);
      setServo(15, p15);
    }
    Serial.print('\n');
    Serial.print("p10:  ");Serial.println(p10);
    Serial.print("p12:  ");Serial.println(p12);
    Serial.print("p14:  ");Serial.println(p14);
    Serial.print('\n');
    Serial.print("p11:  ");Serial.println(p11);
    Serial.print("p13:  ");Serial.println(p13);
    Serial.print("p15:  ");Serial.println(p15);
    Serial.print("---------");
    delay(15);
  }
}

void paso3_e() {
  for (int i = 0; i <= 60; i++){
    if (i <= 30){
      p10 = 125-i;
      //p11 = 30-i;
      p12 = 110-i;
      p13 = 0+i;
      p14 = 85+i;
      p15 = 120-i;
      setServo(10, p10);
      setServo(11, p11);
      setServo(12, p12);
      setServo(13, p13);
      setServo(14, p14);
      setServo(15, p15);
    }
    if (30 <= i){
      //p10 = 125-i;
      p12 = 50+i;
      p13 = 0+i;
      p15 = 60+i;      
      //p14 = 85+i;
      setServo(10, p10);
      setServo(12, p12);
      //setServo(14, p14);
      setServo(13, p13);
      setServo(15, p15);
    }
    Serial.print('\n');
    Serial.print("p10:  ");Serial.println(p10);
    Serial.print("p12:  ");Serial.println(p12);
    Serial.print("p14:  ");Serial.println(p14);
    Serial.print('\n');
    Serial.print("p11:  ");Serial.println(p11);
    Serial.print("p13:  ");Serial.println(p13);
    Serial.print("p15:  ");Serial.println(p15);
    Serial.print("---------");
    delay(15);
  }
}
void paso4_r() {
  for (int i = 0; i <= 30; i++){
    if (i <= 30){
      //p10 = 50+i;
      //p11 = 0+i;
      p12 = 110+i;
      //p12 = 150-i;
      //p13 = 30+i;
      //p14 = 85-i;
      //p15 = 90+i;
      setServo(11, p11);
      setServo(12, p12);
      setServo(13, p13);
      setServo(14, p14);
      setServo(15, p15);
    }
    if (i >= 30){
      //p11 = 0+i;
      //p14 = 85-i;
      //p12 = 50+i;
      //p13 = 0+i;
      //p14 = 145-i;
      setServo(11, p11);
      setServo(12, p12);
      setServo(13, p13);
      setServo(14, p14);
    }
    Serial.print('\n');
    Serial.print("p10:  ");Serial.println(p10);
    Serial.print("p12:  ");Serial.println(p12);
    Serial.print("p14:  ");Serial.println(p14);
    Serial.print('\n');
    Serial.print("p11:  ");Serial.println(p11);
    Serial.print("p13:  ");Serial.println(p13);
    Serial.print("p15:  ");Serial.println(p15);
    Serial.print("---------");
    delay(15);
  }
}
void paso5_t() {
  for (int i = 0; i <= 60; i++){
    if (i <= 30){
      p10 = 95+i;
      p12 = 140+i;
      p14 = 115-i;
      setServo(10, p10);
      setServo(12, p12);
      setServo(14, p14);
    }
    if (30 <= i){
      p11 = 0+i;
      p10 = 95+i;
      p15 = 150-i;
      p14 = 115-i;
      setServo(10, p10);
      setServo(11, p11);
      setServo(14, p14);
      setServo(15, p15);
    }
    Serial.print('\n');
    Serial.print("p10:  ");Serial.println(p10);
    Serial.print("p12:  ");Serial.println(p12);
    Serial.print("p14:  ");Serial.println(p14);
    Serial.print('\n');
    Serial.print("p11:  ");Serial.println(p11);
    Serial.print("p13:  ");Serial.println(p13);
    Serial.print("p15:  ");Serial.println(p15);
    Serial.print("---------");
    delay(15);
  }
}
void paso6_y() {
  for (int i = 0; i <= 60; i++){
    if (i <= 30){
      //p10 = 155-i;
      //p11 = 0+i;
      //p12 = 170-i;
      //p12 = 150-i;
      //p13 = 30+i;
      p14 = 55+i;
      //p15 = 90-i;
      setServo(10, p10);
      setServo(11, p11);
      setServo(12, p12);
      setServo(13, p13);
      setServo(14, p14);
      //setServo(15, p15);
    }
    if (i >= 30){
      p10 = 185-i;
      //p14 = 55-i;
      p12 = 170-i;
      //p12 = 210-i;
      //p13 = 0+i;
      //p15 = 30+i;
      setServo(10, p10);
      setServo(11, p11);
      setServo(12, p12);
      setServo(13, p13);
      setServo(14, p14);
    }
    Serial.print('\n');
    Serial.print("p10:  ");Serial.println(p10);
    Serial.print("p12:  ");Serial.println(p12);
    Serial.print("p14:  ");Serial.println(p14);
    Serial.print('\n');
    Serial.print("p11:  ");Serial.println(p11);
    Serial.print("p13:  ");Serial.println(p13);
    Serial.print("p15:  ");Serial.println(p15);
    Serial.print("---------");
    delay(15);
  }
}
void paso7_u() {
  for (int i = 0; i <= 60; i++){
    if (i <= 30){
      p10 = 155-i;
      //p11 = 0+i;
      p12 = 140-i;
      //p12 = 150-i;
      //p13 = 30+i;
      //p14 = 115-i;
      //p15 = 60+i;
      setServo(10, p10);
      setServo(11, p11);
      setServo(12, p12);
      setServo(13, p13);
      setServo(14, p14);
      setServo(15, p15);
    }
    if (i >= 30){
      //p10 = 65+i;
      //p14 = 115+i;
      //p12 = 170-i;
      //p12 = 210-i;
      p14 = 25+i;
      //p15 = 150-i;
      setServo(10, p10);
      setServo(11, p11);
      setServo(12, p12);
      setServo(13, p13);
      setServo(14, p14);
      setServo(15, p15);
    }
    Serial.print('\n');
    Serial.print("p10:  ");Serial.println(p10);
    Serial.print("p12:  ");Serial.println(p12);
    Serial.print("p14:  ");Serial.println(p14);
    Serial.print('\n');
    Serial.print("p11:  ");Serial.println(p11);
    Serial.print("p13:  ");Serial.println(p13);
    Serial.print("p15:  ");Serial.println(p15);
    Serial.print("---------");
    delay(15);
  }
}
void detener() {
  initial_position();
  Serial.print('\n');
  Serial.print("p10:  ");Serial.println(p10);
  Serial.print("p12:  ");Serial.println(p12);
  Serial.print("p14:  ");Serial.println(p14);
  Serial.print('\n');
  Serial.print("p11:  ");Serial.println(p11);
  Serial.print("p13:  ");Serial.println(p13);
  Serial.print("p15:  ");Serial.println(p15);
  Serial.print("---------");
  delay(500); 
} 

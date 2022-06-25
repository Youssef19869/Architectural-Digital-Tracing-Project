#include "SoftwareSerial.h"
#include <Servo.h>

SoftwareSerial Bluetooth (0, 1); //RX TX
int val;
boolean state = 1;
float Dis = 0;
void Ldelay(float Dis);
void right();
void left();
void superright () ;  
void superleft () ;
void forwardright ();
void forwardleft (); 
void backright ();
void backleft () ;
void Drow_RECT(float Hight ,float Width );
void Drow_SCQ(float Dis);
void Drow_Cir(float Rid); 
Servo myservo;
int pos = 0;
void setup() {
  Serial.begin (9600);
  Bluetooth.begin(9600);
  myservo.attach(9);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
}
void loop() {
  if (Bluetooth.available()) {
    val = Bluetooth.read();
    if (val == 'W') {
      Drow_LINE (400);
    } else if (val == 'w') {
      Drow_TRIA (400);
    }
    if (val == 'B') {
      back();
    } else if (val == 'F') {
      forward();  
    } else if (val == 'R' && state == 1) {
      superright ();
    } else if (val == 'L' && state == 1) {
      superleft ();
    } //else if (val == 'R' && state == 0) {
      //right ();
    //} 
    //else if (val == 'L' && state == 0) {
      //left ();
    //} 
    else if (val == 'G') {
      forwardleft ();
    } else if (val == 'I') {
      forwardright ();
    } else if (val == 'H') {
      backright ();
    } else if (val == 'J') {
      backleft ();
    }  
    else if (val == 'V') {
      Drow_SCQ (400);
    }  
    else if (val == 'U') {
      Drow_RECT (400,200);
    }  
    else if (val == 'X') {
      Drow_Cir (500);
    }  
    else {
     Stop();
    }
  }
}void Stop(){
 
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
}
void forward() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(17, LOW);
  digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
}
void back() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, HIGH);
  digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
}
void right() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(16, LOW);
  digitalWrite(17, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
}

void left() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(16, HIGH);
  digitalWrite(17, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
}
void superright () {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
}
void superleft () {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(17, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
}

void forwardright () {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, LOW);
  digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
}

void forwardleft () {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(17, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
}

void backright () {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
}

void backleft () {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, HIGH);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
}
void Ldelay ( float Dis){
  float t = 0;
  t = Dis / 140  ;
  delay (((int)(t*1000)));
  Stop();
  delay(100);
  }
  void Drow_LINE(float Dis){
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }     
    forward();
   Ldelay(Dis); 
    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  } 
  }
  void Drow_TRIA(float Dis){
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }    
    forwardleft();
   Ldelay(Dis);
    forwardright();
   Ldelay(Dis);
    back();
   Ldelay(Dis);
    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  } 
  }
  void Drow_RECT(float Hight,float Width){
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }             
    forward();
   Ldelay(Hight); 
    superright();
   Ldelay(Width);
     back();
   Ldelay(Hight); 
      superleft();
   Ldelay(Width); 
   for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  } 
  }
  void Drow_SCQ(float Dis){
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    } 
    forward();
   Ldelay(Dis); 
    superright();
   Ldelay(Dis);
     back();
   Ldelay(Dis); 
      superleft();
   Ldelay(Dis); 
   for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  }
  void Drow_Cir(float Rid){
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    } 
    for(int i= 0 ;i<=20;i++){
       forward();
  Ldelay(Rid/20.0); 
    superleft();
   Ldelay(Rid/20.0);
    }
    for(int i= 0 ;i<=20;i++){
       forward();
  Ldelay(Rid/20.0); 
    superright();
   Ldelay(Rid/20.0);
    }
    for(int i= 0 ;i<=20;i++){
       back();
  Ldelay(Rid/20.0); 
    superright();
   Ldelay(Rid/20.0);
    }
    for(int i= 0 ;i<=20;i++){
       back();
  Ldelay(Rid/20.0); 
    superleft();
   Ldelay(Rid/20.0);
    }
    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }          
  }

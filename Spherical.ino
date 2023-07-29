#include <IRremote.hpp>
int irpin = 26;
int mot11 = 8, mot12 = 9, mot21 = 10, mot22 = 11;
int ena1 = 6, ena2 = 5;

IRrecv IR(irpin);
decode_results results;

void setup(){
  IR.enableIRIn();

  pinMode(mot11, OUTPUT);
  pinMode(mot12, OUTPUT);
  pinMode(mot21, OUTPUT);
  pinMode(mot22, OUTPUT);
  pinMode(ena1, OUTPUT);
  pinMode(ena2, OUTPUT);
  Serial.begin(9600);
}


void forward(){
  analogWrite(ena1, 120);
  analogWrite(ena2, 120);
  digitalWrite(mot11, HIGH);
  digitalWrite(mot12, LOW);
  digitalWrite(mot21, HIGH);
  digitalWrite(mot22, LOW);
}

void reverse(){
  analogWrite(ena1, 120);
  analogWrite(ena2, 120);
  digitalWrite(mot11, LOW);
  digitalWrite(mot12, HIGH);
  digitalWrite(mot21, LOW);
  digitalWrite(mot22, HIGH);
}

void left(){
  analogWrite(ena1, 100);
  analogWrite(ena2, 100);
  digitalWrite(mot11, HIGH);
  digitalWrite(mot12, LOW);
  digitalWrite(mot21, LOW);
  digitalWrite(mot22, HIGH);
}

void right(){
  analogWrite(ena1, 100);
  analogWrite(ena2, 100);
  digitalWrite(mot11, LOW);
  digitalWrite(mot12, HIGH);
  digitalWrite(mot21, HIGH);
  digitalWrite(mot22, LOW);
}

void stop(){
  analogWrite(ena1, 120);
  analogWrite(ena2, 120);
  digitalWrite(mot11, LOW);
  digitalWrite(mot12, LOW);
  digitalWrite(mot21, LOW);
  digitalWrite(mot22, LOW);
}

void loop(){
  if(IR.decode()){
    //movement
    if (IR.decodedIRData.decodedRawData == 0xE718FF00){
      forward();
    }
    else if (IR.decodedIRData.decodedRawData == 0xAD52FF00){
      reverse();
    }
    else if (IR.decodedIRData.decodedRawData == 0xF708FF00){
      left();
    }
    else if (IR.decodedIRData.decodedRawData == 0xA55AFF00){
      right();
    }
    else if (IR.decodedIRData.decodedRawData == 0xE31CFF00){
      stop();
    }
    else{
      stop();
    }
    IR.resume();
  }
}
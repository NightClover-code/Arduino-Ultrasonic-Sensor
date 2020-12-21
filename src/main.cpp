#include <Arduino.h>
//defining the pins
#define ledPin 2
#define buzzer 6
#define trigger 9
#define echo 10
//defining variables
long duration;
int distance;

void setup() {
  //initializing serial monitor
  Serial.begin(9600);
  //Pin Modes
  pinMode(ledPin, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  //clearing trigger pin
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  //setting trigger HIGH for 10 microseconds
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  //reading the duration
  duration = pulseIn(echo, HIGH);
  //calculating the distance
  distance = duration * 0.034/2;
  //conditional buzzing 
  if (distance <= 50){
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzer, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzer, LOW);
  }
}
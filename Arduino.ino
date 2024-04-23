#include <Servo.h>

const int trigPin = 10;
const int echoPin = 11;
const int laserPin = 6;
long duration;
int distance;

Servo ultrasonicServo;
Servo laserServo; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(laserPin, OUTPUT); 
  Serial.begin(9600);
  ultrasonicServo.attach(13); 
  laserServo.attach(4); 

void loop() {
  for (int i = 15; i <= 165; i++) {
    ultrasonicServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    
    if (distance < 50) { 
      activateLaser(i); 
    } else {
      deactivateLaser();
    }
  }
  
  for (int i = 165; i > 15; i--) {
    ultrasonicServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    
    if (distance < 50) {
      activateLaser(i); 
    } else {
      deactivateLaser(); 
    }
  }
}

int calculateDistance() { 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

void activateLaser(int angle) {
  laserServo.write(angle); 
  digitalWrite(laserPin, HIGH); 
}

void deactivateLaser() {
  digitalWrite(laserPin, LOW); 
}

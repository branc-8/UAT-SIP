#include <ESP32Servo.h>
#include <analogWrite.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>
#include <MusicDefinitions.h>
#include <XT_DAC_Audio.h>
#include "SoundData.h"
XT_Wav_Class Sound(rawData);                                          
XT_DAC_Audio_Class DacAudio(26,0); 
int sensorPin = 34;
int servoPin = 27;
int output_value;

Servo Servo1;
void setup() {
  Servo1.setPeriodHertz(50);
  Servo1.attach(servoPin);
  pinMode(sensorPin, INPUT);
  Serial.begin(115200);            
}
void loop() {  
//  Serial.print("Moisture: ");
//  Serial.print(analogRead(sensorPin));
//  Serial.println("%");
//  //muzak();
//  delay(1000);      
  if(analogRead(sensorPin)< 3000)
  {
    Serial.println("Watering");
    Serial.println(analogRead(sensorPin));
    stopperUp();
    muzak();
  } else {
    stopperDown();
    Serial.println(analogRead(sensorPin));
  }
}
void muzak(){
  DacAudio.FillBuffer();                
  if(Sound.Playing==false)       
    DacAudio.Play(&Sound); 
}

void stopperUp(){
  Servo1.write(180);
  
}
void stopperDown(){
  Servo1.write(90);
  
}

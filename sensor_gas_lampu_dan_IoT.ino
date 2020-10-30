#include <Arduino.h>

#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "48e7ce82199644a2ab92ab73cc195f5e";

char ssid[] = "emrizkis";
char pass[] = "rizki123";
int nilai = 0;

int batastoleransi = 98; //batas toleransi lingkungan 
void bahaya();
void setup() 
{ 
pinMode(A0, INPUT); 
pinMode(D6, OUTPUT);
pinMode(D1, OUTPUT);

Serial.begin(9600); //kecepatan transfer data 

Blynk.begin(auth, ssid, pass);
} 

void loop() 
{ 
int nilai = analogRead(A0); //membaca nilai di pin A5
Blynk.virtualWrite(V5, nilai); 
if (nilai > batastoleransi) 
{ Serial.println(nilai); 
  bahaya();
  Blynk.virtualWrite(V6, "Bahaya");
  Blynk.notify("Bahaya");
}
else 
{ 
Serial.println(nilai); 
digitalWrite(D6,HIGH);
Blynk.virtualWrite(V6, "Aman");
} 
delay(400); //program berjalan selama 400 milisecond 
Blynk.run();
}

void bahaya(){
 
    digitalWrite(D1, HIGH);
    digitalWrite(D6, HIGH);
    delay(5);
    digitalWrite(D1, LOW);
    digitalWrite(D6, LOW);
    delay(5);
    
}

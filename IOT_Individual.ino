#include "DHT.h"                              
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char authentication[] = "MRxiiFKu9AdWyQTsjFpGIHwa6paq0xH1";
char WiFi_ssid[] = "Kumar";
char password[] = "9860601754";

DHT dhtA(5, DHT22);                           // DHT instance named dhtA, D1 and sensor type

void setup() {
  Blynk.begin(authentication, WiFi_ssid, password);  // Connection with Blynk server
  Blynk.notify("Your System is ready to use.");
  dhtA.begin();                               // Beginning the DHT-22
}

void loop() {
  Blynk.run();
  temperature_Humidity_check();                           // Climate Check
  delay(5000);  
  byte h1 = dhtA.readHumidity();
  Serial.begin(115200);
  Serial.println(h1);
}

void temperature_Humidity_check() {

  
    byte h1 = dhtA.readHumidity();            // t1 and h1 are celsius and humidity readings
    byte t1 = dhtA.readTemperature();         // from DHT/A
    Blynk.virtualWrite(V0, t1);               // Virtual Pin 0 frequency to PUSH in Blynk
    Blynk.virtualWrite(V1, h1);               // Virtual Pin 1 frequency to PUSH in Blynk
    if ( t1 >= 20){
      Blynk.notify("The temperature is High.");
    }
    else{
      Blynk.notify("The temperature is Low.");
    }
   
}

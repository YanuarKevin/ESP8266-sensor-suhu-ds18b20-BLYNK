#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data pin untuk DS18B20
#define ONE_WIRE_BUS D4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Token Auth Blynk
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";

// Nama jaringan WiFi dan password
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  sensors.begin();
}

void loop()
{
  Blynk.run();
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);

  // Kirim data suhu ke Blynk Virtual Pin 1
  Blynk.virtualWrite(V1, temperatureC);
  delay(1000);
}

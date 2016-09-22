#include <DHT.h>

#define DHTPIN A1
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT TESTE: ");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(t) || isnan(h))
  {
    Serial.println("Falha ao ler sensor DHT11");
  }
  else
  {
    Serial.print("Humidade: ");
    Serial.print(h);
    Serial.print(" %  -  ");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
  }
  delay(5000);
}

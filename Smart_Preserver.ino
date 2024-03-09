#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define RELAYPIN 3

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, HIGH);
}

void loop() {
  float humidity = 0;
  float temperature = 0;

  dht.begin();
  delay(1000);
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  if (temperature > 28) {
    digitalWrite(RELAYPIN, LOW);
    Serial.println("Fan is ON");
  } else {
    digitalWrite(RELAYPIN, HIGH);
    Serial.println("Fan is OFF");
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("C, Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Fan Status: ");
  if (digitalRead(RELAYPIN) == LOW) {
    Serial.println("ON");
    // Turn on the DC motor
    digitalWrite(4, LOW);
  } else {
    Serial.println("OFF");
    // Turn off the DC motor
    digitalWrite(4, HIGH);
  }

  delay(2000);
}

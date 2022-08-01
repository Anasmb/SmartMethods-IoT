/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-mysql
 */
//© Copyright 2022 - Written By Anasmb
#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 14
#define DHTTYPE DHT11

const char ssid[] = "Velop 1";
const char password[] = "a1234567";

String HOST_NAME = "http://192.168.100.6"; // change to your PC's IP address
String PATH_NAME = "/sensor/insert_temp.php?";
// String queryString = "temperature=30&humidity=55";

byte connectingCounter = 0;

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);

  connectToWifi();

  dht.begin();
}

void loop()
{

  delay(60000); // send data every 60 sec

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  String strTemp = String(temperature, 2);
  String strHumid = String(humidity, 2);

  HTTPClient http;
  String server = HOST_NAME + PATH_NAME + "temperature=" + strTemp + "&humidity=" + strHumid;
  http.begin(server); // HTTP
  int httpCode = http.GET();

  if (httpCode > 0)
  {
    // file found at server
    if (httpCode == HTTP_CODE_OK)
    {
      String payload = http.getString();
      Serial.println(payload);
    }
    else
    {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    }
  }
  else
  {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();

  if (WiFi.status() != WL_CONNECTED)
  {
    connectToWifi();
  }
}

void connectToWifi()
{
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wifi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
    connectingCounter++;
    WiFi.begin(ssid, password);
    if (connectingCounter > 8)
    {
      connectingCounter = 0;
      Serial.println(F("Unable to connect to the Wifi"));
      Serial.println(F("Restarting ESP32"));
      ESP.restart();
    }
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}
//© Copyright 2022 - Written By Anasmb

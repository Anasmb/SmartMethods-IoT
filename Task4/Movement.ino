#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>

const char* ssid = "Velop 1";
const char* password = "a1234567";


const char* serverName = "http://192.168.100.6/sensors/getMovement.php"; // change to your PC's IP address

String movementReadings;
String movementReadingsArr[3];

byte connectingCounter = 0;

void setup() {
 Serial.begin(115200);

  connectToWifi();

}

void loop() {

  

  delay(10);  //READ DATA FROM THE SERVER EVERY 10 ms

  if(WiFi.status()== WL_CONNECTED){ //if we are still connected to wifi
    
     movementReadings = httpGETRequest(serverName);
      Serial.println(movementReadings);
      JSONVar myObject = JSON.parse(movementReadings);

      if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Parsing input failed!");
        return;
      }

      Serial.print("JSON object = ");
      Serial.println(myObject);
      JSONVar keys = myObject.keys();

      for (int i = 0; i < keys.length(); i++) {
        JSONVar value = myObject[keys[i]];
        Serial.print(keys[i]);
        Serial.print(" = ");
        Serial.println(value);
        movementReadingsArr[i] = value;
      }

     // Serial.print("1 = ");
      //Serial.println(movementReadingsArr[0]);

      if(movementReadingsArr[0]["Direction"].equals("forward")){ 
        //Proceed to move FORWARD
      }
      else if(movementReadingsArr[0]["Direction"].equals("backward")){ 
        //Proceed to move BACKWARD
      }
      else if(movementReadingsArr[0]["Direction"].equals("right")){ 
        //Proceed to turn RIGHT
      }
      else if(movementReadingsArr[0]["Direction"].equals("left")){ 
        //Proceed to turn LEFT
      }
    
    
    }
    else {
      Serial.println("WiFi Disconnected");
    }
}

String httpGETRequest(const char* serverName) {
  
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}


void connectToWifi(){
 WiFi.begin(ssid, password);
 Serial.print("Connecting to Wifi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
    connectingCounter++;
    WiFi.begin(ssid, password);
     if(connectingCounter > 8){
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

#include <WiFi.h>
 
const char* ssid = "Azamat";
const char* password =  "R00000000";
 
const uint16_t port = 8888;
const char * host = "192.168.31.40";
 
void setup()
{
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
 
}
 
void loop()
{
    WiFiClient client;
 
    if (!client.connect(host, port)) {
 
        Serial.println("Connection to host failed");
 
        delay(1000);
        return;
    }
 
    Serial.println("Connected to server successful!");
 
    client.print("Heloo i home");
 
    Serial.println("Disconnecting...");
    client.stop();
 
    delay(10000);
}

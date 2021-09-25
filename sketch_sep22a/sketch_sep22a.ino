#include <GParser.h>

#include <ESP8266WiFi.h>

#define STASSID "Azamat"
#define STAPSK  "R00000000"

WiFiServer server(9090);

const char* ssid     = STASSID;
const char* password = STAPSK;


void setup() {
  Serial.begin(115200);

  //WIFI settings
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();

}
/*
"0; 100; 100" -- for coords
"1; 90" -- for incline
"0" -- stop motors

*/
void loop() {
  WiFiClient client = server.available();
  if (client) {
    if (client.connected()) Serial.println("Client Connected");
    //stepper.tick();
    while (client.connected()) {
      while (client.available() > 0) {
        char str[150];
        //String line = client.readString();
        int amount = client.readBytesUntil(',', str, 150);
        str[amount] = NULL;

        int data[20]; //буфер интов
        int count = 0; //счётчик интов
        char* offset = str;
        while (true){
          data[count++] = atoi(offset);
          offset = strchr(offset, ';');
          if (offset) offset++;
          else break;
        }
        switch(data[0]){
          case 0: Serial.println(data[1]); break;
        }
        
      }
    }
  }
}



















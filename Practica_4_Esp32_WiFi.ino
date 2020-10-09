#include <WiFi.h>
const char* ssid     = "Totalplay-C09E";
const char* password = "C09E5F0Dy24QAN7J";

void setup() {
 Serial.begin(115200);     // set the LED pin mode
    delay(10);
    // We start by connecting to a WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}
void loop(){
  
  }

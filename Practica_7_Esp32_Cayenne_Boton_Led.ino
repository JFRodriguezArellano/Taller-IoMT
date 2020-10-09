#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP32.h>

// WiFi network info.
char ssid[] = "Totalplay-E7A2";
char wifiPassword[] = "E7A298C33Xqjrpfd";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "f0bd8f30-dd6d-11ea-883c-638d8ce4c23d";
char password[] = "16573bd35cc07594a2f16b36ef905f2656e31211";
char clientID[] = "3f228770-dd6e-11ea-a67f-15e30d90bbf4";
int led = 2;
String button_state;

void setup() {
  Serial.begin(9600);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  pinMode(led, OUTPUT);
}

void loop() {
  Cayenne.loop();
  
}

// Default function for sending sensor data at intervals to Cayenne.
// You can also use functions for specific channels, e.g CAYENNE_OUT(1) for sending channel 1 data.
CAYENNE_OUT_DEFAULT()
{
  // Write data to Cayenne here. This example just sends the current uptime in milliseconds on virtual channel 0.
  //Cayenne.virtualWrite(0, millis());
}
// Default function for processing actuator commands from the Cayenne Dashboard.
// You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
  CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
 //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
CAYENNE_IN(2)
{
  CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
  button_state = getValue.asString();
  if (button_state == "1"){
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
    }
 //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}

#include "ESPControl.h" // importing our library
int control = 0;
String path = "nothing";

void setup() {
  Serial.begin(9600);
  pinMode(D0, OUTPUT);
  start("wifi-ssid", "wifi-password");
}

void loop()
{
  if (CheckNewReq() == 1)
  {
    path = getPath();
    path.remove(0, 1);   //Remove slash /
    control = path.toInt();
    Serial.println(control);
    digitalWrite(D0, control);
  }
}

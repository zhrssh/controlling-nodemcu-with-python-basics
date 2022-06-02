#include "ESPControl.h"

#define SSID "wifi-ssid"
#define PASS "wifi-password"

const int leds[8] = { D7, D6, D5, D4, D3, D2, D1, D0 };
const int indicator = D8;

String path = "";

// commands
const unsigned char A = 0xF0; // 1111 0000
const unsigned char B = 0x0F; // 0000 1111
const unsigned char C = 0xAA; // 1010 1010
const unsigned char D = 0x55; // 0101 0101
const unsigned char mask = 0x80; // 1000 0000
bool isCommand = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // Leds
  pinMode(indicator, OUTPUT);
  for ( int i = 0; i < 8; i++ ) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[0], LOW);
  }

  // WiFi
  start(SSID, PASS);
  digitalWrite(indicator, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  if ( !isCommand )
  {
    blinkLeds();
  }
  
  // Received requests
  if ( CheckNewReq() == 1 )
  {
    path = getPath();
    path.remove(0, 1);
    path.toUpperCase();
    if (path == "A")
    {
      // lights all led depending on the hex
      unsigned char bits = A;
      for (int i = 0; i < 8; i++)
      {
        digitalWrite(leds[i], (bits & mask) ? HIGH : LOW);
        bits = bits << 1;
      }
    }
    else if (path == "B")
    {
      // lights all led depending on the hex
      unsigned char bits = B;
      for (int i = 0; i < 8; i++)
      {
        digitalWrite(leds[i], (bits & mask) ? HIGH : LOW);
        bits = bits << 1;
      }
    }
    else if (path == "C")
    {
      // lights all led depending on the hex
      unsigned char bits = C;
      for (int i = 0; i < 8; i++)
      {
        digitalWrite(leds[i], (bits & mask) ? HIGH : LOW);
        bits = bits << 1;
      }
    }
    else if (path == "D")
    {
      // lights all led depending on the hex
      unsigned char bits = D;
      for (int i = 0; i < 8; i++)
      {
        digitalWrite(leds[i], (bits & mask) ? HIGH : LOW);
        bits = bits << 1;
      }
    }
    else
    {
      // will trigger the blinking
      isCommand = false;
      return;
    }

    // if command is existing
    isCommand = true;
  }
}

void blinkLeds()
{
  // blink all the leds
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(leds[i], HIGH);
  }

  delay(1000);

  for (int i = 0; i < 8; i++)
  {
    digitalWrite(leds[i], LOW);
  }

  delay (1000);
}

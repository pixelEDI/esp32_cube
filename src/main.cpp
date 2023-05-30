/*
        _          _ ______ _____ _____
       (_)        | |  ____|  __ \_   _|
  _ __  ___  _____| | |__  | |  | || |
 | '_ \| \ \/ / _ \ |  __| | |  | || |
 | |_) | |>  <  __/ | |____| |__| || |_
 | .__/|_/_/\_\___|_|______|_____/_____|
 | |
 |_|

www.pixeledi.eu | https://linktr.ee/pixeledi
Bluetooth Cube with ESP32 | V1.0 | 05.2023

Sketch for bluetooth connection: https://github.com/playfultechnology/esp32-smartcube/blob/master/esp32-smartcube.ino

# find MAC from your Cube
# edit your MAC in "ble_rubikscube.h" line 11
# edit your crednetials wifi + mqtt
# partition scheme has to be changed because wifi + ble needs a lot of flash space

*/

#include <Arduino.h>
#include <Wire.h>
#include "globals.h"
#include "button.h"
#include "BLEDevice.h"
#include "ble_rubikscube.h"
#include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
#include <Adafruit_SH110X.h>
// fonts https://learn.adafruit.com/adafruit-gfx-graphics-library/using-fonts#step-2
#include <Fonts/FreeSerif9pt7b.h>
#include "oled.h"
#include "wifimqtt.h"

Button rndBTN(3);

void newRound()
{
  solved = false;
  moves = 0;
  startTime = 0;
  firstStart = false;
  // Serial.println("new Round started");
  showReady();
}

void isButtonClicked()
{

  switch (rndBTN.checkBTN())
  {
  case 1:
    newRound();
    break;
  case 2:
    // Serial.println("change user");
    if (user == 1)
      user = 2;
    else
      user = 1;
  };
}

void readBatteryVoltage()
{

  

  if (millis() - millisBattery > (1000 * 10))
  {
    millisBattery = millis();

    uint32_t Vbatt = 0;
    for (int i = 0; i < 16; i++)
    {
      Vbatt = Vbatt + analogReadMilliVolts(A0); // ADC with correction
    }
    // voltage divider actual with 2x 100kOhm to A0
    // results in Voltage / 2
    // get rid of the spikes ->for loop with 16 
    // calculate voltage
    Vbattf = 2 * Vbatt / 16 / 1000.0; 
    // Serial.println(Vbattf, 3);
  }
}

void setup()
{
  Serial.begin(115200);

  rndBTN.start();
  pinMode(A0, INPUT); // ADC

  display1.begin(0x3C, true);
  display1.clearDisplay();
  showloadingDuringConnection();

  connectAP();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callbackmqtt);

  // Serial.print("Initialising BLE...");
  BLEDevice::init("");
  delay(500);
  Serial.println("setup finished");
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  if (!client.loop())
    client.connect("ESP32Cube");

  isButtonClicked();
  readBatteryVoltage();

  // with first move the time starts
  if (!solved && startTime > 0)
  {
    solvingTime = (millis() - startTime);

    showOled();
  }

  if (solved)
  {
    // oled is changed from mqtt callback
  }

  if (deviceFound)
  {
    if (!connected)
    {
      connectToServer();
    }
  }
  else
  {
    scanForDevices();
  }
}
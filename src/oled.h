#ifndef oled_h
#define oled_h

#include <Arduino.h>
#include "globals.h"
#include "batterygrafic.h"

// wokwi test
// https://wokwi.com/projects/360630350868434945

String convertMillisToReadableTime(long milliseconds)
{
    unsigned long allSeconds = milliseconds / 1000;
    int secsRemaining = allSeconds % 3600;
    int runMinutes = secsRemaining / 60;
    int runSeconds = secsRemaining % 60;
    int runThousends = milliseconds % 1000;
    int runHundreds = (runThousends / 10);

    return String(runMinutes) + ":" + String(runSeconds) + "." + String(runHundreds);
}

float mapf(float x, float inmin, float inmax, float outmin, float outmax)
{
    float a = x - inmin;
    float b = outmax - outmin;
    float c = inmax - inmin;
    return a * b / c + outmin;
}

void showBatteryStatus()
{
    // clear and show will be done by other function
    // display1.setTextSize(1);
    // display1.setTextColor(SH110X_WHITE);
    // display1.setCursor(5, 5);
    // display1.print(Vbattf);
    
    // convert upper and lower LiPo Voltage threadshold in Percentage
    // refresh every 10 secds in radBatteryVoltage()
    float batteryleft = mapf(Vbattf, 3.3, 4.2, 0, 100);

    if (batteryleft >= 50.0)
        display1.drawBitmap(5, 50, bitmap_batteryfull, 20, 11, 1);
    else if (batteryleft > 10.0 && batteryleft < 49.9)
        display1.drawBitmap(5, 50, bitmap_batteryhaveFull, 20, 11, 1);
    else if (batteryleft <= 9.9)
        display1.drawBitmap(5, 50, bitmap_Battery_Status_10perc, 20, 11, 1);
    else
        display1.drawBitmap(5, 50, bitmap_batteryfull, 20, 11, 1);

}

void showOled()
{
    int16_t x1;
    int16_t y1;
    uint16_t width;
    uint16_t height;
    String txt = "";
    String countdownTXT = "";

    display1.clearDisplay();
    display1.setTextColor(SH110X_WHITE);
    display1.drawRect(0, 0, 128, 64, SH110X_WHITE);

    display1.setTextSize(1);
    // with comma
    // countdownTXT = String(solvingTime / 1000.0, 3);

    countdownTXT = convertMillisToReadableTime(solvingTime);

    display1.getTextBounds(countdownTXT, 0, 0, &x1, &y1, &width, &height);
    display1.setCursor((SCREEN_WIDTH - width) / 2, 5);
    display1.print(countdownTXT);

    txt = String(moves);
    display1.setTextSize(4);
    display1.getTextBounds(txt, 0, 0, &x1, &y1, &width, &height);
    display1.setCursor((SCREEN_WIDTH - width) / 2, 25);
    display1.print(txt);

    display1.setTextSize(1);
    display1.setCursor(115, 55);
    String usr = "T";
    if (user == 2)
        usr = "E";
    display1.print(usr);

    showBatteryStatus();

    display1.display();
}

void showloadingDuringConnection()
{
    display1.clearDisplay();
    display1.setTextSize(1);
    display1.setTextColor(SH110X_WHITE);
    display1.setCursor(12, 30);
    display1.print("Connecting to Cube");
    display1.display();
}

void showReady()
{
    display1.clearDisplay();
    display1.setTextSize(2);
    display1.setTextColor(SH110X_WHITE);
    display1.setCursor(35, 25);
    display1.print("READY");
    display1.display();
}

void showStats()
{
    display1.clearDisplay();
    display1.setTextSize(1);
    display1.setTextColor(SH110X_WHITE);
    display1.setCursor(5, 5);
    display1.print(stats1);
    display1.setCursor(5, 15);
    display1.print(stats2);
    display1.setCursor(5, 25);
    display1.print(stats3);

    display1.drawLine(0, 40, 128, 40, SH110X_WHITE);

    display1.setCursor(5, 45);
    display1.print(lastStats);
    display1.display();
}

#endif
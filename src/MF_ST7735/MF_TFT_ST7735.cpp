#include "MF_TFT_ST7735.h"
#include "mobiflight.h"
#include <Arduino.h>

void MF_TFT_ST7735::begin()
{

    tft.initR();
    tft.fillScreen(0x0000); // Clear the display from any previuos data
}

void MF_TFT_ST7735::refresh()
{
    tft.fillScreen(0x0000); // Clear the display from any previuos data
}

void MF_TFT_ST7735::attach(int8_t cs, int8_t dc, int8_t rst)
{
    _CS          = cs;
    _DC          = dc;
    _RST         = rst;
    _initialised = true;
    begin();
}

void MF_TFT_ST7735::detach()
{
    if (!_initialised)
        return;
    _initialised = false;
}

void MF_TFT_ST7735::display(const char *string)
{
    refresh();
    tft.setCursor(1, 1);
    tft.setTextSize(2);
    tft.print("MF Output:");
    tft.setCursor(1, 50);
    tft.print("Alt:");
    tft.setCursor(10, 50);
    tft.drawFastHLine(1, 50, 100, 0xFFFF);
    tft.setCursor(1, 80);
    tft.setTextSize(1);
    tft.print(string);
    tft.setCursor(1, 100);

    tft.setCursor(1, 120);
    tft.print("End");
}
#include "MF_OLED_SSD1322.h"
#include "mobiflight.h"
#include <Arduino.h>

void MF_OLED_SSD1322::begin()
{
    oled.begin();
    oled.clearBuffer();
}

void MF_OLED_SSD1322::refresh()
{
    oled.clearBuffer();
}

void MF_OLED_SSD1322::attach(int8_t cs, int8_t dc, int8_t rst)
{
    _CS          = cs;
    _DC          = dc;
    _RST         = rst;
    _initialised = true;
    begin();
}

void MF_OLED_SSD1322::detach()
{
    if (!_initialised)
        return;
    _initialised = false;
}

void MF_OLED_SSD1322::display(const char *string)
{
    refresh();
    oled.setFont(u8g2_font_ncenB08_tr);
    oled.drawStr(0, 10, "Test Test Test");
    oled.sendBuffer();
}
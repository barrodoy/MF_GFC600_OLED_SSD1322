#include "MF_OLED_SSD1322.h"
#include "mobiflight.h"
#include <Arduino.h>

String mf_data = cmdMessenger.readStringArg();

void MF_OLED_SSD1322::begin()
{
    oled.begin();
    oled.setFont(u8g2_font_profont22_mf); // choose a suitable font
    oled.drawStr(5, 10, "Welcome to MF"); // write something to the internal memory
    oled.sendBuffer();
    delay(1000);
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

void MF_OLED_SSD1322::drawRol()
{
    oled.setFont(u8g2_font_courB12_tf);
    oled.drawStr(6, 15, "ROL");
} // end of drawRol method

void MF_OLED_SSD1322::drawHdg()
{
    oled.setFont(u8g2_font_12x6LED_tf);
    oled.drawStr(6, 15, "HDG");
} // end of drawHdg method

void MF_OLED_SSD1322::drawLvlLat()
{
    oled.setFont(u8g2_font_courB12_tf);
    oled.drawStr(6, 15, "LVL");
} // end of drawLvlLat method

void MF_OLED_SSD1322::drawLvlVer()
{
    oled.setFont(u8g2_font_courB12_tf);
    oled.drawStr(56, 15, "LVL");
} // end of drawLvlVer method

void MF_OLED_SSD1322::drawVs()
{
    oled.setFont(u8g2_font_courB12_tf);
    oled.drawStr(56, 15, "VS"); // if VS mode is on, print "VS"
} // end of drawVs method

void MF_OLED_SSD1322::drawFpm()
{
    oled.setFont(u8g2_font_courB08_tf); // choose a suitable font
    oled.drawStr(140, 25, "FPM");       // if VS mode is on print "FPM" in a smaller font below the VS value display
    oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
} // end of drawFpm method

void MF_OLED_SSD1322::drawIas()
{
    oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
    oled.drawStr(56, 15, "IAS");        // if IAS mode is on, print "IAS"
} // end of drawIas method

void MF_OLED_SSD1322::drawKts()
{
    oled.setFont(u8g2_font_courB08_tf); // choose a suitable font
    oled.drawStr(140, 25, "KTS");       // if IAS mode is on, print "KTS"
    oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
} // end of drawKts method

void MF_OLED_SSD1322::drawSmallVor()
{
    oled.setFont(u8g2_font_courB08_tf); // choose a suitable font
    oled.drawStr(6, 57, "VOR");         // if VS mode is on, print "VS"
} // end of drawSmallVor method

void MF_OLED_SSD1322::drawBigVor()
{
    oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
    oled.drawStr(6, 15, "VOR");         // if IAS mode is on, print "IAS"
} // end of drawBigVor method

void MF_OLED_SSD1322::drawSmallAlts()
{
    oled.setFont(u8g2_font_courB08_tf); // choose a suitable font
    oled.drawStr(56, 57, "ALTS");       // if ALT mode is on, print "ALTS"
    oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
} // end of drawSmallAlts method

void MF_OLED_SSD1322::drawBigAlts()
{
    oled.drawStr(56, 15, "ALTS"); // if ALTS mode is on, print "ALTS"
} // end of drawBigAlts method

void MF_OLED_SSD1322::drawSmallFt()
{
    oled.setFont(u8g2_font_courB08_tf); // choose a suitable font
    oled.drawStr(150, 25, "FT");        // if ALTS mode is on, print "FT"
    oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
} // end of drawSmallFt method

void MF_OLED_SSD1322::drawSmallAlt()
{
    oled.setFont(u8g2_font_courB08_tf); // choose a suitable font
    oled.drawStr(56, 57, "ALT");        // if ALTS mode is on, print "ALT"
    oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
} // end of drawSmallAlt method

void MF_OLED_SSD1322::drawBigAlt()
{
    oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
    oled.drawStr(56, 15, "ALT");        // if ALT mode is on, print "ALT"
} // end of drawBigAlt method

void MF_OLED_SSD1322::drawBigGps()
{
    oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
    oled.drawStr(6, 15, "GPS");         // if ALT mode is on, print "ALT"
} // end of drawBigGps method

void MF_OLED_SSD1322::flash(const char *modeName)
{
    int i = 0;
    while (i < 10) {

        oled.drawStr(2, 10, modeName);
        oled.sendBuffer();
        delay(500);
        oled.clearBuffer();
        oled.drawStr(2, 10, "");
        oled.sendBuffer();
        delay(500);
        i++;
    }
}

void MF_OLED_SSD1322::display(char *string)
{

    int   ap        = atoi(strtok(string, "|")); // MF string - #
    int   fd        = atoi(strtok(NULL, "|"));   // MF string - !
    int   yd        = atoi(strtok(NULL, "|"));   // MF string - ?
    int   hdg       = atoi(strtok(NULL, "|"));   // MF string - @
    int   nav       = atoi(strtok(NULL, "|"));   // MF string - A
    int   apr       = atoi(strtok(NULL, "|"));   // MF string - B
    int   bc        = atoi(strtok(NULL, "|"));   // MF string - C
    int   vs        = atoi(strtok(NULL, "|"));   // MF string - D
    char *vsValStr  = strtok(NULL, "|");         // //MF string - E. vs value string for display
    int   vsVarInt  = atoi(vsValStr);            // vs value as int for calculations
    int   ias       = atoi(strtok(NULL, "|"));   // MF string - F
    char *iasValStr = strtok(NULL, "|");         // //MF string - G. ias value string for display
    int   iasVarInt = atoi(iasValStr);           // ias value as int for calculations
    int   alt       = atoi(strtok(NULL, "|"));   // MF string - H
    char *altValStr = strtok(NULL, "|");         // //MF string - I. vs value string for display
    int   altVarInt = atoi(altValStr);           // ias value as int for calculations
    int   lvl       = atoi(strtok(NULL, "|"));   // MF string - J
    int   rol       = atoi(strtok(NULL, "|"));   // MF string - K
    int   pit       = atoi(strtok(NULL, "|"));   // MF string - L

    oled.clearBuffer();

    oled.drawLine(52, 11, 52, 57);   // draws the boundary line of the lateral modes
    oled.drawLine(162, 11, 162, 57); // draws the boundary line of the vertical modes

    /*
    VERTICAL MODES DISPLAY
    */
    if (vs) {
        drawVs();
        oled.drawStr(90, 15, vsValStr);
        drawFpm();
    }

    // push data to display
    oled.sendBuffer();
} // end of Display function

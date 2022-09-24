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

void MF_OLED_SSD1322::setLargeFont()
{
    oled.setFont(u8g2_font_bpixeldouble_tr);
}

void MF_OLED_SSD1322::setSmallFont()
{
    oled.setFont(u8g2_font_profont12_tf);
}

void MF_OLED_SSD1322::setSymbolsFont()
{
    oled.setFont(u8g2_font_unifont_t_symbols);
}

void MF_OLED_SSD1322::drawPit()
{
    setLargeFont();
    oled.drawStr(56, 15, "PIT");
} // end of drawRol method

void MF_OLED_SSD1322::drawRol()
{
    setLargeFont();
    oled.drawStr(6, 15, "ROL");
} // end of drawRol method

void MF_OLED_SSD1322::drawHdg()
{
    setLargeFont();
    oled.drawStr(6, 15, "HDG");
} // end of drawHdg method

void MF_OLED_SSD1322::drawLvlLat()
{
    setLargeFont();
    oled.drawStr(6, 15, "LVL");
} // end of drawLvlLat method

void MF_OLED_SSD1322::drawLvlVer()
{
    setLargeFont();
    oled.drawStr(56, 15, "LVL");
} // end of drawLvlVer method

void MF_OLED_SSD1322::drawVs()
{
    setLargeFont();
    oled.drawStr(56, 15, "VS"); // if VS mode is on, print "VS"
} // end of drawVs method

void MF_OLED_SSD1322::drawFpm()
{
    setSmallFont();
    oled.drawStr(142, 25, "FPM"); // if VS mode is on print "FPM" in a smaller font below the VS value display
    setLargeFont();
} // end of drawFpm method

void MF_OLED_SSD1322::drawIas()
{
    setLargeFont();
    oled.drawStr(56, 15, "IAS"); // if IAS mode is on, print "IAS"
} // end of drawIas method

void MF_OLED_SSD1322::drawKts()
{
    setSmallFont();
    oled.drawStr(140, 25, "KTS"); // if IAS mode is on, print "KTS"
    setLargeFont();
} // end of drawKts method

void MF_OLED_SSD1322::drawSmallVor()
{
    setSmallFont();
    oled.drawStr(6, 57, "VOR"); // if VS mode is on, print "VS"
} // end of drawSmallVor method

void MF_OLED_SSD1322::drawBigVor()
{
    setLargeFont();
    oled.drawStr(6, 15, "VOR"); // if IAS mode is on, print "IAS"
} // end of drawBigVor method

void MF_OLED_SSD1322::drawSmallAlts()
{
    setSmallFont();
    oled.drawStr(56, 57, "ALTS"); // if ALT mode is on, print "ALTS"
    setLargeFont();
} // end of drawSmallAlts method

void MF_OLED_SSD1322::drawBigAlts()
{
    oled.drawStr(56, 15, "ALTS"); // if ALTS mode is on, print "ALTS"
} // end of drawBigAlts method

void MF_OLED_SSD1322::drawSmallFt()
{
    setSmallFont();
    oled.drawStr(150, 25, "FT"); // if ALTS mode is on, print "FT"
    setLargeFont();
} // end of drawSmallFt method

void MF_OLED_SSD1322::drawSmallAlt()
{
    setSmallFont();
    oled.drawStr(56, 57, "ALT"); // if ALTS mode is on, print "ALT"
    setLargeFont();
} // end of drawSmallAlt method

void MF_OLED_SSD1322::drawBigAlt()
{
    setLargeFont();
    oled.drawStr(56, 15, "ALT"); // if ALT mode is on, print "ALT"
} // end of drawBigAlt method

void MF_OLED_SSD1322::drawBigGps()
{
    setLargeFont();
    oled.drawStr(6, 15, "GPS"); // if ALT mode is on, print "ALT"
} // end of drawBigGps method

void MF_OLED_SSD1322::drawSmallLoc()
{
    setSmallFont();
    oled.drawStr(6, 57, "LOC"); // if LOC mode is Armed, print "LOC"
    setLargeFont();
} // end of drawSmallLoc method

void MF_OLED_SSD1322::drawSmallGps()
{
    setSmallFont();
    oled.drawStr(6, 57, "GPS"); // if GPS mode is Armed, print "GPS"
    setLargeFont();
} // end of drawSmallLoc method

void MF_OLED_SSD1322::drawSmallVapp()
{
    setSmallFont();
    oled.drawStr(6, 57, "VAPP"); // if VAPP mode is Armed, print "VAPP"
    setLargeFont();
} // end of drawSmallVapp method

void MF_OLED_SSD1322::drawBigGp()
{
    setLargeFont();
    oled.drawStr(56, 15, "GP"); // if ALTS mode is on, print "ALTS"
} // end of drawBigGP method

void MF_OLED_SSD1322::flash(const char *modeName)
{

    oled.drawStr(6, 15, "");
    oled.updateDisplayArea(0, 0, 15, 15);
    delay(500);
    oled.drawStr(6, 15, modeName);
    oled.updateDisplayArea(0, 0, 15, 15);
    delay(500);
    oled.drawStr(6, 15, "");
    oled.updateDisplayArea(0, 0, 15, 15);
    delay(500);
}

void MF_OLED_SSD1322::display(char *string)
{
    /*
    Read all AP modes and values from MF LCD string output
    */
    int   ap           = atoi(strtok(string, "|")); // MF string - #
    int   fd           = atoi(strtok(NULL, "|"));   // MF string - !
    int   yd           = atoi(strtok(NULL, "|"));   // MF string - ?
    int   hdg          = atoi(strtok(NULL, "|"));   // MF string - @
    int   nav          = atoi(strtok(NULL, "|"));   // MF string - A
    int   apr          = atoi(strtok(NULL, "|"));   // MF string - B
    int   bc           = atoi(strtok(NULL, "|"));   // MF string - C
    int   vs           = atoi(strtok(NULL, "|"));   // MF string - D
    char *vsValStr     = strtok(NULL, "|");         // //MF string - E. vs value string for display
    int   vsValInt     = atoi(vsValStr);            // vs value as int for calculations
    int   ias          = atoi(strtok(NULL, "|"));   // MF string - F
    char *iasValStr    = strtok(NULL, "|");         // //MF string - G. ias value string for display
    int   iasValInt    = atoi(iasValStr);           // ias value as int for calculations
    int   alt          = atoi(strtok(NULL, "|"));   // MF string - H
    char *altValStr    = strtok(NULL, "|");         // //MF string - I. vs value string for display
    int   altValInt    = atoi(altValStr);           // ias value as int for calculations
    int   lvl          = atoi(strtok(NULL, "|"));   // MF string - J
    int   rol          = atoi(strtok(NULL, "|"));   // MF string - K
    int   pit          = atoi(strtok(NULL, "|"));   // MF string - L
    int   gps          = atoi(strtok(NULL, "|"));   // MF string - M
    int   loc          = atoi(strtok(NULL, "|"));   // MF string - N
    int   alts         = atoi(strtok(NULL, "|"));   // MF string - O
    char *indAltValStr = strtok(NULL, "|");         // MF String - P
    int   indAltValInt = atoi(indAltValStr);
    int   vorReception = atoi(strtok(NULL, "|"));
    int   avionics     = atoi(strtok(NULL, "|")); // MF string - R
    int   hdgAsInit    = atoi(strtok(NULL, "|")); // MF string - S

    /*
Some AP logic
    */
    bool navVorArmed  = (rol || hdg) && nav && !gps && !loc; // HDG mode is on with NAV VOR armed
    bool navGpsArmed  = (rol || hdg) && nav && gps;          // HDG mode is on with NAV GPS armed
    bool navLocArmed  = (rol || hdg) && nav && !gps && loc;  // HDG mode is on with NAV LOC armed
    bool navVappArmed = (rol || hdg) && apr;
    bool navGpsActive = (!rol && !hdg) && (nav || apr) && gps; // NAV GPS is active
    bool navVorActive = (!rol && !hdg) && nav && !gps && !loc; // NAV VOR is active
    bool navGpsGp     = gps && apr && !pit;
    bool altsActive   = (alt || ias || vs) && alts;

    oled.clearBuffer(); // refresh the display

    if (avionics) {
        oled.drawLine(52, 11, 52, 57);   // draws the boundary line of the lateral modes
        oled.drawLine(162, 11, 162, 57); // draws the boundary line of the vertical modes
        oled.drawStr(230, 15, "PFT");
        delay(500);
    }

    // draw Init screen

    /*
    VERTICAL MODES DISPLAY
    */
    if (vs) {
        drawVs();

        if (vsValInt < 0 && vsValInt > -999) {
            oled.setCursor(136, 15);
            setLargeFont();
            oled.print(vsValInt * -(1));
            setSymbolsFont();
            oled.drawUTF8(128, 15, "↓");
        }

        else if (vsValInt < -999) {
            oled.setCursor(130, 15);
            setLargeFont();
            oled.print(vsValInt * -(1));
            setSymbolsFont();
            oled.drawUTF8(122, 15, "↓");
        }

        else if (vsValInt > 0 && vsValInt < 999) {
            oled.setCursor(136, 15);
            setLargeFont();
            oled.print(vsValInt);
            setSymbolsFont();
            oled.drawUTF8(128, 15, "↑");
        }

        else if (vsValInt > 999) {
            oled.setCursor(130, 15);
            setLargeFont();
            oled.print(vsValInt);
            setSymbolsFont();
            oled.drawUTF8(122, 15, "↑");
        }

        else if (vsValInt == 0) {
            setLargeFont();
            oled.drawStr(114, 15, vsValStr);
        }
        drawFpm();
        drawSmallAlts();
    }

    if (ias) {
        drawIas();
        oled.drawStr(136, 15, iasValStr);
        drawKts();
        drawSmallAlts();
    }

    if (pit) {
        drawPit();
        drawSmallAlts();
    }

    if (alt && !alts) {
        drawBigAlt();
        oled.drawStr(120, 15, indAltValStr);
    }

    if (alts) {
        drawBigAlts();
        oled.drawStr(120, 15, altValStr);
        drawSmallAlt();
    }

    if (navGpsGp) {
        drawBigGp();
    }

    /*
    LATERAL MODES DISPLAY
    */

    if (rol) {
        drawRol();
        if (navVorArmed) {
            drawSmallVor();
        }

        if (navGpsArmed) {
            drawSmallGps();
        }

        if (navVappArmed) {
            drawSmallVapp();
        }
    }
    if (hdg) {
        drawHdg();
        if (navVorArmed) {
            drawSmallVor();
        }
        if (navGpsArmed) {
            drawSmallGps();
        }

        if (navVappArmed) {
            drawSmallVapp();
        }
    }

    if (navGpsActive) {
        drawBigGps();
    }

    if (navVorActive) {
        drawBigVor();
    }

    // push data to display
    oled.sendBuffer();
} // end of Display function

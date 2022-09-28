#include "MF_OLED_SSD1322.h"
#include "mobiflight.h"
#include <Arduino.h>

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
    oled.setFont(u8g2_font_profont12_mr);
}

void MF_OLED_SSD1322::setSymbolsFont()
{
    oled.setFont(u8g2_font_9x15_t_symbols);
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

void MF_OLED_SSD1322::drawBigPft()
{
    setLargeFont();
    oled.drawStr(230, 15, "PFT");
    delay(500);
}

void MF_OLED_SSD1322::drawInitScreen()
{
    oled.setFont(u8g2_font_tenfatguys_tf);
    oled.drawStr(92, 15, "GFC600");
    oled.setFont(u8g2_font_tenthinguys_tr);
    oled.drawStr(34, 28, "WITH ELECTRONIC STABILITY");
    oled.drawStr(79, 42, "AND PROTECTION");
    oled.setFont(u8g2_font_profont15_mf);
    oled.drawStr(6, 56, "CONT");
    setSymbolsFont();
    oled.drawStr(1, 56, "↙ ");
}

void MF_OLED_SSD1322::drawNegative3DigitsVs(int vsValInt)
{
    oled.setCursor(136, 15);
    setLargeFont();
    oled.print(vsValInt * -(1));
    setSymbolsFont();
    oled.drawUTF8(128, 15, "↓");
}

void MF_OLED_SSD1322::drawNegative4DigitsVs(int vsValInt)
{
    oled.setCursor(130, 15);
    setLargeFont();
    oled.print(vsValInt * -(1));
    setSymbolsFont();
    oled.drawUTF8(122, 15, "↓");
}

void MF_OLED_SSD1322 ::drawPositive3DigitsVs(int vsValInt)
{
    oled.setCursor(136, 15);
    setLargeFont();
    oled.print(vsValInt);
    setSymbolsFont();
    oled.drawUTF8(128, 15, "↑");
}

void MF_OLED_SSD1322 ::drawPositive4DigitsVs(int vsValInt)
{
    oled.setCursor(130, 15);
    setLargeFont();
    oled.print(vsValInt);
    setSymbolsFont();
    oled.drawUTF8(122, 15, "↑");
}

void MF_OLED_SSD1322::drawVsZero(int vsValInt)
{
    oled.setCursor(140, 15);
    setLargeFont();
    oled.print(vsValInt);
}

void MF_OLED_SSD1322 ::preFlightTest()
{
    setSmallFont();
    oled.drawStr(220, 15, "PFT");
    oled.sendBuffer();
    analogWrite(apRedLed, 255);
    analogWrite(apGreenLed, 255);
    analogWrite(apBlueLed, 0);
    delay(1000);
    analogWrite(apRedLed, 255);
    analogWrite(apGreenLed, 0);
    analogWrite(apBlueLed, 0);
    delay(1000);
    analogWrite(apRedLed, 0);
    analogWrite(apGreenLed, 0);
    analogWrite(apBlueLed, 0);
    oled.clearBuffer();              // refresh the display
    oled.drawLine(52, 11, 52, 57);   // draws the boundary line of the lateral modes
    oled.drawLine(162, 11, 162, 57); // draws the boundary line of the vertical modes
    initSeqDone = 1;
}

void MF_OLED_SSD1322::altsFlash()
{
    uint8_t       altsFlashState          = 0;
    unsigned long altsFlashPreviousMillis = 0;
    const long    altsFlashInterval       = 500;
    uint8_t       altsFlashCount          = 0;

    while (altsFlashCount < 10) {
        unsigned long altsFlashCurrentMillis = millis();
        if (altsFlashCurrentMillis - altsFlashPreviousMillis >= altsFlashInterval) {

            if (altsFlashState == 0) {
                altsFlashState = 1;
            }

            else {
                altsFlashState = 0;
            }

            if (altsFlashState == 1) {
                setLargeFont();
                oled.setDrawColor(1);
                oled.drawBox(56, 0, 35, 15);
                oled.setDrawColor(0);
                oled.drawStr(56, 15, "ALTS");
                oled.sendBuffer();
            }

            else {
                oled.setDrawColor(0);
                oled.drawBox(56, 0, 35, 15);
                oled.setDrawColor(1);
                oled.drawStr(56, 15, "ALTS");
                oled.sendBuffer();
            }
            altsFlashPreviousMillis = altsFlashCurrentMillis;
            altsFlashCount++;
            // save the last time you blinked the LED
        }
    }
    altsFlashed = 1;
}

void MF_OLED_SSD1322::apLedYellow(uint8_t state)
{
    if (state == 1) {
        analogWrite(apRedLed, 255);
        analogWrite(apGreenLed, 255);
        analogWrite(apBlueLed, 0);
    }

    else {
        analogWrite(apRedLed, 0);
        analogWrite(apGreenLed, 0);
        analogWrite(apBlueLed, 0);
    }
}

void MF_OLED_SSD1322::apLedRed()
{
    analogWrite(apRedLed, 255);
    analogWrite(apGreenLed, 0);
    analogWrite(apBlueLed, 0);
}

void MF_OLED_SSD1322::apLedGreen()
{
    analogWrite(apRedLed, 0);
    analogWrite(apGreenLed, 255);
    analogWrite(apBlueLed, 0);
}

void MF_OLED_SSD1322::apLedOff()
{
    analogWrite(apRedLed, 0);
    analogWrite(apGreenLed, 0);
    analogWrite(apBlueLed, 0);
}

void MF_OLED_SSD1322::display(char *string)
{
    /*
    Read all AP modes and values from MF LCD string output
    */
    int   ap        = atoi(strtok(string, "|")); // MF string - #
    int   fd        = atoi(strtok(NULL, "|"));   // MF string - !
    int   yd        = atoi(strtok(NULL, "|"));   // MF string - ?
    int   hdg       = atoi(strtok(NULL, "|"));   // MF string - @
    int   nav       = atoi(strtok(NULL, "|"));   // MF string - A
    int   apr       = atoi(strtok(NULL, "|"));   // MF string - B
    int   bc        = atoi(strtok(NULL, "|"));   // MF string - C
    int   vs        = atoi(strtok(NULL, "|"));   // MF string - D
    char *vsValStr  = strtok(NULL, "|");         // //MF string - E. vs value string for display
    int   vsValInt  = atoi(vsValStr);            // vs value as int for calculations
    int   ias       = atoi(strtok(NULL, "|"));   // MF string - F
    char *iasValStr = strtok(NULL, "|");         // //MF string - G. ias value string for display
    int   iasValInt = atoi(iasValStr);           // ias value as int for calculations
    int   alt       = atoi(strtok(NULL, "|"));   // MF string - H
    char *altValStr = strtok(NULL, "|");         // //MF string - I. vs value string for display
    int   altValInt = atoi(altValStr);           // ias value as int for calculations
    int   lvl       = atoi(strtok(NULL, "|"));   // MF string - J
    int   rol       = atoi(strtok(NULL, "|"));   // MF string - K
    int   pit       = atoi(strtok(NULL, "|"));   // MF string - L
    int   gps       = atoi(strtok(NULL, "|"));   // MF string - M
    int   loc       = atoi(strtok(NULL, "|"));   // MF string - N

    char *indAltValStr      = strtok(NULL, "|"); // MF String - P
    int   indAltValInt      = atoi(indAltValStr);
    int   vorReception      = atoi(strtok(NULL, "|"));
    int   avionics          = atoi(strtok(NULL, "|")); // MF string - R
    int   contButtonPressed = atoi(strtok(NULL, "|")); // MF string - S
    int   alts              = atoi(strtok(NULL, "|")); // MF string - O
    int   roundAlt          = atoi(strtok(NULL, "|")); // MF string - T

    // bool alts = (alt || vs || ias || pit) && (((altValInt - indAltValInt < 400) && ((altValInt - indAltValInt > 51) || (altValInt - indAltValInt > -400)) && (altValInt - indAltValInt < -51)));

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

    bool negative3DigitsVs = vsValInt < 0 && vsValInt > -999;
    bool negative4DigitsVs = vsValInt < -999;
    bool positive3DigitsVs = vsValInt > 0 && vsValInt < 999;
    bool positive4DigitsVs = vsValInt > 999;
    bool vsZero            = vsValInt == 0;

    oled.clearBuffer(); // refresh the display

    if (!avionics) {
        initSeqDone = 0;
    }

    if (avionics && !contButtonPressed) { // init screen
        drawInitScreen();
    } // end of init

    else if (avionics && contButtonPressed && !initSeqDone) { // If avionics are on and init process is done
        oled.drawLine(52, 11, 52, 57);                        // draws the boundary line of the lateral modes
        oled.drawLine(162, 11, 162, 57);
        preFlightTest();

    }

    else if (avionics && contButtonPressed && initSeqDone) {
        oled.clearBuffer();              // refresh the display
        oled.drawLine(52, 11, 52, 57);   // draws the boundary line of the lateral modes
        oled.drawLine(162, 11, 162, 57); // draws the boundary line of the vertical modes

        /*
        AP,YD,FD MODES INDICATIOS:
        */

        if (ap) {
            wasApOn = 1;
            analogWrite(apGreenLed, 255);
        }

        else if (!ap && wasApOn) {
            uint8_t       yellowLedState            = 0;
            unsigned long yellowFlashPreviousMillis = 0;
            const long    yellowFlashInterval       = 500;
            uint8_t       apYellowFlashCount        = 0;

            while (apYellowFlashCount < 10) {
                unsigned long yellowFlashCurrentMillis = millis();
                if (yellowFlashCurrentMillis - yellowFlashPreviousMillis >= yellowFlashInterval) {
                    // save the last time you blinked the LED

                    if (yellowLedState == 0) {
                        yellowLedState = 1;
                    }

                    else {
                        yellowLedState = 0;
                    }

                    apLedYellow(yellowLedState);

                    yellowFlashPreviousMillis = yellowFlashCurrentMillis;
                    apYellowFlashCount++;
                }
            }

            apLedOff();
            wasApOn = 0;
        }

        else {
            analogWrite(apGreenLed, 0);
            wasApOn = 0;
        }

        /*
        LATERAL MODES DISPLAY
        */

        if (rol) { // ROL MODE
            drawRol();
            if (navVorArmed) { // VOR navigation is armed in ROL mode
                drawSmallVor();
            }

            if (navGpsArmed) { // GPS navigation is armed in ROL mode
                drawSmallGps();
            }

            if (navVappArmed) { // APR is armed in ROL mode
                drawSmallVapp();
            }
        }
        if (hdg) { // HDG MODE
            drawHdg();
            if (navVorArmed) { // VOR navigation is armed in HDG mode
                drawSmallVor();
            }
            if (navGpsArmed) { // GPS navigation is armed in HDG mode
                drawSmallGps();
            }

            if (navVappArmed) { // APR navigation is armed in HDG mode
                drawSmallVapp();
            }
        }

        if (navGpsActive) { // GPS navigation is active
            drawBigGps();
        }

        if (navVorActive) { // VOR navigation is active
            drawBigVor();
        }

        /*
    VERTICAL MODES DISPLAY
    */

        if (vs) { // VS MODE
            drawVs();

            if (negative3DigitsVs) {
                drawNegative3DigitsVs(vsValInt);
            }

            else if (negative4DigitsVs) { // 4 digits negative VS value
                drawNegative4DigitsVs(vsValInt);

            }

            else if (positive3DigitsVs) { // 3 digits positive VS value
                drawPositive3DigitsVs(vsValInt);
            }

            else if (positive4DigitsVs) { // 4 digits positive VS value
                drawPositive4DigitsVs(vsValInt);
            }

            else if (vsZero) { // if VS is 0, no arrow needed
                drawVsZero(vsValInt);
            }
            drawFpm();
            drawSmallAlts();
            altsFlashed = 0;
        }

        else if (ias) { // IAS/FLC MODE
            drawIas();
            oled.drawStr(136, 15, iasValStr);
            drawKts();
            drawSmallAlts();
            altsFlashed = 0;
        }

        else if (pit) { // PITCH MODE
            drawPit();
            drawSmallAlts();
            altsFlashed = 0;
        } else if (navGpsGp) { // GPS GP MODE
            drawBigGp();
        }

        else if (lvl) { // LVL vertical mode
            drawLvlVer();
        }

        else if (alt && !alts) { // ALT HOLD MODE
            drawBigAlt();
            oled.setCursor(130, 15);
            oled.print(roundAlt);
            // oled.drawStr(120, 15, indAltValStr);
            drawSmallFt();
            altsFlashed = 0;
            oled.sendBuffer();
        }

        else if (alts && !altsFlashed) { // ALT CAPTURE MODE
            drawBigAlts();
            oled.drawStr(120, 15, altValStr);
            drawSmallAlt();
            drawSmallFt();
            // altsFlash();
            altsFlashed = 1;
            oled.sendBuffer();
        }

        else if (alts && altsFlashed) {
            { // ALT CAPTURE MODE
                drawBigAlts();
                oled.drawStr(120, 15, altValStr);
                drawSmallFt();
                drawSmallAlt();
                altsFlashed = 1;
                oled.sendBuffer();
            }
        }
    } // end of avionics and init done

    // push data to display
    oled.sendBuffer();
    delay(50);
} // end of Display function
#include "MF_OLED_SSD1322.h"
#include "mobiflight.h"
#include <Arduino.h>

void MF_OLED_SSD1322::begin()
{
    oled.begin();
    oled.setFont(u8g2_font_courB12_tf);   // choose a suitable font
    oled.drawStr(2, 10, "Welcome to MF"); // write something to the internal memory
    oled.sendBuffer();
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
    oled.setFont(u8g2_font_courB12_tf);
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

String MF_OLED_SSD1322::prepareData(const char *string)
{
    String mf_data = string;

    return mf_data;

} // end of prepareData method

bool MF_OLED_SSD1322::fdOn(String mf_data)
{
    if (mf_data.charAt(0) == '1') {
        return true;
    }

    else {
        return false;
    }
} // end of fdOn method

bool MF_OLED_SSD1322::hdgOn(String mf_data)
{
    if (mf_data.charAt(2) == '1') {
        return true;
    }

    else {
        return false;
    }
} // end of hdgOn method

bool MF_OLED_SSD1322::vsOn(String mf_data)
{
    if (mf_data.charAt(4) == '1') {
        return true;
    }

    else {
        return false;
    }
} // end of vsOn method

bool MF_OLED_SSD1322::iasOn(String mf_data)
{
    if (mf_data.charAt(12) == '1') {
        return true;
    }

    else {
        return false;
    }
} // end of iasOn method

bool MF_OLED_SSD1322::altOn(String mf_data)
{
    if (mf_data.charAt(32) == '1') {
        return true;
    }

    else {
        return false;
    }
} // end of altOn method

bool MF_OLED_SSD1322::lvlOn(String mf_data)
{
    if (mf_data.charAt(34) == '1') {
        return true;
    }

    else {
        return false;
    }
} // end of lvlOn method

bool MF_OLED_SSD1322::vorOn(String mf_data)
{
    if (mf_data.charAt(36) == '1') {
        return true;
    }

    else {
        return false;
    }
} // end of vorOn method

bool MF_OLED_SSD1322::gpsNavOn(String mf_data)
{
    if (mf_data.charAt(38) == '1') {
        return true;
    }

    else {
        return false;
    }
} // end of gpsNavOn method

void MF_OLED_SSD1322::display(const char *string)
{
    // prepare data
    String mf_data = prepareData(string);
    bool   fdMode  = fdOn(mf_data);
    bool   hdgMode = hdgOn(mf_data);
    bool   vsMode  = vsOn(mf_data);
    bool   iasMode = iasOn(mf_data);
    bool   altMode = altOn(mf_data);
    bool   lvlMode = lvlOn(mf_data);
    bool   vorMode = vorOn(mf_data);
    bool   gpsMode = gpsNavOn(mf_data);

    // prepare VS data
    String vsString = mf_data.substring(6, 11); // takes vs from mf_data String object
    int    vsInt;
    vsInt          = vsString.toInt();
    const char *vs = vsString.c_str(); // converts vsString String object to chars array

    // prepare IAS data
    String      iasString = mf_data.substring(14, 17);
    const char *ias       = iasString.c_str();

    // prepare ALT data
    String altString = mf_data.substring(20, 25);
    int    altInt;
    altInt          = altString.toInt();
    const char *alt = altString.c_str();

    // prepare AP ALT data:
    String apAltString = mf_data.substring(27, 31);
    int    apAltInt;
    apAltInt          = apAltString.toInt();
    const char *apAlt = apAltString.c_str();

    oled.clearBuffer(); // clear the internal memory           // transfer internal memory to the display

    // lines drawing
    oled.drawLine(52, 11, 52, 57);   // draws the boundary line of the lateral modes
    oled.drawLine(162, 11, 162, 57); // draws the boundary line of the vertical modes

    // charAt(0) - FD
    // charAt(2) - HDG
    // charAt(36) - VOR
    // charAt(34) - LVL
    // charAt(4) - VS
    // charAt(12) - IAS
    // charAt(32) - ALT
    // charAt(38) - NAV/GPS

    // check if FD is on
    if (mf_data.charAt(0) == '1') {
        // if FD is on

        // lateral modes

        // HDG mode
        if (mf_data.charAt(2) == '1') {
            drawHdg();

            if (mf_data.charAt(36) == '1') { // if VOR is armed with HDG On
                drawSmallVor();
            }

        } // end of HDG mode

        // NAV Mode
        else if (mf_data.charAt(36) == '1' && mf_data.charAt(2) == '0' && mf_data.charAt(38) == '0') {
            drawBigVor();
        } // end of Nav Mode

        // GPS Nav mode
        else if (mf_data.charAt(36) == '1' && mf_data.charAt(2) == '0' && mf_data.charAt(38) == '1') {
            drawBigGps();
        } // end of GPS Nav mode

        else {
            drawRol();
            // oled.drawStr(6, 15, "ROL");
        }

        // vertical modes

        // LVL mode
        if (mf_data.charAt(34) == '1') {
            drawLvlLat();
            drawLvlVer();
        } // end of LVL mode

        // VS mode
        else if (mf_data.charAt(4) == '1' && mf_data.charAt(34) == '0') {
            drawVs();
            drawFpm();
            // oled.drawStr(56, 15, "VS");         // if VS mode is on, print "VS"
            // oled.setFont(u8g2_font_courB08_tf); // choose a suitable font
            // oled.drawStr(140, 25, "FPM");       // if VS mode is on print "FPM" in a smaller font below the VS value display
            // oled.setFont(u8g2_font_courB12_tf); // choose a suitable font

            // if selected vs value is 3 positive 3 digits
            if ((vsInt > 0) && (vsInt < 999)) {
                oled.setFont(u8g2_font_cu12_t_symbols);
                oled.drawUTF8(122, 15, "↑");
                oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
                oled.drawStr(110, 15, vs);
            }

            // if selected vs value is positive 4 digites
            else if (vsInt > 999) {

                oled.setFont(u8g2_font_cu12_t_symbols);
                oled.drawUTF8(110, 15, "↑");
                oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
                oled.drawStr(110, 15, vs);
            }

            // if selected vs value is negative 3 digits
            else if (vsInt < 0 && vsInt > -999) {

                // remove the minus sign
                vsString       = mf_data.substring(8, 11);
                const char *vs = vsString.c_str(); // converts vsString String object to chars array

                oled.setFont(u8g2_font_cu12_t_symbols);
                oled.drawUTF8(122, 15, "↓");
                oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
                oled.drawStr(130, 15, vs);

            }

            else if (vsInt < -999) {
                // remove the minus sign
                vsString       = mf_data.substring(7, 11);
                const char *vs = vsString.c_str(); // converts vsString String object to chars array

                oled.setFont(u8g2_font_cu12_t_symbols);
                oled.drawUTF8(114, 15, "↓");
                oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
                oled.drawStr(122, 15, vs);
            }

            else if (vsInt == 0) {
                oled.setFont(u8g2_font_courB12_tf); // choose a suitable font
                oled.drawStr(110, 15, vs);
            }

            // oled.drawStr(26, 25, mf_data.substring(6, 11));
        } // end of VS mode

        // IAS mode
        else if (mf_data.charAt(12) == '1') {
            drawIas();
            // oled.drawStr(56, 15, "IAS"); // if IAS mode is on, print "IAS"
            oled.drawStr(130, 15, ias);

            drawKts();
            // oled.setFont(u8g2_font_courB08_tf); // choose a suitable font
            // oled.drawStr(140, 25, "KTS");       // if IAS mode is on, print "KTS"
            // oled.setFont(u8g2_font_courB12_tf); // choose a suitable font

        } // end of IAS mode

        else if (mf_data.charAt(32) == '1') {
            if (apAltInt - altInt >= 50 || apAltInt - altInt <= -50) {
                drawBigAlts();
                oled.drawStr(120, 15, apAlt);
                drawSmallFt();
                drawSmallAlt();
            } // end of "ALTS" if

            else {
                drawBigAlt();
                oled.drawStr(120, 15, apAlt);
                drawSmallFt();
                drawSmallAlts();
            } // end of "ALT"

        } // end of ALTS\ALT modes

        else // PIT Mode
        {
            oled.drawStr(56, 15, "PIT"); // if PIT mode is on, print "PIT"
            drawSmallAlts();
        } // end of "PIT"

        // ALTS text condition
        if ((mf_data.charAt(4) == '1' || mf_data.charAt(12) == '1') && mf_data.charAt(34) == '0') {
            drawSmallAlts();
        }

    } // end of FD if

    // push data to display
    oled.sendBuffer();
} // end of Display function

#include "U8g2lib.h"
#include "commandmessenger.h"
#include <Arduino.h>

class MF_OLED_SSD1322
{
private:
    // Fields
    int8_t _CS  = 10;
    int8_t _DC  = 9;
    int8_t _RST = 8;

    bool _initialised;

public:
    // Constructor
    U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI oled;
    MF_OLED_SSD1322(const u8g2_cb_t *rotation, uint8_t cs = 10, uint8_t dc = 9, uint8_t reset = 8)
        : oled(U8G2_R2, cs, dc, reset){};

    // ************************************
    // **** GLOBAL & UNIVERSAL METHODS ***
    // ********
    uint8_t       initSeqDone             = 0;
    uint8_t       apRedLed                = 44;
    uint8_t       apGreenLed              = 6;
    uint8_t       apBlueLed               = 46;
    uint8_t       fdLed                   = 5;
    uint8_t       ydLed                   = 28;
    uint8_t       altsFlashEnable         = 1;
    uint8_t       altsFlashState          = 0;
    unsigned long altsFlashPreviousMillis = 0;
    unsigned long altsFlashInterval       = 500;
    uint8_t       altsFlashCount          = 0;
    bool          wasApOn                 = 0;
    unsigned long CurrentMillis           = millis();

    void begin();
    void attach(int8_t cs, int8_t dc, int8_t rst);
    void detach();
    void display(char *string);
    void refresh();
    void drawPit();
    void drawRol();
    void drawHdg();
    void drawLvlLat();
    void drawLvlVer();
    void drawVs();
    void drawBigGs();
    void drawFpm();
    void drawIas();
    void drawKts();
    void drawSmallVor();
    void drawBigVor();
    void drawSmallAlts();
    void drawBigAlts();
    void drawSmallFt();
    void drawSmallAlt();
    void drawBigAlt();
    void drawBigGps();
    void drawBigLoc();
    void drawSmallLoc();
    void drawSmallGs();
    void drawSmallGps();
    void setLargeFont();
    void setSmallFont();
    void drawSmallVapp();
    void setSymbolsFont();
    void drawBigGp();
    void drawBigPft();
    void drawInitScreen();
    void drawNegative3DigitsVs(int vsValInt);
    void drawNegative4DigitsVs(int vsValInt);
    void drawPositive3DigitsVs(int vsValInt);
    void drawPositive4DigitsVs(int vsValInt);
    void drawVsZero(int vsValInt);
    void preFlightTest();
    void altsFlash();
    void apLedYellow(uint8_t state);
    void apLedRed();
    void apLedGreen();
    void apLedOff();
    void apLedYellowFlash();
};
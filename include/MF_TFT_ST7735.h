#include "Adafruit_ST7735.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SPIDevice.h"
#include "Adafruit_ST7789.h"
#include "Adafruit_ST77xx.h"

class MF_TFT_ST7735
{
private:
    // Fields
    Adafruit_ST7735 tft;
    int8_t _CS;
    int8_t _DC;
    int8_t _RST;
    bool _initialised;

public:
    // Constructor
    // 'CLK' is sometimes referred to as 'RW'
    MF_TFT_ST7735(int8_t cs = 10, int8_t dc = 8, int8_t rst = 9);

    // ************************************
    // **** GLOBAL & UNIVERSAL METHODS ****
    // ********

    void attach(int8_t cs, int8_t dc, int8_t rst);
    void detach();
    void displayTest();
};
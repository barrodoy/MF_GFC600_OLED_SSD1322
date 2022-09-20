#include "Adafruit_ST7735.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SPIDevice.h"
#include "Adafruit_ST7789.h"
#include "Adafruit_ST77xx.h"

class MF_TFT_ST7735
{
private:
    // Fields
    int8_t _CS;
    int8_t _DC;
    int8_t _RST;
    bool   _initialised;

public:
    // Constructor
    Adafruit_ST7735 tft;
    MF_TFT_ST7735(int8_t cs = 10, int8_t dc = 8, int8_t rst = 9)
        : tft(cs, dc, rst){};

    // ************************************
    // **** GLOBAL & UNIVERSAL METHODS ****
    // ********
    void begin();
    void attach(int8_t cs, int8_t dc, int8_t rst);
    void detach();
    void display(const char *string);
    void refresh();
};
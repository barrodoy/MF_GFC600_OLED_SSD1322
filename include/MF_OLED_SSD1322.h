#include "U8g2lib.h"

class MF_OLED_SSD1322
{
private:
    // Fields
    int8_t _CS;
    int8_t _DC;
    int8_t _RST;
    bool   _initialised;

public:
    // Constructor
    U8G2_SSD1322_NHD_128X64_F_4W_HW_SPI oled;
    MF_OLED_SSD1322(const u8g2_cb_t *rotation, uint8_t cs = 10, uint8_t dc = 9, uint8_t reset = 8)
        : oled(U8G2_R0, cs, dc, reset){};

    // ************************************
    // **** GLOBAL & UNIVERSAL METHODS ****
    // ********
    void begin();
    void attach(int8_t cs, int8_t dc, int8_t rst);
    void detach();
    void display(const char *string);
    void refresh();
};
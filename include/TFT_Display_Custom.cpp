#include <Arduino.h>
//#include "MFLCDDisplay.h"
#include "allocateMem.h"
#include "commandmessenger.h"
#include "TFT_Display_Custom.h"
#include "MF_TFT_ST7735.h"
#include "MFBoards.h"
#include "Adafruit_ST7735.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SPIDevice.h"
#include "Adafruit_ST7789.h"
#include "Adafruit_ST77xx.h"

namespace TFT_Display_Custom
{
    MF_TFT_ST7735 *lcd_SPI[MAX_MFLCD_SPI];
    uint8_t        cust_LCDs_Registered = 0;

    void Add(int8_t cs = 10, int8_t dc = 8, int8_t rst = 9)
    {
        if (cust_LCDs_Registered == MAX_MFLCD_SPI)
            return;

        if (!FitInMemory(sizeof(MF_TFT_ST7735))) {
            // Error Message to Connector
            cmdMessenger.sendCmd(kStatus, F("Custom LCD does not fit in Memory!"));
            return;
        }
        lcd_SPI[cust_LCDs_Registered] = new MF_TFT_ST7735(cs, dc, rst);
        lcd_SPI[cust_LCDs_Registered]->attach(cs, dc, rst);
        cust_LCDs_Registered++;
#ifdef DEBUG2CMDMESSENGER
        cmdMessenger.sendCmd(kStatus, F("Added lcdDisplay"));
#endif
    }

    void Clear()
    {
        for (int i = 0; i != cust_LCDs_Registered; i++) {
            lcd_SPI[i]->detach();
        }
        cust_LCDs_Registered = 0;
#ifdef DEBUG2CMDMESSENGER
        cmdMessenger.sendCmd(kStatus, F("Cleared lcdDisplays"));
#endif
    }

    void OnSet()
    {
        int   address = cmdMessenger.readInt16Arg();
        char *output  = cmdMessenger.readStringArg();

        // lcd_SPI[0]->handleMobiFlightRaw(output); // This needs to be set to lcd_SPI[address]->... for release.
        lcd_SPI[0]->displayTest();
        setLastCommandMillis();
    }
} // end of namespace LCDDisplayCustom

#include <Arduino.h>
//#include "MFLCDDisplay.h"
#include "allocateMem.h"
#include "commandmessenger.h"
#include "OLED_Display_Custom.h"
#include "MF_OLED_SSD1322.h"
#include "MFBoards.h"
#include "U8g2lib.h"

namespace OLED_Display_Custom
{
    MF_OLED_SSD1322 *lcd_I2C[MAX_MFLCD_I2C];
    uint8_t          cust_LCDs_Registered = 0;

    void Add(int8_t cs = 10, int8_t dc = 9, int8_t rst = 8)
    {
        if (cust_LCDs_Registered == MAX_MFLCD_I2C)
            return;

        if (!FitInMemory(sizeof(MF_OLED_SSD1322))) {
            // Error Message to Connector
            cmdMessenger.sendCmd(kStatus, F("Custom LCD does not fit in Memory!"));
            return;
        }
        lcd_I2C[cust_LCDs_Registered] = new MF_OLED_SSD1322(U8G2_R0, cs, dc, rst);
        lcd_I2C[cust_LCDs_Registered]->attach(cs, dc, rst);
        cust_LCDs_Registered++;
#ifdef DEBUG2CMDMESSENGER
        cmdMessenger.sendCmd(kStatus, F("Added lcdDisplay"));
#endif
    }

    void Clear()
    {
        for (int i = 0; i != cust_LCDs_Registered; i++) {
            lcd_I2C[i]->detach();
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
        lcd_I2C[address]->display(output);
        setLastCommandMillis();
    }
} // end of namespace LCDDisplayCustom

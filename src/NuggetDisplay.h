#pragma once

#include "Arduino.h"
#include "SH1106Wire.h"
#include "Nugget_Buttons.h"

extern SH1106Wire display;
extern Nugget_Buttons nuggButtons;

// add dashboard, loader bar?

class NuggetDisplay {

  public:
    NuggetDisplay();

    /* ----- HEADER ----- */
    void setHeader(String headerText);
    void setHeader(String headerText, String subHeaderText);
    
    /* ----- FOOTER ----- */
    void setFooter(String footerText);

    /* ----- NAV + MENU ----- */
    void setNav(void (*functionLeft)(), void (*functionRight)());
    void setNav(void (*navFunction)(char* param));
    void setNav(void (**navFunctions)());
    
    void setMenuKeyMap(String* keyMapVals); // map keypresses to actions and return pressed key
    void setMenuScroller(String* scrollerVals);
    void setMenuScroller(String* scrollerVals, uint16_t numScrollerVals);
    
    /* ----- UPDATE ----- */
    void clear();
    void display();     // clear & update screen once
    void autoDisplay(); // continuous refresh until event



    private:

        /* ----- HEADER ----- */
        String headerText; String subHeaderText;
        bool headerEnabled = false;

        /* ----- FOOTER ---- */
        String footerText;
        bool footerEnabled = false;

        /* ----- NAV + MENU ----- */
        bool navEnabled = false;
        
        uint8_t menuType = 0;

        void (*functionLeft)();
        void (*functionRight)();
        void (*navFunction)(char* param);
        void (**navFunctions)();
        //void (*sfunction)(char* param);

        uint8_t scrollerIndex;

        String* scrollerVals; uint16_t numScrollerVals;
        String* keyMapVals;

        /* ----- UPDATE ----- */
        void updateHeader();
        void updateFooter();
        void updateNav();
    
};

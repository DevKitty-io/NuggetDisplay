#define up_btn 9 // up button
#define dn_btn 18 // down button
#define lt_btn 11 // left button
#define rt_btn 7 // right button

// import Interface library and screen library
#include "Nugget_Interface.h"
#include "Nugget_Buttons.h"

// Navigation 
#define keyMapEnabled   menuType==1
#define scrollerEnabled menuType==2

int8_t press = -1;

Nugget_Buttons nuggButtons(up_btn,dn_btn,lt_btn,rt_btn);

Nugget_Interface::Nugget_Interface() {

}

/* --------------- HEADER --------------- */

// set a single header text value and left align it
void Nugget_Interface::setHeader(String headerText){
    headerEnabled = true;
    this->headerText = headerText;
}

// set header + subheader text
void Nugget_Interface::setHeader(String headerText, String subHeaderText){
    headerEnabled = true;
    this->headerText = headerText;
    this->subHeaderText = subHeaderText;
}

/* --------------- FOOTER --------------- */

// set footer text
void Nugget_Interface::setFooter(String footerText) {
  footerEnabled = true;
  this->footerText = footerText;
  this->footerText.toUpperCase(); // stylistic 
}

/* --------------- NAVIGATION --------------- */

// set LEFT and/or RIGHT navigation for most interfaces
void Nugget_Interface::setNav(void (*functionLeft)(), void (*functionRight)()) {
  navEnabled = true;
  this->functionLeft = functionLeft;
  this->functionRight = functionRight;
}

// set UP, DOWN, LEFT, RIGHT navigation for KeyMap menus
void Nugget_Interface::setNav(void (**navFunctions)()) {
    navEnabled = true;
    this->navFunctions = navFunctions;
}

void Nugget_Interface::setNav(void (*navFunction)(char* param)) {
    navEnabled = true;
    this->navFunction = navFunction;
}

/* --------------- MENU --------------- */

// Menu Type 1
void Nugget_Interface::setMenuKeyMap(String* keyMapVals) {
    this->keyMapVals = keyMapVals;
    menuType = 1;
    navEnabled = true;
}

// Menu Type 2
void Nugget_Interface::setMenuScroller(String* scrollerVals) {
    this->scrollerVals = scrollerVals;
    menuType = 2;
    navEnabled = true;
}

/* --------------- UPDATE --------------- */

void Nugget_Interface::updateFooter() {
    if (navEnabled && menuType>0) { footerEnabled = true; }

    if (footerEnabled) {
        ::display.drawLine(0, 54, 127, 54);
        ::display.drawLine(0, 53, 127, 53);
        
        // draw centered footer text
        ::display.drawString((127-::display.getStringWidth(footerText))/2, 53, footerText);
        
        if (functionLeft) {
            ::display.drawRect(9,55,2,9);
            ::display.fillTriangle(1, 60, 4, 57, 4, 63);
        }
        if (functionRight) {
            ::display.drawRect(117,55,2,9);
            ::display.fillTriangle(126, 60, 123, 57, 123, 63);
        }
    }
}

void Nugget_Interface::updateHeader() {

    if (headerEnabled && menuType!=2) {
        ::display.drawLine(0,13,127,13);
        ::display.drawLine(0,14,127,14);

        
        // if subHeader parameter provided
        if(!subHeaderText.equals("")) {
            subHeaderText = subHeaderText.length()>10 ? subHeaderText.substring(0,7)+"..." : subHeaderText;
            
            uint8_t textDivider = 123-::display.getStringWidth(subHeaderText);
            ::display.drawString(textDivider+4,0,subHeaderText);
            ::display.drawLine(textDivider,0,textDivider,14);
            ::display.drawLine(textDivider+1,0,textDivider+1,14);
        }

        headerText = headerText.length()>(20-subHeaderText.length()) ? headerText.substring(0,17-subHeaderText.length())+"..." : headerText;
        ::display.drawString(0,0,headerText);
    }
}

void Nugget_Interface::updateNav() {
    String direction[] = {"UP", "LT", "RT", "DN" };
    for (int i=0; i<4; i++) {
        if (keyMapVals[i].length() < 10) { ::display.drawString(0,10*i,direction[i]+":"+keyMapVals[i]); }
        else { ::display.drawString(0,10*i,direction[i]+":"+keyMapVals[i].substring(0,7)+"..."); }
    }
}

/* --------------- DISPLAY --------------- */

void Nugget_Interface::clear() { ::display.clear(); }
void Nugget_Interface::display() { ::display.display(); }

// updates Display & Navigation
void Nugget_Interface::autoDisplay() { // updates UI display and loops until button input provided
    press = -1;

    if (navEnabled) {

        /* 
            ## Key Map ##
            wait for any keypress, and navigate to a function
        */
        if (keyMapEnabled) {
            while (press==-1) {
                clear();
                press = nuggButtons.getPress();
                updateFooter();
                updateNav();
                display();
            }
            
            // pass value to single function
            if (navFunction) {
                (*navFunction)("test");
                // pass keyMapVals[press-1]
            }
            // multiple functions
            else {
                (*navFunctions[press-1])();
            }

        }   

        // Scroller Menu
        else if (scrollerEnabled) {
            while (true) {

            }
        }

        // Regular Navigation
        else {
            clear();
            updateHeader();
            updateFooter();
            display();
        } 

    }
}
/*


    if (navEnabled) {
        while (!(nuggButtons.ltPressed() or nuggButtons.rtPressed())) {
            press = nuggButtons.getPress();
            ::display.clear();

            updateHeader();
            updateFooter();

            if (keyMapEnabled) {
                setMenuKeyMap(keyMapVals);
            }
            ::display.display();
        }
    }
    else if (keyMapEnabled) {
        while (press==-1) {

            press = nuggButtons.getPress();
            ::display.clear();

            updateHeader();
            updateFooter();

            if (keyMapEnabled) {
                setMenuKeyMap(keyMapVals);
            }
            ::display.display();

        }
    }

    ::display.clear();
    ::display.display();
    */
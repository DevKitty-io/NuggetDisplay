#include "Nugget_Interface.h"
// #include "Graphics.h" 
// #include "Attacks.h"

// String selectPool[50];
// uint8_t selectPoolCount = 0;
int8_t press = -1;


Nugget_Interface::Nugget_Interface() {

}

void Nugget_Interface::addKeyMap(String* keyMapVals) {
    this->keyMapVals = keyMapVals;
    keyMapEnabled = true;
    // ::display.fillTriangle(0,0,0,9,5,4);
    // ::display.fillTriangle(0,10,0,19,5,14);
    // ::display.fillTriangle(0,20,0,29,5,24);
    // ::display.fillTriangle(0,30,0,39,5,34);

    // ::display.drawString(7,0,keyMapVals[0]);
    // ::display.drawString(7,10,keyMapVals[1]);
    // ::display.drawString(0,20,keyMapVals[2]);
    // ::display.drawString(0,30,keyMapVals[3]);
    String direction[] = {"UP", "LT", "RT", "DN" };
    for (int i=0; i<4; i++) {
        if (keyMapVals[i].length() < 10) { ::display.drawString(0,10*i,direction[i]+":"+keyMapVals[i]); }
        else { ::display.drawString(0,10*i,direction[i]+":"+keyMapVals[i].substring(0,7)+"..."); }
    }
}

// // Basic Lateral Scrolling Menu w/ Arrows
// MenuInterface::MenuInterface(String menuText, int8_t numArrows) {
//   this->menuText = menuText;
//   this->numArrows = numArrows;

//   // init();
// }

// void MenuInterface::addLoader(boolean ready, uint8_t timeEstimate) {
//   while (!ready){
//     ::display.clear();
//     updateFooter();
//     display.drawString(0,0,"Loading...");

//     ::display.display();
//   }
// }

// void MenuInterface::addTitle() {
//   menuText.toUpperCase();

//   ::display.drawXbm(Navbar_Outline_x_hot, Navbar_Outline_y_hot, Navbar_Outline_width, Navbar_Outline_height, Navbar_Outline_bits);
//   ::display.drawXbm(Arrow_Left_x_hot, Arrow_Left_y_hot, Arrow_Left_width, Arrow_Left_height, Arrow_Left_bits);

//   if (numArrows != 1) {
//     ::display.drawXbm(Arrow_Right_x_hot, Arrow_Right_y_hot, Arrow_Right_width, Arrow_Right_height, Arrow_Right_bits);
//   }

//   if (::display.getStringWidth(menuText) < 101) {
//     ::display.drawString(((104 - ::display.getStringWidth(menuText)) / 2) + 12, 54, menuText);
//   }
// }

// void MenuInterface::addHeader(String headerText, String secondaryText) {
//   this->headerText = headerText;
//   this->secondaryText = secondaryText;
//   headerEnabled = true;

//   ::display.drawXbm(Window_Header_x_hot, Window_Header_y_hot, Window_Header_width, Window_Header_height, Window_Header_bits);
//   ::display.drawString(3, 0, headerText);
//   ::display.drawString(94, 0, secondaryText);
// }

// bool notInSelectPool(String selectText) {
//   for (int i=0; i<selectPoolCount; i++) {
//     if (selectText.equals(selectPool[i])) return false;
//   }
//   return true;  
// }

// void MenuInterface::addScroller(String* scrollerTextValues, uint8_t numScrollerValues) {
//   this->scrollerTextValues = scrollerTextValues;
//   this->numScrollerValues = numScrollerValues;

//   scrollerMenu = true; scrollerSelectMenu = false;
//   scrollerPos = 0;
// }

// void MenuInterface::addScrollerSelect(String* scrollerTextValues, uint8_t numScrollerValues) {
//   this->scrollerTextValues = scrollerTextValues;
//   this->numScrollerValues = numScrollerValues;

//   if (this->numScrollerValues ==0) {
//     Serial.println("0 found");
//     scrollerTextValues[this->numScrollerValues] = "Rescan: 0 Found";
//     this->numScrollerValues++;
//   }

//   scrollerTextValues[this->numScrollerValues] = "...";
//   scrollerTextValues[this->numScrollerValues+1] = "* START ATTACK *";
//   this->numScrollerValues+= 2;

//   scrollerMenu = true; scrollerSelectMenu = true;
//   scrollerPos = 0;
// }

// void MenuInterface::addScroller(String* scrollerTextValues, void (**scrollerMethodList)(), uint8_t numScrollerValues) {
//   this->scrollerTextValues = scrollerTextValues;
//   this->numScrollerValues = numScrollerValues;
//   this->scrollerMethodList = scrollerMethodList;

//   scrollerMenu = true; scrollerSelectMenu = false;
//   scrollerPos = 0;
// }

// void MenuInterface::updateScroller() {

//   for (uint8_t i = (scrollerPos / 5) * 5; i < ((scrollerPos / 5) * 5) + 5; i++) {
//     if (i >= numScrollerValues) break;
//     display.drawString(4, (i % 5) * 10, scrollerTextValues[i]);
//   }

//   // draw selector line
//   display.drawLine(0, (scrollerPos % 5 * 10) + 2, 0, (scrollerPos % 5 * 10) + 10);
// }


// // add scrolling footer here
// void MenuInterface::addFooter(String* footerTextValues, unsigned char* scrollerIconBits[]) {
//   this->footerTextValues = footerTextValues;
//   this->scrollerIconBits = scrollerIconBits;
//   footerEnabled = true; dynamicFooter = true;
// }

void Nugget_Interface::addFooter(String footerText) {
  this->footerText = footerText;
  footerEnabled = true;  dynamicFooter = false;
}

void Nugget_Interface::addNav(void (*function1)()) {
  this->function1 = function1;
  navCount = 1;
}   

void Nugget_Interface::addNav(void (*sfunction)(char* param)) {
    this->sfunction = sfunction;
}

// void MenuInterface::addNav(void (*function1)(), void (*function2)()) {
//   this->function1 = function1;
//   this->function2 = function2;
//   navCount = 2;
// }

// void MenuInterface::addDashboard(unsigned char* dbGraphics, String* dbText, uint8_t dbCount) {
//   this->dbGraphics = dbGraphics;
//   this->dbText = dbText;
//   this->dbCount = dbCount;
//   ::display.drawXbm(0, 15, 128, 38, dbGraphics); // graphic must match exact height
//   // for (int i=0; i<dbCount; i++) {
//   //   //
//   // }
// }

// void MenuInterface::updateFooter() {

//   if (footerEnabled) {
//     if (dynamicFooter) {
//       footerText = footerTextValues[scrollerPos];
//       footerText.toUpperCase();

//       // divider for arrow
//       ::display.drawLine(0, 54, 127, 54);
//       ::display.drawLine(0, 53, 127, 53);
//       ::display.drawLine(118, 54, 118, 63);
//       ::display.drawLine(117, 54, 117, 63);


//       ::display.drawXbm(0,0,128,64,scrollerIconBits[scrollerPos]);
//       ::display.drawXbm(Arrow_Right_x_hot,Arrow_Right_y_hot,Arrow_Right_width,Arrow_Right_height,Arrow_Right_bits);
        

//     }
//     else {
//       footerText.toUpperCase();
//       ::display.drawXbm(Navbar_Outline_x_hot, Navbar_Outline_y_hot, Navbar_Outline_width, Navbar_Outline_height, Navbar_Outline_bits);
      
//       if (navCount==2){
//         ::display.drawXbm(Arrow_Right_x_hot,Arrow_Right_y_hot,Arrow_Right_width,Arrow_Right_height,Arrow_Right_bits);
//       }
//       ::display.drawXbm(Arrow_Left_x_hot,Arrow_Left_y_hot,Arrow_Left_width,Arrow_Left_height,Arrow_Left_bits);
      
//       if (::display.getStringWidth(footerText) < 101) {
//         ::display.drawString(((104 - ::display.getStringWidth(footerText)) / 2) + 12, 54, footerText);
//       }
//       else {
//         ::display.drawString(56,54,"...");
//       }
//     }
//   }
// }

// // temporary method
// void MenuInterface::addSimpleMonitor(uint8_t monitorCount) {
//   this->monitorCount = monitorCount;
//   monitorEn = true;
//   ::display.drawString(0,17,"Deauthing "+(String) monitorCount);
//   ::display.drawString(0,27,"clients from");
//   String tmpBSSID = apList[scrollIndex][0];
//   tmpBSSID.replace(":","");
//   ::display.drawString(0,37,tmpBSSID);
//   ::display.drawXbm(4,0,128,64,attack_bits);
//   // wifiScanner.deauthClients();

// }

// void MenuInterface::updateDisplay(bool override) { // override variable doesn't even matter

//   updateFooter();
//   ::display.display();
//   while (true) {
//     int8_t press = nuggButtons.getPress();

//     if (nuggButtons.ltPressed()) {
//       (*function1)();
//     }
//     // else if (nuggButtons.rtPressed()) {
//     //   (*function2)();
//     // }

//     delay(0);
//   }
// }

// void MenuInterface::updateDisplayManual() {
//     // while (true) {
//     ::display.clear();

//     int8_t press = nuggButtons.getPress();

//     if (scrollerMenu) {
      
//       // basic up & down scrolling actions
//       if (nuggButtons.upPressed() and scrollerPos > 0) {
//         scrollerPos--;
//         Serial.println("Scroller");
//       }
//       else if (nuggButtons.dnPressed() and scrollerPos < numScrollerValues - 1) {
//         scrollerPos++;
//         Serial.println("sdfsdfs");
//       }

//       // check nav list or check function list 
      
//       if (dynamicFooter) { // dynamic Menu
//          if (nuggButtons.rtPressed()) {
//         (*scrollerMethodList[scrollerPos])();
//         }
//       }
//       else {
         
//       }

//       if (scrollerSelectMenu){
//         if (nuggButtons.ltPressed()) {
//           (*function1)();
//         }
//         else if (nuggButtons.rtPressed()) {
//           Serial.println(scrollerTextValues[scrollerPos].indexOf("*"));
          
//           if (scrollerPos<numScrollerValues-2 and scrollerTextValues[scrollerPos].indexOf("Rescan")>=0) {
//             rescanClients = true;
//             Attacks::selectClients();
//             // wifiScanner.scanClients(25);
//           }
//           else if (scrollerPos<numScrollerValues-2 and !(scrollerTextValues[scrollerPos].indexOf("*")>=0)) {
//             scrollerTextValues[scrollerPos] = "* "+(scrollerTextValues[scrollerPos]);
//             selectPoolCount++;
//           }
//           else if (scrollerPos<numScrollerValues-2) {
//             scrollerTextValues[scrollerPos].replace("* ","");
//             selectPoolCount--;
//           }
//           else if (scrollerPos == numScrollerValues-1 and selectPoolCount>0){
//             (*function2)();
//           }

//         }

//       }

     
      
//       updateScroller();
//     }

//         //dynamic footer already points to a function... right? 
//         if(!dynamicFooter and !scrollerSelectMenu) {
//           if (nuggButtons.ltPressed()) {
//             Serial.println("Left press, executing function 1");
//             (*function1)();
//           }
//           else if (nuggButtons.rtPressed() and navCount==2) {
//             scrollIndex = scrollerPos; // temporary exposed variable
//             Serial.println("Right press, executing function 2");
//             (*function2)();
//           }
//         }

//     if (headerEnabled) {
//       addHeader(headerText, secondaryText);
//     }

//     // update to support list refresh
//     updateFooter();
//     //    addDashboard(dbGraphics, dbText, dbCount);


//  if (monitorEn) {
//         // Serial.println("monitor enabled!");
//         addSimpleMonitor(monitorCount);
//       }
//     ::display.display();

//     delay(0);
//   // }
// }
void Nugget_Interface::updateFooter() {
    this->footerText = footerText;
    ::display.drawLine(0, 54, 127, 54);
    ::display.drawLine(0, 53, 127, 53);
    
    ::display.drawString(0,54,"Dir:");
    ::display.drawString(25, 54, footerText);
    ::display.display();
}

void Nugget_Interface::updateNav() {
    // 1, 2, 3, 4
    if (keyMapEnabled and press!=-1) {
        
        // re-map keys for interface
        uint8_t rstring;
        if      (press==1) { rstring=0; } // up->0
        else if (press==2) { rstring=3; } // dn->3
        else if (press==3) { rstring=1; } // lt->1
        else if (press==4) { rstring=2; } // rt->2

        if (keyMapVals[rstring].equals("")) return;
        ::display.clear();

        String paramStr = keyMapVals[rstring];

        uint8_t paramLen = paramStr.length()+1;
        char char_array[paramLen];

        paramStr.toCharArray(char_array, paramLen);
        sfunction(char_array); // call a function passing the keypress String
    }
}

void Nugget_Interface::updateDisplay() {
    ::display.display();
    if (keyMapEnabled) {
        addKeyMap(keyMapVals);
    }
    updateFooter();
    updateNav();
}

void Nugget_Interface::autoUpdateDisplay() { // updates UI display and loops until button input provided
    ::display.display();

    while (true) {

    press = nuggButtons.getPress();

    // if(press==1) {
    //     ::display.clear();
    //     ::display.display();
    //     break;
    // }

    updateFooter();
    updateNav();

    // delay(0);

//     if (scrollerMenu) {
      
//       // basic up & down scrolling actions
//       if (nuggButtons.upPressed() and scrollerPos > 0) {
//         scrollerPos--;
//         Serial.println("Scroller");
//       }
//       else if (nuggButtons.dnPressed() and scrollerPos < numScrollerValues - 1) {
//         scrollerPos++;
//         Serial.println("sdfsdfs");
//       }

//       // check nav list or check function list 
      
//       if (dynamicFooter) { // dynamic Menu
//          if (nuggButtons.rtPressed()) {
//         (*scrollerMethodList[scrollerPos])();
//         }
//       }
//       else {
         
//       }

//       if (scrollerSelectMenu){
//         if (nuggButtons.ltPressed()) {
//           (*function1)();
//         }
//         else if (nuggButtons.rtPressed()) {
//           Serial.println(scrollerTextValues[scrollerPos].indexOf("*"));
          
//           if (scrollerPos<numScrollerValues-2 and scrollerTextValues[scrollerPos].indexOf("Rescan")>=0) {
//             rescanClients = true;
//             Attacks::selectClients();
//             // wifiScanner.scanClients(25);
//           }
//           else if (scrollerPos<numScrollerValues-2 and !(scrollerTextValues[scrollerPos].indexOf("*")>=0)) {
//             scrollerTextValues[scrollerPos] = "* "+(scrollerTextValues[scrollerPos]);
//             selectPoolCount++;
//           }
//           else if (scrollerPos<numScrollerValues-2) {
//             scrollerTextValues[scrollerPos].replace("* ","");
//             selectPoolCount--;
//           }
//           else if (scrollerPos == numScrollerValues-1 and selectPoolCount>0){
//             (*function2)();
//           }

//         }

      }

     
      
//       updateScroller();
    }

//         //dynamic footer already points to a function... right? 
//         if(!dynamicFooter and !scrollerSelectMenu) {
//           if (nuggButtons.ltPressed()) {
//             Serial.println("Left press, executing function 1");
//             (*function1)();
//           }
//           else if (nuggButtons.rtPressed() and navCount==2) {
//             scrollIndex = scrollerPos; // temporary exposed variable
//             Serial.println("Right press, executing function 2");
//             (*function2)();
//           }
//         }

//     if (headerEnabled) {
//       addHeader(headerText, secondaryText);
//     }

//     // update to support list refresh
//     updateFooter();
//     //    addDashboard(dbGraphics, dbText, dbCount);


//  if (monitorEn) {
//         // Serial.println("monitor enabled!");
//         addSimpleMonitor(monitorCount);
//       }
//     ::display.display();

//     delay(0);
//   }
// }

#include "SH1106Wire.h"
#include "graphics.h" 
#include "FunctionTester.h"
#include "font.h"


SH1106Wire display(0x3C, 33, 35);

void setup() {
    Serial.begin(115200);
    display.init();
    display.flipScreenVertically();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(DejaVu_Sans_Mono_10);
    
    FunctionTester::scrollerTester();
}


void loop() {
  
  // put your main code here, to run repeatedly:

}

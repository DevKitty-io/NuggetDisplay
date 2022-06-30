#include "FunctionTester.h"
#include "Nugget_Interface.h" 

FunctionTester::FunctionTester() {

}

// print char to header
void FunctionTester::stringTester(char* param) {
  Nugget_Interface stringScreen;
  stringScreen.setHeader(param,"123");
  stringScreen.setFooter("Icon Tester");
  
  stringScreen.setNav(footerTester,keyMapTester);
  stringScreen.autoDisplay();
}

// map to 4 unique functions, for now
void FunctionTester::keyMapTester() {
  String osList[] = {"Icon", "Footer", "Windows", "Starred"};
  void (*interfaces[256])(void) = {&iconTester, &footerTester, &iconTester, &iconTester};
  
  Nugget_Interface combo;
  combo.setMenuKeyMap(osList); // needs a function map
  combo.setNav(stringTester);
  combo.setFooter("Multi KeyMap");
  combo.autoDisplay();
}

void FunctionTester::iconTester() {
  Nugget_Interface iconScreen;
  iconScreen.setHeader("Main Header","123");
  iconScreen.setFooter("Icon Tester");
  
  iconScreen.setNav(footerTester,keyMapTester);
  iconScreen.autoDisplay();
}

void FunctionTester::footerTester() {
  Nugget_Interface footerScreen;
  footerScreen.setFooter("Footer Tester");
  footerScreen.setNav(footerTester,keyMapTester);
  footerScreen.autoDisplay();
}

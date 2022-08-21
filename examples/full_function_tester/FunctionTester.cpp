#include "FunctionTester.h"
#include "NuggetDisplay.h" 

FunctionTester::FunctionTester() {

}

// print char to header
void FunctionTester::stringTester(char* param) {
  NuggetDisplay stringScreen;
  stringScreen.setHeader(param,"123");
  stringScreen.setFooter("Icon Tester");
  
  stringScreen.setNav(footerTester,keyMapTester);
  stringScreen.autoDisplay();
}

// map to 4 unique functions, for now
void FunctionTester::keyMapTester() {
  String osList[] = {"Icon", "Footer", "Windows", "Starred"};
  void (*interfaces[256])(void) = {&iconTester, &footerTester, &iconTester, &iconTester};
  
  NuggetDisplay combo;
  combo.setMenuKeyMap(osList); // needs a function map
  combo.setNav(stringTester);
  combo.setFooter("Multi KeyMap");
  combo.autoDisplay();
}

void FunctionTester::iconTester() {
  NuggetDisplay iconScreen;
  iconScreen.setHeader("Main Header","123");
  iconScreen.setFooter("Icon Tester");
  
  iconScreen.setNav(footerTester,keyMapTester);
  iconScreen.autoDisplay();
}

void FunctionTester::footerTester() {
  NuggetDisplay footerScreen;
  footerScreen.setFooter("Footer Tester");
  footerScreen.setNav(footerTester,keyMapTester);
  footerScreen.autoDisplay();
}

void FunctionTester::scrollerTester() {
  String map[] = {"First","Second","Third","Fourth","Fifth","Sixth","Seven","Eight","Nine"};

  NuggetDisplay scrollerScreen;
  // scrollerScreen.setHeader("Main Header","123");
  scrollerScreen.setFooter("Scrolling");
  scrollerScreen.setMenuScroller(map, 9);
  scrollerScreen.setNav(footerTester,keyMapTester);
  scrollerScreen.autoDisplay();
}
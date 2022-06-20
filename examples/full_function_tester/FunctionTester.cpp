#include "FunctionTester.h"
#include "Nugget_Interface.h" 

FunctionTester::FunctionTester() {

}

void FunctionTester::keyMapTester() {
  String osList[] = {"Meow", "Mac", "Windows", "Starred"};
  Nugget_Interface combo;
  combo.addMenuKeyMap(osList); // needs a function map
  combo.setFooter("Directory");
  combo.updateDisplay();
}

void FunctionTester::iconTester() {
  Nugget_Interface iconScreen;
  iconScreen.setHeader("Main Header","123");
  iconScreen.setFooter("Icon Tester");
  
  iconScreen.setNav(footerTester,footerTester);
  iconScreen.updateDisplay();
}

void FunctionTester::footerTester() {
  Nugget_Interface footerScreen;
  footerScreen.setFooter("Footer Tester");
  footerScreen.updateDisplay();
}

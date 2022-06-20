# Nugget_Screen

## Function Documentation

`void .init()`

### Header
`void .setHeader(String headerText)`  
`void .setHeader(String headerText, String subHeaderText)`  

### Footer
`void .setFooter(String footerText)`

### Navigation
`void .addMenuKeyMap(String* keyMapVals, void (*function1)())`
`void .addMenuScroller()`
`void .addLoader()`

`void .setNav(void (*functionLeft)(),void (*functionRight)())`

### Update
`void .update()`
`void .autoUpdate()`

`void.updateHeader()`
`void.updateFooter()`
`void.updateNav()`
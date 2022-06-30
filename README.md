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

### Display 

### Update
`void .update()`
`void .autoUpdate()`

`void.updateHeader()`
`void.updateFooter()`

### Variables
`bool headerEnabled`
`bool footerEnabled`

`bool navEnabled`

`uint8_t menuType` n
| Number | Menu |
| --- | --- |
| 0 | None  |
| 1 | Left / Right Navigation |
| 2 | Scroller |
| 3 | KeyMap |

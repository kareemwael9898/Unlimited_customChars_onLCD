#include <LiquidCrystal.h>
#define rs 12
#define en 10
#define d4 8
#define d5 6
#define d6 4
#define d7 2

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/*********************************************/
byte sentence[][8] = {

  { B10001, B10101, B01110, B00100, B01110, B01010, B00000, B00000 },
  { B00000, B10001, B10101, B01110, B00100, B01110, B01010, B01010 },
  { B10001, B10101, B01110, B00100, B01110, B01010, B00000, B00000 },
  { B00000, B10001, B10101, B01110, B00100, B01110, B01010, B01010 },
  { B00000, B00000, B10101, B01110, B00100, B01110, B01010, B01010 },
  { B00000, B10001, B10101, B01110, B00100, B01110, B01010, B01010 },
  { B00000, B00000, B10101, B11111, B00100, B01110, B01010, B01010 },
  { B00000, B00000, B00100, B11111, B10101, B01110, B01010, B01010 },
  { B00000, B00000, B00100, B01110, B10101, B11111, B01010, B01010 },
  { B00000, B00000, B00100, B00100, B10101, B11111, B11011, B01010 },
  { B00000, B00000, B00100, B00100, B10101, B11111, B11011, B01010 },
  { B00000, B00000, B00100, B00100, B00100, B11111, B11011, B11011 },
  { B00000, B00000, B00000, B00100, B00100, B11111, B11111, B11011 },
  { B00000, B00000, B00000, B00000, B00100, B11111, B11111, B11011 },

  { B00000, B00000, B00000, B00000, B00000, B11111, B11111, B11111 },
  { B00000, B00000, B00000, B00000, B11111, B11111, B11111, B11111 },
  { B00000, B00000, B00000, B11111, B11111, B11111, B11111, B11110 },
  { B00000, B00000, B11111, B11111, B11111, B11111, B11110, B11100 },
  { B00000, B11111, B11111, B11111, B11111, B11110, B11100, B11000 },
  { B11111, B11111, B11111, B11111, B11110, B11100, B11000, B00000 },
  { B11111, B11111, B11111, B11111, B11110, B11100, B11000, B10000 },
  { B11111, B11111, B11111, B11111, B11111, B11100, B10000, B10000 },
  { B11111, B11111, B11111, B11111, B11111, B11110, B11000, B10000 },
  { B11111, B11111, B11111, B11111, B11111, B11110, B11100, B10000 },
  { B11111, B11111, B11111, B11111, B11111, B11110, B11100, B11000 },
  { B11111, B11111, B11111, B11111, B11111, B11111, B11100, B11000 },
  { B11111, B11111, B11111, B11111, B11111, B11111, B11100, B11100 },
  { B11111, B11111, B11111, B11111, B11111, B11111, B11110, B11100 },
  { B11111, B11111, B11111, B11111, B11111, B11111, B11110, B11110 },
  { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11110 },

  { B00000, B00000, B01000, B01000, B01010, B01000, B01000, B00000 },
  { B00000, B00000, B01110, B01010, B01110, B00010, B00010, B00000 },
  { B00000, B00000, B00100, B01010, B01010, B01010, B01010, B00000 },
  { B00000, B00000, B01010, B01010, B01010, B01010, B00100, B00000 },
  { B00000, B00000, B11110, B00010, B00010, B00010, B00010, B00000 },
  { B00000, B00000, B01100, B10010, B10010, B01100, B00000, B00000 },
  { B00000, B00000, B01110, B10000, B01000, B10000, B01110, B00000 },
  { B00000, B00000, B10101, B11110, B10000, B10000, B10000, B00000 },
  { B00000, B00000, B01110, B10000, B01000, B00100, B00010, B00000 },
  { B00000, B00000, B00100, B00100, B00100, B00100, B00100, B00000 },


};
/****************************************/

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int writeDelay = 250;
  // The position of first char on the lcd
  int startPos = 11;                                           // It dependes on size of SENTENCE & Must be >= Number of custom characters
  int currentPos = startPos;                                   // The position of the cursor
  int firstChar = sizeof(sentence) / sizeof(sentence[0]) - 1;  // Get the number of custom characters
  int charsOnLCD = 0;  // Current number of characters on the LCD
  
  for (int i = firstChar; i > 0; i--) {
    if (charsOnLCD != 8) {
      lcd.createChar(charsOnLCD, sentence[i]);
      lcd.setCursor(currentPos--, 0);
      lcd.write(charsOnLCD++);
    } else {
      scrollFrom(i);
      lcd.setCursor(8, 0);
    }
    delay(writeDelay);
  }
  delay(2000);
  lcd.clear();
};
void scrollFrom(int nextChar) {
  for (int i = 0; i < 8; i++) {
    lcd.createChar(i, sentence[--nextChar + 7]);
    // delay(100);
  }
}

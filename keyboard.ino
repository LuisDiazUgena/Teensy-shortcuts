
// include the library code:
#include <LiquidCrystal.h>
#include <Bounce.h>
#include <usb_keyboard.h>

int pinBtn1 = 15,pinBtn2 = 14;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

//Crea botones con debounce por software
Bounce btn1 = Bounce(pinBtn1,10);
Bounce btn2 = Bounce(pinBtn2,10);

void setup() {

  // set up the LCD's number of columns and rows: 
  lcd.begin(20,4);
  
  pinMode(pinBtn1, INPUT_PULLUP);
  pinMode(pinBtn2, INPUT_PULLUP);
  // Print a message to the LCD.
  lcd.print("Teensy Shorcuts!");
  delay(1000);
  lcd.clear();
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("Profile: ");
  lcd.setCursor(9,0);

  //Funcion que modifque los perfiles -- todo --

  lcd.print("Arduino IDE");

  btn1.update();
  btn2.update();
  
  if (btn1.risingEdge()){
    Serial.println("risingEdge btn1");
    Keyboard.set_modifier(MODIFIERKEY_CTRL);
    Keyboard.set_key1(KEY_R);
    Keyboard.send_now();

  }
  
  if (btn2.risingEdge()){
    Serial.println("risingEdge btn2");
    Keyboard.set_modifier(MODIFIERKEY_CTRL);
    Keyboard.set_key1(KEY_U);
    Keyboard.send_now();

  }  
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
  
}

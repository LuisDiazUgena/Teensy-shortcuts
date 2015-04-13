/*

USB keyboard shortcut manager
Teensy 3.1 working as usb keyboard
Luis Diazains...


*/
struct Profile {

  char name[20];
  char shortcut1[10];
  char shortcut2[10];
  char shortcut3[10];
  char shortcut4[10];
  char shortcut5[10];
  char shortcut6[10];

};

//Libraries
#include <LiquidCrystal.h>
#include <Bounce.h>
#include <usb_keyboard.h>
#include <string.h>

int pinBtn1 = 0, pinBtn2 = 1, pinBtn3 = 2, pinBtn4 = 3, pinBtn5 = 4, pinBtn6 = 5;
int pinPS = 15;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

//Create buttons with software debounce
Bounce btn1 = Bounce(pinBtn1, 10);
Bounce btn2 = Bounce(pinBtn2, 10);
Bounce btn3 = Bounce(pinBtn3, 10);
Bounce btn4 = Bounce(pinBtn4, 10);
Bounce btn5 = Bounce(pinBtn5, 10);
Bounce btn6 = Bounce(pinBtn6, 10);
Bounce btnPS = Bounce(pinPS, 10);

//Profile Selector
int aktProfile = 2, lastProfile = 0;
int profile_number = 3;

//Profiles

struct Profile profile1;
struct Profile profile2;
struct Profile profile3;
struct Profile profile4;

void setup() {

  pinMode(pinBtn1, INPUT_PULLUP);
  pinMode(pinBtn2, INPUT_PULLUP);
  pinMode(pinBtn3, INPUT_PULLUP);
  pinMode(pinBtn4, INPUT_PULLUP);
  pinMode(pinBtn5, INPUT_PULLUP);
  pinMode(pinBtn6, INPUT_PULLUP);
  pinMode(pinPS, INPUT_PULLUP);

  //pinMode(pinProfileSelector, INPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);

  // Print a message to the LCD.
  lcd.print("Teensy shortcuts!");
  lcd.setCursor(0, 3);
  lcd.print("Luis Diaz");
  delay(1000);
  lcd.clear();

//Add values to the struct

//Initialize profiles

//Profile1
  strcpy (profile1.name, "Arduino IDE");
  strcpy (profile1.shortcut1, "Verify");
  strcpy (profile1.shortcut2, "Upload");
  strcpy (profile1.shortcut3, "Monitor");
  strcpy (profile1.shortcut4, "AutoFormat");

//profile2
  strcpy (profile2.name, "Sublime 3");
  strcpy (profile2.shortcut1, "Fold All");
  strcpy (profile2.shortcut2, "Upload");
  strcpy (profile2.shortcut3, "Monitor");
  strcpy (profile2.shortcut4, "AutoFormat");


  //profile3
  strcpy (profile3.name, "Html Edittor");
  strcpy (profile3.shortcut1, "h2");
  strcpy (profile3.shortcut2, "em");
  strcpy (profile3.shortcut3, "strong");
  strcpy (profile3.shortcut4, "pre Arduin");

}

void loop() {


  btnPS.update();

  if (btnPS.risingEdge()) {
    Serial.println("NextProfile");
    aktProfile++;
    if (aktProfile > profile_number) {
      aktProfile = 1;
    }
  }

  printProfile(aktProfile);
  profileActions(aktProfile);

}
//

void profileActions(int aktProfile) {

  btn1.update();
  btn2.update();
  btn3.update();
  btn4.update();
  btn5.update();
  btn6.update();


  switch (aktProfile) {
  // Profile 1
  case 1:

    if (btn1.risingEdge()) {
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.set_key1(KEY_R);
      Keyboard.send_now();
    }
    if (btn2.risingEdge()) {
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.set_key1(KEY_U);
      Keyboard.send_now();
    }
    if (btn3.risingEdge()) {
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.send_now();
      Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT );
      Keyboard.set_key1(KEY_M);
      Keyboard.send_now();
    }
    if (btn4.risingEdge()) {
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.set_key1(KEY_T);
      Keyboard.send_now();
    }
    break;
  // Profile 2
  case 2:
    if (btn1.risingEdge()) {
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.send_now();
      Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT );
      Keyboard.set_key1(KEY_D);
      Keyboard.send_now();
    }
    if (btn2.risingEdge()) {
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.send_now();
      Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT );
      Keyboard.set_key1(KEY_U);
      Keyboard.send_now();
    }
    if (btn3.risingEdge()) {
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.send_now();
      Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT );
      Keyboard.set_key1(KEY_M);
      Keyboard.send_now();
    }
    if (btn4.risingEdge()) {
      // Autoformat working with Sublime Text 2 & 3 AStyle Formatter Plugin by timonwong
      // https://github.com/timonwong/SublimeAStyleFormatter
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.send_now();
      Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT );
      Keyboard.set_key1(KEY_F);
      Keyboard.send_now();
    }
    break;
  // Profile 3
  case 3:

    // Strings profile3
    //String header = "<h2></h2>", em = "<em></em>", pre = "<pre lang=", pre1 = "arduino", pre2 = "></pre>", strong = "<strong></strong>";

    if (btn1.risingEdge()) {
      Keyboard.print("<h2></h2>");
      goingBack(5);
    }

    if (btn2.risingEdge()) {
      Keyboard.print("<em></em>");
      goingBack(5);
    }
    
    if (btn3.risingEdge()) {
      Keyboard.print("<strong></strong>");
      goingBack(9);
    }
    if (btn4.risingEdge()) {
      Keyboard.print("<pre lang=\"arduino\"></pre>");
      goingBack(6);
    }

  }

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();

}

void goingBack(int pos) {

  int aktPos;
  
  for (aktPos = 0; aktPos < pos ; aktPos++) {
    Keyboard.set_key1(KEY_LEFT);
    Keyboard.send_now();
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
  }

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void printProfile(int aktProfile) {

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("Profile: ");
  lcd.setCursor(9, 0);

  if (lastProfile != aktProfile ) {
    lcd.clear();
  }

  lastProfile = aktProfile;

  switch (aktProfile) {
  case 1:
    lcd.print(profile1.name);
    lcd.setCursor(0, 1);
    lcd.print(profile1.shortcut1);
    lcd.setCursor(10, 1);
    lcd.print(profile1.shortcut2);
    lcd.setCursor(0, 2);
    lcd.print(profile1.shortcut3);
    lcd.setCursor(10, 2);
    lcd.print(profile1.shortcut4);
    lcd.setCursor(0, 3);
    lcd.print(profile1.shortcut5);
    lcd.setCursor(10, 3);
    lcd.print(profile1.shortcut6);
    break;
  case 2:
    lcd.print(profile2.name);
    lcd.setCursor(0, 1);
    lcd.print(profile2.shortcut1);
    lcd.setCursor(10, 1);
    lcd.print(profile2.shortcut2);
    lcd.setCursor(0, 2);
    lcd.print(profile2.shortcut3);
    lcd.setCursor(10, 2);
    lcd.print(profile2.shortcut4);
    lcd.setCursor(0, 3);
    lcd.print(profile2.shortcut5);
    lcd.setCursor(10, 3);
    lcd.print(profile2.shortcut6);

    break;
  case 3:
    lcd.print(profile3.name);
    lcd.setCursor(0, 1);
    lcd.print(profile3.shortcut1);
    lcd.setCursor(10, 1);
    lcd.print(profile3.shortcut2);
    lcd.setCursor(0, 2);
    lcd.print(profile3.shortcut3);
    lcd.setCursor(10, 2);
    lcd.print(profile3.shortcut4);
    lcd.setCursor(0, 3);
    lcd.print(profile3.shortcut5);
    lcd.setCursor(10, 3);
    lcd.print(profile3.shortcut6);
    break;
  case 4:
    lcd.print(profile4.name);
    lcd.setCursor(0, 1);
    lcd.print(profile4.shortcut1);
    lcd.setCursor(10, 1);
    lcd.print(profile4.shortcut2);
    lcd.setCursor(0, 2);
    lcd.print(profile4.shortcut3);
    lcd.setCursor(10, 2);
    lcd.print(profile4.shortcut4);
    lcd.setCursor(0, 3);
    lcd.print(profile4.shortcut5);
    lcd.setCursor(10, 3);
    lcd.print(profile4.shortcut6);

    break;
  }
}



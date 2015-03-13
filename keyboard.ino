
struct Profile {

  char name[20];
  char shorcut1[20];
  char shorcut2[20];

};

// include the library code:
#include <LiquidCrystal.h>
#include <Bounce.h>
#include <usb_keyboard.h>
#include <string.h>

int pinBtn1 = 15,pinBtn2 = 14, pinProfileSelector = A2;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

//Create buttons with software debounce
Bounce btn1 = Bounce(pinBtn1,10);
Bounce btn2 = Bounce(pinBtn2,10);

//Profile Selector
int aktProfile,profile_number=2;

//String profile1 = "Arduino IDE", profile2 = "Inkscape";

struct Profile profile1;
struct Profile profile2;

void setup() {

  pinMode(pinBtn1, INPUT_PULLUP);
  pinMode(pinBtn2, INPUT_PULLUP);
  pinMode(pinProfileSelector, INPUT);

  // set up the LCD's number of columns and rows: 
  lcd.begin(20,4);

  // Print a message to the LCD.
  lcd.print("Teensy Shorcuts!");
  lcd.setCursor(0,3);
  lcd.print("Luis Diaz");
  delay(750);
  lcd.clear();

//Add values to the struct

//Initialize profiles

//Profile1
strcpy (profile1.name,"Arduino IDE");
strcpy (profile1.shorcut1,"Compilate");
strcpy (profile1.shorcut2,"Upload");
//profile2
strcpy (profile2.name,"Inkscape");
strcpy (profile1.shorcut1,"test1");
strcpy (profile1.shorcut2,"test2");
}

void loop() {

  aktProfile = selectProfile();
  printProfile(aktProfile);
  profileActions(aktProfile);

}

void profileActions(int aktProfile){

  btn1.update();
  btn2.update();

  switch (aktProfile) {
    case 1:
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
    }          // do something
    break;
    case 2:
      // TODO --> add inkscape shorcuts
      break;

  }

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();

}

int selectProfile(){

  int trimmer = 0;

  trimmer = analogRead(pinProfileSelector);

  if (trimmer < 1023/profile_number){
    return 1;
  }
  else{
    return 2;
  }

}

void printProfile(int aktProfile){

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("Profile: ");
  lcd.setCursor(9,0);

  //Funcion que modifque los perfiles -- todo --

  switch (aktProfile) {
    case 1:
    lcd.print(profile1.name);
    lcd.setCursor(0,1);
    
    break;
    case 2:
    lcd.print(profile2.name);
    break;
  }
}



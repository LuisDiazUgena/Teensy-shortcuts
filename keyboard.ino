
struct Profile {

  char name[20];
  char shorcut1[10];
  char shorcut2[10];
  char shorcut3[10];
  char shorcut4[10];
  char shorcut5[10];
  char shorcut6[10];

};

// include the library code:
#include <LiquidCrystal.h>
#include <Bounce.h>
#include <usb_keyboard.h>
#include <string.h>

int pinBtn1 = 2,pinBtn2 = 3,pinBtn3 = 4, pinBtn4=5, pinProfileSelector = A2;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

//Create buttons with software debounce
Bounce btn1 = Bounce(pinBtn1,10);
Bounce btn2 = Bounce(pinBtn2,10);
Bounce btn3 = Bounce(pinBtn3,10);
Bounce btn4 = Bounce(pinBtn4,10);
//Profile Selector
int aktProfile,profile_number=4;
int lastProfile=0;

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
  
  pinMode(pinProfileSelector, INPUT);

  // set up the LCD's number of columns and rows: 
  lcd.begin(20,4);

  // Print a message to the LCD.
  lcd.print("Teensy Shorcuts!");
  lcd.setCursor(0,3);
  lcd.print("Luis Diaz");
  delay(1000);
  lcd.clear();

//Add values to the struct

//Initialize profiles

//Profile1
strcpy (profile1.name,"Arduino IDE");
strcpy (profile1.shorcut1,"Verify");
strcpy (profile1.shorcut2,"Upload");
strcpy (profile1.shorcut3,"Monitor");
strcpy (profile1.shorcut4,"AutoFormat");

//profile2
strcpy (profile2.name,"Sublime 3");
strcpy (profile2.shorcut1,"Verify");
strcpy (profile2.shorcut2,"Upload");
strcpy (profile2.shorcut3,"Monitor");
strcpy (profile2.shorcut4,"AutoFormat");

/*
//profile3
strcpy (profile3.name,"Profile3");
strcpy (profile3.shorcut1,"test1");
strcpy (profile3.shorcut2,"test2");
strcpy (profile3.shorcut3,"test3");
strcpy (profile3.shorcut4,"test4");
//profile4
strcpy (profile4.name,"Profile4");
strcpy (profile4.shorcut1,"test1");
strcpy (profile4.shorcut2,"test2");
strcpy (profile4.shorcut3,"test3");
strcpy (profile4.shorcut4,"test4");
strcpy (profile4.shorcut6,"test6");
*/
}

void loop() {

  aktProfile = selectProfile();
  printProfile(aktProfile);
  profileActions(aktProfile);

}

void profileActions(int aktProfile){

  btn1.update();
  btn2.update();
  btn3.update();
  btn4.update();

  switch (aktProfile) {
    case 1:
    
    if (btn1.risingEdge()){
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.set_key1(KEY_R);
      Keyboard.send_now();
    }
    if (btn2.risingEdge()){
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.set_key1(KEY_U);
      Keyboard.send_now();
    }
    if (btn3.risingEdge()){
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.send_now();
      Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT );
      Keyboard.set_key1(KEY_M);
      Keyboard.send_now();
    }          
    if (btn4.risingEdge()){
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.set_key1(KEY_T);
      Keyboard.send_now();  
    }
    break;
    case 2:
    if (btn1.risingEdge()){
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.send_now();
      Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT );
      Keyboard.set_key1(KEY_V);
      Keyboard.send_now();
    }
    if (btn2.risingEdge()){
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.send_now();
      Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT );
      Keyboard.set_key1(KEY_U);
      Keyboard.send_now();
    }
    if (btn3.risingEdge()){
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.send_now();
      Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT );
      Keyboard.set_key1(KEY_M);
      Keyboard.send_now();
    }          
    if (btn4.risingEdge()){
      Keyboard.set_modifier(MODIFIERKEY_CTRL);
      Keyboard.send_now();
      Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT );
      Keyboard.set_key1(KEY_O);
      Keyboard.send_now(); 
    }      
    break;

  }

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();

}

int selectProfile(){


  int trimmer = 0;
  int threeshold = 256; //1023/4 = 255

  trimmer = analogRead(pinProfileSelector);
  
  if (trimmer < threeshold){
    return 1;
    }else if(trimmer < 2*threeshold){
      return 2;
      }else if(trimmer < 3*threeshold){
        return 3;
        }else{
          return 4;
        }


      }

      void printProfile(int aktProfile){

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("Profile: ");
  lcd.setCursor(9,0);

  if (lastProfile != aktProfile ){
    lcd.clear();
  }

  lastProfile = aktProfile;

  switch (aktProfile) {
    case 1:
    lcd.print(profile1.name);
    lcd.setCursor(0,1);
    lcd.print(profile1.shorcut1);
    lcd.setCursor(10,1);
    lcd.print(profile1.shorcut2);
    lcd.setCursor(0,2);
    lcd.print(profile1.shorcut3);
    lcd.setCursor(10,2);
    lcd.print(profile1.shorcut4);
    lcd.setCursor(0,3);
    lcd.print(profile1.shorcut5);
    lcd.setCursor(10,3);
    lcd.print(profile1.shorcut6);
    break;
    case 2:
    lcd.print(profile2.name);
    lcd.setCursor(0,1);
    lcd.print(profile2.shorcut1);
    lcd.setCursor(10,1);
    lcd.print(profile2.shorcut2);
    lcd.setCursor(0,2);
    lcd.print(profile2.shorcut3);
    lcd.setCursor(10,2);
    lcd.print(profile2.shorcut4);
    lcd.setCursor(0,3);
    lcd.print(profile2.shorcut5);
    lcd.setCursor(10,3);
    lcd.print(profile2.shorcut6);

    break;
    case 3:
    lcd.print(profile3.name);
    lcd.setCursor(0,1);
    lcd.print(profile3.shorcut1);
    lcd.setCursor(10,1);
    lcd.print(profile3.shorcut2);
    lcd.setCursor(0,2);
    lcd.print(profile3.shorcut3);
    lcd.setCursor(10,2);
    lcd.print(profile3.shorcut4);
    lcd.setCursor(0,3);
    lcd.print(profile3.shorcut5);
    lcd.setCursor(10,3);
    lcd.print(profile3.shorcut6);
    break;
    case 4:
    lcd.print(profile4.name);
    lcd.setCursor(0,1);
    lcd.print(profile4.shorcut1);
    lcd.setCursor(10,1);
    lcd.print(profile4.shorcut2);
    lcd.setCursor(0,2);
    lcd.print(profile4.shorcut3);
    lcd.setCursor(10,2);
    lcd.print(profile4.shorcut4);
    lcd.setCursor(0,3);
    lcd.print(profile4.shorcut5);
    lcd.setCursor(10,3);
    lcd.print(profile4.shorcut6);

    break;      
  }
}



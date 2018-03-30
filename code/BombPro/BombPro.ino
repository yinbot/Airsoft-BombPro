#include <Wire.h> 
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include "tpic6b595.h"

/*
 Arduino Bomb Pro
 
 The circuit:
 * More info at : http://yin.mainstreamds.com/
 If you need some help mail me to yinbot@gmail.com
 
 created 4,Sep, 2010
 Modified 11 Nov 2015
 by Ignacio Lillo
 */

// the i2c port needs to be specified here. you can detect this with an i2c port scanner
// https://playground.arduino.cc/Main/I2cScanner
LiquidCrystal_I2C  lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'a'},
  {'4', '5', '6', 'b'},
  {'7', '8', '9', 'c'},
  {'*', '0', '#', 'd'},
};

byte rowPins[ROWS] = {  // connect to the row pinouts of the keypad
  A6,
  A5,
  A4,
  A2,
};
byte colPins[COLS] = { // connect to the column pinouts of the keypad
  A1,
  A0,
  A3,
  A7,
};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char codeInput[8];
byte time[4];
boolean refresh = true; // 1 refresh one time...
char password[8];
int key = -1;
char lastKey;
char var;
boolean passwordEnable = false;

//Buttons for lcd shield
char BT_RIGHT = '6';
char BT_UP = '2';
char BT_DOWN = '8';
char BT_LEFT = '4';
char BT_SEL = '#';   // Ok key  
char BT_CANCEL = '*';
char BT_DEFUSER = 'x';   // not implemented

//leds

const uint8_t REDLED = 22;
const uint8_t GREENLED = 23;
//const int BLUELED = 12;
//RELAYPIN
boolean relayEnable = false;
const uint8_t RELAYPIN = 9;
//IS VERY IMPORTANT THAT YOU TEST THIS TIME. BY DEFAULT IS IN 1 SEC. THAT IS NOT TOO MUCH. SO TEST IT!
const int RELAY_TIME = 5000;

//TIME INTS
uint8_t GAMEHOURS = 0;
uint8_t GAMEMINUTES = 45;
uint8_t BOMBMINUTES = 4;
uint8_t ACTIVATESECONDS = 5;

boolean endGame = false;

boolean sdStatus = false; //search and destroy game enable used in config
boolean saStatus = false; //same but SAbotaghe
boolean doStatus = false; //for DEmolition
boolean start = true;
boolean defusing;
boolean cancelando;
// SOUND TONES
boolean soundEnable = true;
uint8_t tonepin = 8; // Pin 13 for the sound
int alarmTone1 = 700;
int alarmTone2 = 2600; // http://www.mainstreamds.com/wp-content/uploads/2014/08/bomb2.0_esquema.png
int activeTone = 1330;
uint8_t errorTone = 100;

unsigned long iTime;
unsigned long timeCalcVar;
unsigned long redTime;
unsigned long greenTime;
unsigned long iZoneTime;//initial time for zone
byte team=0; // 0 = neutral, 1 = blue team, 2 = red team
const byte TEAM_NEUTRAL = 0;
const byte TEAM_BLUE = 1;
const byte TEAM_RED = 2;

void setup () {
  lcd.begin(20, 4);
  Serial.begin(9600);
  pinMode(SER_OUT, OUTPUT);
  pinMode(SRCK, OUTPUT);
  pinMode(RCK, OUTPUT);
  LED_OFF // turn off all leds at start in case we trigger a reboot.

  startupSplash();
  keypad.setHoldTime(50);
  keypad.setDebounceTime(50);
  keypad.addEventListener(keypadEvent);

  //PinModes
  pinMode(GREENLED, OUTPUT);     
  pinMode(REDLED, OUTPUT); 
  pinMode(RELAYPIN, OUTPUT);  
  // CONFIGURE THE BARS OF PROGRESS BAR
  byte bar1[8] = {
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
  };
  byte bar2[8] = {
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
  };
  byte bar3[8] = {
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
  };
  byte bar4[8] = {
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
  };
  byte bar5[8] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
  };
  byte up[8] = {
    B00000,
    B00100,
    B01110,
    B11111,
    B11111,
    B00000,
    B00000,
  };

  byte down[8] = {
    B00000,
    B00000,
    B11111,
    B11111,
    B01110,
    B00100,
    B00000,
  };
  lcd.createChar(0, bar1);
  lcd.createChar(1, bar2);
  lcd.createChar(2, bar3);
  lcd.createChar(3, bar4);
  lcd.createChar(4, bar5);
  lcd.createChar(5, up);
  lcd.createChar(6, down);
}

void loop () {
  menuPrincipal();
}
void keypadEvent (KeypadEvent key) {
  switch (keypad.getState()){
    case RELEASED:
      switch (key) {
         case '#':
          defusing = false;
         break;
         case '*':
          cancelando = false;
         break;
      }
    break;
    case HOLD:
      switch (key) {
        case '#':
          defusing = true;
        break;
        case '*':
          cancelando = true;
        break;
      }
    break;
  }
}

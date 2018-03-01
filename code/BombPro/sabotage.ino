
void sabotage() {
  endGame = false;
  refresh = true;
  cls();
  digitalWrite(REDLED, LOW);
  digitalWrite(GREENLED, LOW);
  //SETUP INITIAL TIME
  int minutos = GAMEMINUTES - 1;


  if (start) {
    iTime = millis(); //  initialTime of the game, use this because sabotage mode goes can return to sabotage()
    start = false;
  }

  unsigned long aTime;

  //Starting Game Code
  while (1) { // this is the important code, is a little messy but works good.

    if (endGame) {
      failSplash();
    }
    //Code for led blinking
    timeCalcVar = (millis() - iTime) % 1000;
    if (timeCalcVar >= 0 && timeCalcVar <= 50)digitalWrite(GREENLED, HIGH);
    if (timeCalcVar >= 90 && timeCalcVar <= 130)digitalWrite(GREENLED, LOW);

    lcd.setCursor(0, 0);
    lcd.print(GAME_TIME);
    lcd.setCursor(3,1);
    lcd.print(F("          "));
    aTime = millis() - iTime;
    lcd.setCursor(5, 2);

    //PRINT TIME ON LCD
    printTime(minutos, aTime);
    //###########################CHECKINGS##################

    //Check If Game End
    if (minutos - aTime / 60000 == 0 && 59 - ((aTime / 1000) % 60) == 0) {
      failSplash();
    }

    //USED IN PASSWORD GAME
    if ('#' == keypad.getKey() && passwordEnable) {
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print(ARMING_BOMB);
      delay(1000);//a little delay to think in the password
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(ENTER_CODE);

      setCodeTime();// we need to set the compare variable first

      //then compare :D

      if (comparePassword()) {
        destroySabotage();
      }
      lcd.clear();
      lcd.setCursor(5, 2);
      lcd.print(CODE_ERROR);
      if (soundEnable)tone(tonepin, errorTone, 200);
      delay(500);
      cls();
    }

    //Check If Is Activating
    while (defusing && !passwordEnable)
    {
      keypad.getKey();
      cls();
      digitalWrite(GREENLED, LOW);
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print(ARMING_BOMB);
      lcd.setCursor(0, 1);
      unsigned int percent = 0;
      unsigned long xTime = millis(); //start disabling time
      while (defusing)
      {
        keypad.getKey();
        //check if game time runs out during the disabling
        aTime = millis() - iTime;
        if ((minutos - aTime / 60000 == 0 && 59 - ((aTime / 1000) % 60) == 0) || minutos - aTime / 60000 > 4000000000)endGame = true;

        timeCalcVar = (millis() - xTime) % 1000;

        if ( timeCalcVar >= 0 && timeCalcVar <= 40)
        {
          digitalWrite(REDLED, HIGH);
          if (soundEnable)tone(tonepin, alarmTone1, 200);
        }
        if (timeCalcVar >= 480 && timeCalcVar <= 520)
        {
          if (soundEnable)tone(tonepin, alarmTone2, 200);
          digitalWrite(REDLED, LOW);
        }
        unsigned long seconds = millis() - xTime;
        percent = (seconds) / (ACTIVATESECONDS * 10);
        drawBar(percent);

        if (percent >= 100)
        {
          digitalWrite(GREENLED, LOW);
          destroySabotage();// jump to the next gamemode
        }
      }
      cls();
      digitalWrite(REDLED, LOW);
    }
  }
}

void destroySabotage() {
  endGame = false;
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print(BOMB_ARMED);
  delay(1000);
  int minutos = BOMBMINUTES - 1;
  unsigned long iTime = millis();
  unsigned long aTime;
  int largoTono = 50;

  //MAIN LOOP
  while (1) {

    //If you fail disarm.
    if (endGame) {
      explodeSplash();
    }

    //Led Blink

    timeCalcVar = (millis() - iTime) % 1000;
    if (timeCalcVar >= 0 && timeCalcVar <= 40)
    {
      digitalWrite(REDLED, HIGH);
      if (soundEnable)tone(tonepin, activeTone, largoTono);
    }
    if (timeCalcVar >= 180 && timeCalcVar <= 220) {
      digitalWrite(REDLED, LOW);
    }
    //Sound

    timeCalcVar = (millis() - iTime) % 1000;
    aTime = millis() - iTime;
    if (timeCalcVar >= 245 && timeCalcVar <= 255 && minutos - aTime / 60000 < 2 && soundEnable)tone(tonepin, activeTone, largoTono);
    if (timeCalcVar >= 495 && timeCalcVar <= 510 && minutos - aTime / 60000 < 4 && soundEnable)tone(tonepin, activeTone, largoTono);
    if (timeCalcVar >= 745 && timeCalcVar <= 760 && minutos - aTime / 60000 < 2 && soundEnable)tone(tonepin, activeTone, largoTono);
    if ( minutos - aTime / 60000 == 0 && 59 - ((aTime / 1000) % 60) < 10)largoTono = 300;

    lcd.setCursor(1, 0);
    lcd.print(DETONATION_IN);
    //Passed Time

    lcd.setCursor(5, 3);

    ////////HERE ARE THE TWO OPTIONS THAT ENDS THE GAME///////////

    ////TIME PASED AWAY AND THE BOMB EXPLODES
    if (minutos - aTime / 60000 == 0 && 59 - ((aTime / 1000) % 60) == 0) // Check if game ends
    {
      failSplash();
    }
    //print time
    printTime(minutos, aTime);

    //// SECOND OPTION: YOU PRESS DISARMING BUTTON

    //IF IS A PASSWORD GAME

    if ('#' == keypad.getKey() && passwordEnable) {

      cls();
      digitalWrite(REDLED, LOW);
      digitalWrite(GREENLED, HIGH);
      lcd.print(DISARMING);
      delay(1000);//a little delay to think in the password

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(ENTER_CODE);

      setCodeTime();// we need to set the compare variable first

      //then compare :D

      if (comparePassword()) {
        sabotage();
      }
      lcd.clear();
      lcd.setCursor(5, 2);
      lcd.print(CODE_ERROR);
      if (soundEnable)tone(tonepin, errorTone, 200);
      delay(500);
      cls();
    }

    if (defusing && !passwordEnable) // disarming bomb
    {
      lcd.clear();
      digitalWrite(REDLED, LOW);
      lcd.setCursor(5, 0);
      lcd.print(DISARM);
      lcd.setCursor(0, 1);
      unsigned int percent = 0;
      unsigned long xTime = millis();
      while (defusing)
      {
        keypad.getKey();
        //check if game time runs out during the disabling
        aTime = millis() - iTime;
        if ((minutos - aTime / 60000 == 0 && 59 - ((aTime / 1000) % 60) == 0) || minutos - aTime / 60000 > 4000000000) {
          endGame = true;
        }

        timeCalcVar = (millis() - xTime) % 1000;
        if (timeCalcVar >= 0 && timeCalcVar <= 20)
        {
          digitalWrite(GREENLED, HIGH);
          if (soundEnable)tone(tonepin, alarmTone1, 200);
        }
        if (timeCalcVar >= 480 && timeCalcVar <= 500)
        {
          if (soundEnable)tone(tonepin, alarmTone2, 200);
          digitalWrite(GREENLED, LOW);
        }
        unsigned long seconds = (millis() - xTime);
        percent = seconds / (ACTIVATESECONDS * 10);
        drawBar(percent);

        //BOMB DISARMED RETURN TO SABOTAGE
        if (percent >= 100)
        {
          cls();
          lcd.print(F("   Bomb Disarmed"));
          delay(1000);
          sabotage();
        }
      }
      digitalWrite(REDLED, LOW);
      digitalWrite(GREENLED, LOW);
      cls();
    }
  }
}















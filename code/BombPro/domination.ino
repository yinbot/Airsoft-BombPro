void domination(){

  //SETUP INITIAL TIME 
  uint8_t minutos = GAMEMINUTES-1;
  boolean showGameTime=true;
  unsigned long a;
  unsigned long iTime=millis(); //  initialTime in millisec 
  unsigned long aTime;
 
  team=0;
  iZoneTime=0;
  aTime=0;
  redTime=0;
  greenTime=0;

  int largoTono = 50;
  // 0 = neutral, 1 = green team, 2 = red team
  a=millis();
  //Starting Game Code
  while(1)  // this is the important code, is a little messy but works good.
  {
    if(endGame){
      gameOver();
    }
    
    keypad.getKey();
    aTime=millis()- iTime;
    //Code for led blinking
    timeCalcVar=(millis()- iTime)%1000;
    if(timeCalcVar >= 0 && timeCalcVar <= 40)
    {
      if(team==1)digitalWrite(GREENLED, HIGH);  
      if(team==2)digitalWrite(REDLED, HIGH);  
    }
    if(timeCalcVar >= 50 && timeCalcVar <= 100)
    {    
      if(team==1)digitalWrite(GREENLED, LOW);  
      if(team==2)digitalWrite(REDLED, LOW);
    }
    // Sound!!! same as Destroy 
    if(timeCalcVar >= 0 && timeCalcVar <= 40 && soundEnable)tone(tonepin,activeTone,largoTono);

    if(timeCalcVar >= 245 && timeCalcVar <= 255 && minutos-aTime/60000<2 && soundEnable)tone(tonepin,activeTone,largoTono);
    if(timeCalcVar >= 495 && timeCalcVar <= 510 && minutos-aTime/60000<4 && soundEnable)tone(tonepin,activeTone,largoTono);
    if(timeCalcVar >= 745 && timeCalcVar <= 760 && minutos-aTime/60000<2 && soundEnable)tone(tonepin,activeTone,largoTono);
    //Help to count 3 secs
    if(a+2000<millis()){
      a=millis();   
      showGameTime=!showGameTime;
      cls();
    }
    //THE NEXT TO METHODS SHOW "GAME TIME" AND "CONTROLED ZONE TIME" IT SHOWS 2 AND 2 SEC EACH

    if(showGameTime){ //THE SECOND IS /2
      lcd.setCursor(5,0);
      lcd.print(F("GAME TIME"));
      lcd.setCursor(5,2);
      printTime(minutos, aTime);
    }
    else if (!showGameTime){

      lcd.setCursor(2,0);
      if (team == TEAM_NEUTRAL) {
        lcd.print(F("  NEUTRAL ZONE"));
      }
      if (team == TEAM_BLUE) {
        lcd.print(F("   BLUE ZONE"));
      }
      if (team == TEAM_RED) {
        lcd.print(F("   RED ZONE"));
      }

      if (team != TEAM_NEUTRAL) {
        lcd.setCursor(5, 2);
        printTimeDom(millis()-iZoneTime,true);
      }
    }

    //###########################CHECKINGS##################

    //Check If Game End
    if(minutos-aTime/60000==0 && 59-((aTime/1000)%60)==0)
    {
      gameOver();
    }

    //Check If IS neutral
    while ((isRedButtonPressed() && team == TEAM_BLUE) || (isBlueButtonPressed() && team == TEAM_RED)) {
      cls();
      if(team != TEAM_NEUTRAL) {
        lcd.print(F("   NEUTRALIZING..."));
      }
      lcd.setCursor(0, 4);
      uint8_t percent = 0;
      unsigned long xTime=millis(); //start disabling time
      while (isRedButtonPressed() || isBlueButtonPressed()) {
        //check if game time runs out during the disabling
        aTime= millis()- iTime;
        if((minutos-aTime/60000==0 && 59-((aTime/1000)%60)==0) || minutos-aTime/60000>4000000000){ 
          endGame = true;
        }
        
        keypad.getKey();
        timeCalcVar = (millis()- xTime)%1000;

        if( timeCalcVar >= 0 && timeCalcVar <= 20)
        {
          if(soundEnable)tone(tonepin,alarmTone1,200);
        }
        if(timeCalcVar >= 480 && timeCalcVar <= 500)
        {
          if(soundEnable)tone(tonepin,alarmTone2,200);
          digitalWrite(REDLED, LOW);
        }

        unsigned long seconds= millis() - xTime;
        percent = (seconds)/(ACTIVATESECONDS*10);
        drawBar(percent);

        if(percent >= 100)
        {
          delay(1000);

          if(team==1){ 
            greenTime+=millis()-iZoneTime;
            iZoneTime=0; 

          }
          if(team==2){ 
            redTime+=millis()-iZoneTime;
            iZoneTime=0; 
          }
          team=0;
          break;
        }
      }
      cls();
    }

    //Capturing red

    while (isRedButtonPressed() && team == TEAM_NEUTRAL) {
      cls();
      if (team == TEAM_NEUTRAL) {
        lcd.print(F("   CAPTURING ZONE"));
      }
      lcd.setCursor(0, 3);
      uint8_t percent = 0;
      unsigned long xTime = millis(); //start disabling time
      while (isRedButtonPressed()) {
        keypad.getKey();
        //check if game time runs out during the disabling
        aTime = millis()- iTime;
        if ((minutos-aTime/60000==0 && 59-((aTime/1000)%60)==0) || minutos-aTime/60000>4000000000) {
          endGame = true;
        }
        timeCalcVar = (millis()- xTime)%1000;

        if( timeCalcVar >= 0 && timeCalcVar <= 20) {
          digitalWrite(REDLED, HIGH);  
          if(soundEnable)tone(tonepin,alarmTone1,200);
        }
        if(timeCalcVar >= 480 && timeCalcVar <= 500) {
          if(soundEnable)tone(tonepin,alarmTone2,200);
          digitalWrite(REDLED, LOW);
        }

        unsigned long seconds= millis() - xTime;
        percent = (seconds)/(ACTIVATESECONDS*10);
        drawBar(percent);

        if(percent >= 100) {
          digitalWrite(GREENLED, LOW);
          team=2;
          iZoneTime=millis();
          delay(1000);
          break;
        }
      }
      cls();
      digitalWrite(REDLED, LOW);
    }

    //getting to blue zone
    while (isBlueButtonPressed() && team == TEAM_NEUTRAL ) {
      cls();
      if(team==0)lcd.print(F("   CAPTURING ZONE"));
      lcd.setCursor(0,3);
      uint8_t percent=0;
      unsigned long xTime=millis(); //start disabling time
      while (isBlueButtonPressed()) {
        keypad.getKey();
        //check if game time runs out during the disabling
        aTime= millis()- iTime;
        if((minutos-aTime/60000==0 && 59-((aTime/1000)%60)==0) || minutos-aTime/60000>4000000000){ 
          endGame = true;
        }
        timeCalcVar = (millis()- xTime)%1000;

        if( timeCalcVar >= 0 && timeCalcVar <= 20)
        {
          digitalWrite(GREENLED, HIGH);  
          if(soundEnable)tone(tonepin,alarmTone1,200);
        }
        if(timeCalcVar >= 480 && timeCalcVar <= 500)
        {
          if(soundEnable)tone(tonepin,alarmTone2,200);
          digitalWrite(GREENLED, LOW);
        }

        unsigned long seconds= millis() - xTime;
        percent = (seconds)/(ACTIVATESECONDS*10);
        drawBar(percent);

        if(percent >= 100)
        {
          digitalWrite(GREENLED, LOW);
          team=1;
          iZoneTime=millis();
          delay(1000);
          break;
        }
      }
      cls();
      digitalWrite(GREENLED, LOW);  
    }
  }
}

void gameOver(){

  if(team==1)greenTime+=millis()-iZoneTime;
  if(team==2)redTime+=millis()-iZoneTime;
  digitalWrite(GREENLED, LOW);
  digitalWrite(REDLED, LOW);
  while(!defusing){
    keypad.getKey();
    if(defusing){
      keypad.getKey();
      break;
    }
    lcd.clear();
    lcd.setCursor(2,5);
    lcd.print(F("  TIME OVER!"));
    lcd.setCursor(0,3);

    //check who team win the base
    if (greenTime > redTime ) {
      // greenteam wins
      lcd.print(F("   BLUE TEAM WINS"));
      digitalWrite(GREENLED, HIGH);
    } else {
      // redteam wins 
      lcd.print(F("   RED TEAM WINS"));
      digitalWrite(REDLED, HIGH);
    }
    delay(3000);
    keypad.getKey();
    if(defusing){
      keypad.getKey();
      break;
    }
    cls();
    lcd.print(F("      Red Time:"));
    lcd.setCursor(7, 2);
    printTimeDom(redTime,false);
    delay(3000);
    keypad.getKey();
    if (defusing) {
      break;
    }
    cls();
    lcd.print(F("     Blue Time:"));
    lcd.setCursor(7, 2);
    printTimeDom(greenTime,false);
    delay(3000);
    keypad.getKey();
    if(defusing){
      keypad.getKey();
      break;
    }
  }
  cls();
  delay(100);
  lcd.print(F("    Play Again?"));
  lcd.setCursor(0,3);
  lcd.print(F("   # : Yes * : No"));
  while(1)
  {
    var = keypad.waitForKey();
    if(var == '#' ){
      tone(tonepin,2400,30);
      cls();
      domination();
      break;
    }  
    if(var == '*' ){
      tone(tonepin,2400,30);
      menuPrincipal();
      break;
    }  
  } 
}

boolean isRedButtonPressed () {
  return defusing;
}

boolean isBlueButtonPressed () {
  return cancelando;
}


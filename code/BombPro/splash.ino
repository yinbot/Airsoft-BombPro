
void explodeSplash(){
  digitalWrite(REDLED, LOW);  
  digitalWrite(GREENLED, LOW); 
  cls();
  delay(100);
  endGame = false;
  lcd.setCursor(0,1);
  lcd.print(F("   TERRORISTS WIN"));
  lcd.setCursor(5,2);
  lcd.print(F("GAME OVER"));
  for(int i = 200; i>0; i--)// this is the ultra hi definition explosion sound xD
  {
    tone(tonepin,i);
    delay(20);
  }
  noTone(tonepin);
  if(relayEnable){
    activateRelay(); 
  }
  delay(5000);
  cls();

  //end code
  lcd.print(F("    Play Again?"));
  lcd.setCursor(0,3);
  lcd.print(F("   # : Yes * : No"));
  while(1)
  {
    var = keypad.waitForKey();
    if(var == '#' ){
      tone(tonepin,2400,30);
      //We have two options, search & destroy and sabotaje play again options so!
      if(sdStatus){
        startGameCount();
        search();
      }
      if(saStatus){
        saStatus=true;
        startGameCount();
        start=true; //to set iTime to actual millis() :D
        sabotage();
      }
    }  
    if(var == '*' ){
      tone(tonepin,2400,30);
      menuPrincipal();

      break;
    }  
  } 
}
void failSplash(){
  digitalWrite(REDLED, LOW);  
  digitalWrite(GREENLED, LOW); 
  cls();
  delay(100);
  endGame = false;
  lcd.setCursor(5,1);
  lcd.print(F("TIME OUT"));
  lcd.setCursor(4,2);
  lcd.print(F("GAME OVER"));
  for(int i = 200; i>0; i--)// this is the ultra hi definition explosion sound xD
  {
    tone(tonepin,i);
    delay(20);
  }
  noTone(tonepin);
  if(relayEnable){
    activateRelay(); 
  }
  delay(5000);
  cls();

  //end code
  lcd.print(F("    Play Again?"));
  lcd.setCursor(0,3);
  lcd.print(F("   # : Yes * : No"));
  while(1)
  {
    var = keypad.waitForKey();
    if(var == '#' ){
      tone(tonepin,2400,30);
      //We have two options, search & destroy and sabotaje play again options so!
      if(sdStatus){
        startGameCount();
        search();
      }
      if(saStatus){
        saStatus=true;
        startGameCount();
        start=true; //to set iTime to actual millis() :D
        sabotage();
      }
    }  
    if(var == '*' ){
      tone(tonepin,2400,30);
      menuPrincipal();

      break;
    }  
  } 
}
void disarmedSplash(){
  endGame = false;
  digitalWrite(REDLED, LOW); 
  digitalWrite(GREENLED, LOW);
  if(sdStatus || saStatus){
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print(F(" BOMB DISARMED"));
    lcd.setCursor(0,2);
    lcd.print(F("    COUNTER WIN"));
    digitalWrite(GREENLED, HIGH);  
    delay(5000);
    digitalWrite(GREENLED, LOW); 
  }
  //end code
  lcd.clear();
  lcd.print(F("    Play Again?"));
  lcd.setCursor(0,3);
  lcd.print(F("   # : Yes * : No"));
  digitalWrite(REDLED, LOW);  
  digitalWrite(GREENLED, LOW); 
  while(1)
  {
    var = keypad.waitForKey();
    if(var == '#' ){
      tone(tonepin,2400,30);
      //We have two options, search & destroy and sabotaje play again options so!
      if(sdStatus){
        startGameCount();
        search();
      }
      if(saStatus){
        saStatus=true;
        startGameCount();
        start=true; //to set iTime to actual millis() :D
        sabotage();
      }
    }  
    if(var == '*' ){
      tone(tonepin,2400,30);
      menuPrincipal();
      break;
    }  
  } 
}

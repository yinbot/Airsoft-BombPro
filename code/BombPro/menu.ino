//##################MENUS###############################

void menuPrincipal(){   //MAIN MENU

  digitalWrite(GREENLED, LOW); 
  digitalWrite(REDLED, LOW); 

  //   if whe start a new game from another we need to restart propertly this variables
  saStatus=false;
  sdStatus=false;
  doStatus=false;
  //Draw menu
  cls();//clear lcd and set cursor to 0,0
  int i=0;
 // HERE YOU CAN ADD MORE ITEMS ON THE MAIN MENU
  lcd.print(menu1[i]);
  lcd.setCursor(15,1);
  checkArrows(i,2);
  while(1){

    var = keypad.waitForKey();
    if(var == BT_UP && i>0){
      tone(tonepin,2400,30);
      i--;
      cls();
      lcd.print(menu1[i]);
      checkArrows(i,2);
      delay(50);
    }
    if(var == BT_DOWN && i<2){
      tone(tonepin,2400,30);
      i++;
      cls(); 
      lcd.print(menu1[i]);    
      checkArrows(i,2);
      delay(50);
    }

    if(var == BT_SEL){
      tone(tonepin,2400,30);
      cls();
      switch (i){

      case 0:
        sdStatus=true;
        configQuickGame();
        startGameCount();
        search();
        break;
      case 1: 
        saStatus=true;
        configQuickGame();
        startGameCount();
        sabotage();
        break;
      case 2:

        doStatus=true;
        configQuickGame();
        startGameCount();
        domination();
        break;
      case 3:
        config();
        break;

      }
    }
  }
}

void config(){
  //Draw menu
  lcd.clear();
  lcd.setCursor(0, 0);
  int i=0;
  
  delay(500);
  lcd.print(menu2[i]);
  checkArrows(i,3);

  while(1){
    var=keypad.waitForKey();
    if(var == BT_UP && i>0){
      tone(tonepin,2400,30);
      i--;
      lcd.clear();  
      lcd.print(menu2[i]);
      checkArrows(i,3);
      delay(50);

    }
    if(var == BT_DOWN && i<3){
      tone(tonepin,2400,30);
      i++;
      lcd.clear();  
      lcd.print(menu2[i]);
      checkArrows(i,3);
      delay(50);
    }
    if(var == BT_CANCEL){
      tone(tonepin,2400,30);
      menuPrincipal();
    }
    if(var == BT_SEL){
      tone(tonepin,2400,30);
      lcd.clear();
      switch (i){

      case 0:
        //gameConfigMenu();
        break;

      case 1:
        //soundConfigMenu();
        break;

      case 2:
        cls();
        lcd.print("Mosfet ON!");
        digitalWrite(mosfet, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(4000);   // wait for 4 second
        cls();
        lcd.print("Mosfet OFF!");
        digitalWrite(mosfet, LOW);
        delay(2000);
        config();
        break;        

      }
    }
  }
}

void configQuickGame(){

  cls();
  //GAME TIME
  if(sdStatus || doStatus || saStatus){
    menu1:
    cls();
    lcd.print(GAME_TIME);
    delay(100);
    lcd.setCursor(0,1);
    lcd.print("00:00 hh:mm");
    lcd.cursor();
    lcd.blink();
    lcd.setCursor(0,1);
    byte var2=0;
    for(int i=0;i<4;i++){ 
      while(1){
        if(i==2 && var2==0){
          lcd.print(":");
          var2=1;
        }

        byte varu= getRealNumber();
        if(varu !=11){

          time[i] =  varu;
          Serial.print(varu);


          lcd.print(varu);
          tone(tonepin,2400,30);

          break;
        }
      }  
    }
    lcd.noCursor();
    lcd.noBlink();
    lcd.setCursor(13,1);
    lcd.print("ok?");
    //zona donde pasamos los items a
    //redibujar
    while(1){
      var = keypad.waitForKey();
      if(var == 'd') // Cancel or Back Button :')
      {
        tone(tonepin,2400,30);
        GAMEMINUTES= ((time[0]*600)+(time[1]*60)+(time[2]*10)+(time[3]));
        break;
      }    
  if(var == 'c') // Cancel or Back Button :')
      {
        tone(tonepin,2400,30);
        goto menu1;
      }           
    }
    tone(tonepin,2400,30);
    cls();
  }
  //BOMB TIME
  if(sdStatus || saStatus){
 
    menu2:
    cls();
    lcd.print(BOMB_TIME);
    delay(100);
    lcd.setCursor(0,1);
    lcd.print(ZERO_MINUTES);
    lcd.cursor();
    lcd.blink();
    lcd.setCursor(0,1);
    for(int i=0;i<2;i++){ 
      while(1){
        byte varu= getRealNumber();
        if(varu !=11){
          time[i] =  varu;
          lcd.print(varu);
          tone(tonepin,2400,30);
          break;
        }
      }  
    }
    lcd.noCursor();
    lcd.noBlink();   
    lcd.setCursor(13,1);
    lcd.print("ok?");
    //zona donde pasamos los items a
    //redibujar
    while(1){
      var = keypad.waitForKey();
      if(var == 'd') // Cancel or Back Button :')
      {
        tone(tonepin,2400,30);
        BOMBMINUTES= ((time[0]*10)+(time[1]));
        break;
      }    
  if(var == 'c') // Cancel or Back Button :')
      {
        tone(tonepin,2400,30);
        goto menu2;
      }           
    }
    tone(tonepin,2400,30);
    cls();
  }
  cls();
  //ARMING TIME
  if(sdStatus || doStatus || saStatus){
        
    menu3:
    cls();
    lcd.print(ARM_TIME);
    delay(100);
    lcd.setCursor(0,1);
    lcd.print(ZERO_SECS);
    lcd.cursor();
    lcd.blink();
    lcd.setCursor(0,1);
    for(int i=0;i<2;i++){ 
      while(1){
        byte varu= getRealNumber();
        if(varu !=11){
          time[i] =  varu;
          lcd.print(varu);
          tone(tonepin,2400,30);
          break;
        }
      }  
    }
    lcd.noCursor();
    lcd.noBlink(); 
    lcd.setCursor(13,1);
    lcd.print("ok?");  
    
    //zona donde pasamos los items a
    //redibujar
    while(1){
      var = keypad.waitForKey();
      if(var == 'd') // Cancel or Back Button :')
      {
        tone(tonepin,2400,30);
        ACTIVATESECONDS= ((time[0]*10)+(time[1]));
        break;
      }    
  if(var == 'c') // Cancel or Back Button :')
      {
        tone(tonepin,2400,30);
        goto menu3;
      }           
    }
    tone(tonepin,2400,30);
    cls();
  }
  //Want sound??
  if(sdStatus || saStatus || doStatus){
    cls();
    lcd.print(ENABLE_SOUND);
    lcd.setCursor(0,1);
    lcd.print(YES_OR_NOT);

    while(1)
    {
      var = keypad.waitForKey();
      if(var == 'a' ){
        soundEnable=true;
        tone(tonepin,2400,30);
        break;
      }  

      if(var == 'b' ){
        soundEnable=false;
        tone(tonepin,2400,30);
        break;
      }  
    }
  } 
  //Activate Mosfet at Terrorist game ends??? Boom!

  if(sdStatus || saStatus){
    cls();
    lcd.print(ENABLE_MOSFET);
    lcd.setCursor(0,1);
    lcd.print(YES_OR_NOT);
    while(1)
    {
      var = keypad.waitForKey();
      if(var == 'a' ){
        mosfetEnable=true;
        tone(tonepin,2400,30);
        break;
      }  
      if(var == 'b' ){
        mosfetEnable=false;
        tone(tonepin,2400,30);
        break;
      }  
    } 
  }
  //You Want a password enable-disable game?
  if(sdStatus || saStatus){
    cls();
    lcd.print(ENABLE_CODE);
    lcd.setCursor(0,1);
    lcd.print(YES_OR_NOT);

    while(1)
    {
      var = keypad.waitForKey();
      if(var == 'a' ){
        tone(tonepin,2400,30);
        setNewPass();
        passwordEnable = true;
        break;
      }  
      if(var == 'b' ){
        tone(tonepin,2400,30);
        passwordEnable = false;
        break;
      }  
    } 
    tone(tonepin,2400,30);
  }  
  //Continue the game :D
}







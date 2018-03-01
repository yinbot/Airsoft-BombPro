void drawBar(byte porcent){
  //TODO: Optimize this code 
  int box=(8*porcent)/10;
  lcd.setCursor(0,1);
  while(box>=5){
    if(box>=5)
    {
      lcd.write(4);
      box-=5;
    }
  }
    switch(box){
    case 0:
      break;
    case 1:
      lcd.write((uint8_t)0);
      break;
    case 2:
      lcd.write(1);
      break;
    case 3:
      lcd.write(2);
      break;
    case 4:
      lcd.write(3);
      break;
    }
  

}
void cls(){
  lcd.clear();
  lcd.setCursor(0,0);
}

void printTime(unsigned long minutos, unsigned long aTiempo){

  timeCalcVar=minutos-aTiempo/60000;
  //Hours
  
  if(timeCalcVar/60==0 && refresh){
      lcd.clear();
      refresh=false;
      //delay(100);
      lcd.setCursor(3,1);
      Serial.println("!!!!");
  }
   
  if(timeCalcVar/60>=1){
    
    if(timeCalcVar/60<10)
  {
    lcd.setCursor(2,1);
    lcd.print("0");
    lcd.print(timeCalcVar/60);
  }
  else
  {
    lcd.print(timeCalcVar/60);
  }
  
  lcd.print(":");
  
  }
  //minutes
  if(timeCalcVar%60<10)
  {
    lcd.print("0");
    lcd.print(timeCalcVar%60);
  }
  else
  {
    lcd.print(timeCalcVar%60);
  }
  lcd.print(":");
  //seconds
  timeCalcVar=aTiempo/1000;
  if(59-(timeCalcVar%60)<10)
  {
    lcd.print("0");
    lcd.print(59-(timeCalcVar%60));
  }
  else
  {
    lcd.print(59-(timeCalcVar%60));
  }
  lcd.print(":");
  //this not mach with real time, is just a effect, it says 999 because millis%1000 sometimes give 0 LOL
  lcd.print(999-(millis()%1000));
}

void printTimeDom(unsigned long aTiempo, boolean showMillis){
  //minutes
  if((aTiempo/60000)<10)
  {
    lcd.print("0");
    lcd.print(aTiempo/60000);
  }
  else
  {
    lcd.print(aTiempo/60000);
  }
  lcd.print(":");
  //seconds
  if(((aTiempo/1000)%60)<10)
  {
    lcd.print("0");
    lcd.print((aTiempo/1000)%60);
  }
  else
  {
    lcd.print((aTiempo/1000)%60);
  }
  if(showMillis){
    lcd.print(":");
    //this not mach with real time, is just a effect, it says 999 because millis%1000 sometimes give 0 LOL
      lcd.print(999-millis()%1000);

  }
}

void startGameCount(){
  lcd.clear();
  lcd.setCursor(3,1);
  lcd.print("Ready to Start");
  lcd.setCursor(2,2);
  lcd.print("Press ANY Button");
  keypad.waitForKey();//if you press a button game start

  cls();
  lcd.setCursor(3,1);
  lcd.print("Starting Game");
  for(int i = 5; i > 0 ; i--){ // START COUNT GAME INIT
    lcd.setCursor(8,2);
    tone(tonepin,2000,100);
    lcd.print("in ");
    lcd.print(i);
    delay(1000);
  }
  cls();
}

void checkArrows(byte i,byte maxx ){

  if(i==0){
    lcd.setCursor(15,1);
    lcd.write(6); 
  }
  if(i==maxx){  
    lcd.setCursor(15,0);
    lcd.write(5);
  }
  if(i>0 && i<maxx){
    lcd.setCursor(15,1);
    lcd.write(6);
    lcd.setCursor(15,0);
    lcd.write(5);  
  }
}

void activateRelay(){

  digitalWrite(RELAYPIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(RELAY_TIME); 
  digitalWrite(RELAYPIN, LOW);

}



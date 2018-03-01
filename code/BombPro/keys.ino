//This fuction compare codeInput[8] and password[8] variables
boolean comparePassword(){

  for(int i=0;i<8;i++){
    if(codeInput[i]!=password[i])return false;
  }
  return true;
}

//Set the password variable
void setCode(){

  lcd.setCursor(0, 1);
  for(int i=0;i<8;i++){
    while(1){
      var= getNumber();
      if(var !='x'){
        codeInput[i] = var;

        if (i != 0){
          lcd.setCursor(i-1,1);
          lcd.print("*");
          lcd.print(var);
        }
        else
        {
          lcd.print(var);
        }
        tone(tonepin,2400,30);
        break;
      }
    }
  }
}
void setCodeTime(){

  timeCalcVar=millis();

  for(int i=0;i<8;i++){
    while(1){
      if(ACTIVATESECONDS*1000+timeCalcVar-millis()<=100){
        codeInput[i]='x';
        break;
      }

      lcd.setCursor(11,0);
      printTimeDom(ACTIVATESECONDS*1000+timeCalcVar-millis(),false);

      var= getNumber();
      if(var !='x'){
        codeInput[i] = var;

        if (i != 0){
          lcd.setCursor(i-1,1);
          lcd.print("*");
          lcd.print(var);
        }
        else
        {
          lcd.print(var);
        }
        tone(tonepin,2400,30);
        break;
      }
    }
  }
}
void setPass(){
  lcd.setCursor(0, 1);

  for(int i=0;i<8;i++){ 
    while(1){
      var= getNumber();
      if(var !='x'){
        password[i] =  var;
        if (i != 0){
          lcd.setCursor(i-1,1);
          lcd.print("*");
          lcd.print(var);
        }
        else
        {
          lcd.print(var);
        }
        tone(tonepin,2400,30);
        break;
      }
    }  
  }
}

void setNewPass(){

  while(1){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Enter New Pass");
    setPass();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    Retype Pass");

    setCode();

    if(comparePassword()){

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Password Set OK!");
      delay(2000); 
      break; 
    }
    else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" ERROR Dont Match!");
      if(soundEnable)tone(tonepin,errorTone,200);
      delay(2000); 

    }
  }
}
//Whait until a button is pressed is is a number return the number 'char' if not return x



char getNumber(){
  while(1){
    var = keypad.getKey();
    if (var){//
      switch (var) {
      case 'a': 
        return 'x';
        break;
      case 'b': 
        return 'x';
        break;

      case 'c': 
        return 'x';
        break;
      case 'd': 
        return 'x';
        break;
      case '*': 
        return 'x';
        break;
      case '#': 
        return 'x';
        break;
      default:
        return var;
        break;
      }
    }
    return 'x';
  }
}

byte getRealNumber(){

  while(1){
    var = keypad.waitForKey();

    if (var){//
      switch (var) {
      case '1': 
        return 1;
        break;
      case '2': 
        return 2;
        break;

      case '3': 
        return 3;
        break;
      case '4': 
        return 4;
        break;
      case '5': 
        return 5;
        break;
      case '6': 
        return 6;
      case '7': 
        return 7;
        break;
      case '8': 
        return 8;
        break;
      case '9': 
        return 9;
        break;
        case '0': 
        return 0;
        break;
        
      default:
        return 11;
        break;
      }

    }
    return 11;
  }
}








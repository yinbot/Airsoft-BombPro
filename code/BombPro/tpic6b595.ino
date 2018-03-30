void TPIC6B959N_write (void) {
  unsigned char i, numOfBytes;
  unsigned char loopLedValues;
  digitalWrite(SRCK, LOW);
  digitalWrite(RCK, LOW);
  /* shift out the bits */
  for (numOfBytes = sizeof(ledValues);numOfBytes > 0;--numOfBytes) {
    for (i = 8;i > 0;--i) {
      loopLedValues = (ledValues[numOfBytes - 1] >> (i - 1));
      loopLedValues = (loopLedValues & 1);
      digitalWrite(SER_OUT, loopLedValues);
      digitalWrite(SRCK, HIGH);
      digitalWrite(SRCK, LOW);
    }
  }
  digitalWrite(RCK, HIGH);  // enable outputs
  digitalWrite(RCK, LOW);
}

void animateRed (void) {
  
}

void animateBlue (void) {
  
}


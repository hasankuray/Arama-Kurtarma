const int qtrMults[] = {7, 5, 3, 1, -1, -3, -5, -7};

int getPosition() {  
  readQtr();
  printQtr();
  int sum = 0;
  int valueCounter = 0;
  for (byte i = 0; i < 8; i++) {
    if (qtrVal[i] == 0) {
      valueCounter++;
    }
    sum += qtrVal[i] * qtrMults[i];
  }
  if (valueCounter == 0) {
    return positionLast;
  }
  sum /= valueCounter;
  return sum;
}

int computeQtr() { // siyah saysını döndürüyor. siyah=1
  int totalValue = 0;
  readQtr();
  for (int i = 0; i < qtr; i++) {
    totalValue += qtrVal[i];
  }
  Serial.println(totalValue);
  return totalValue;
}

void defineQtr() {
  for (int i = 0; i < qtr; i++) {
    pinMode(qtrPins[i], INPUT_PULLUP);
  }
}

 
 void readQtr() {
//int  count =0 ;
  for (int i = 0; i < qtr; i++) {
    //if(qtrVal[i] ==1){
      //count += 1;
      //if(count == 8){
      //setMotors(0,0);
      //delay(1000);
     // setMotors(defaultRightSpeed,defaultLeftSpeed);
     // }
    //}
    qtrVal[i] = digitalRead(qtrPins[i]);
  }
}

void printQtr() {
  for (int i = 0; i < qtr; i++) {
    Serial.print(qtrVal[i]);
    Serial.print("--");
  }
  Serial.println();
}


void defineMotors() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

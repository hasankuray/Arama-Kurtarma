void setMotors(int RightSpeed, int LeftSpeed) {
  if (LeftSpeed > 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
   else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  if (RightSpeed > 0) {
    digitalWrite(IN4, HIGH);
    digitalWrite(IN3, LOW);
  } 
  else {
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, HIGH);
  }
  analogWrite(enA,abs(LeftSpeed));
  analogWrite(enB,abs(RightSpeed));
  }
 
  
  void goToLine() { // t görene kadar düz gitme
  resetEncoders();
  while (true) {
    goForward();
    readQtr();
    if (computeQtr() < 5) break;
  }
  setMotors(0,0);
}

void goOnLine() { // robotun t görene kadar follow line çalıştırma kodu. Parametre olarak kaçıncı T de duracagını alıyor.
  while (1) {
    //    Serial.println("çizgi izlicem");
    followLine();
    if (computeQtr() < 5) break;
  }
  setMotors(0,0);
}

void goStep(double target) {
  resetEncoders();
  while (true) {
    goForward();
    long leftPos = leftEnc.read();
    double stepp = leftPos / (297.92 * 12);
    if (stepp >= target) break;
  }
  setMotors(0,0);
}



void turnLeft(){
  goLeftStep(0.4);
}

void turnBack(){
  goLeftStep(0.85);
}

void turnRight(){
  goRightStep(0.25);
}

void duzGit(double target){
  resetEncoders();
  while(true){
  setMotors(defaultRightSpeed , defaultLeftSpeed-2.85);
  long leftPos = leftEnc.read();
  double stepp = leftPos / (297.92 * 12);
  if (stepp >= target) break;
  }
  setMotors(0,0);
}

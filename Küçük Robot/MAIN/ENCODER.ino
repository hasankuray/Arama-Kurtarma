void goLeftStep(double target) {  // SOLA DÖN
    rightEnc.write(0);
    while (true) {
  setMotors(defaultRightSpeed, -defaultLeftSpeed);
  long rightPos = rightEnc.read();
  double stepp = rightPos / (298.0 * 12);
  Serial.println(stepp);
  if (stepp >= target) 
     break;
  }
  resetEncoders();
  setMotors(0,0);
}

void goRightStep(double target) {  //SAĞA DÖN
       leftEnc.write(0);
       while (true) {
    setMotors(-defaultRightSpeed, defaultLeftSpeed);
    long leftPos = leftEnc.read();
    double stepp = leftPos / (298.0 * 12);
     Serial.println(stepp);
     if (stepp >= target) 
       break;
  }
  resetEncoders();
  setMotors(0,0);
}


void resetEncoders() {                                    // ENCODER RESET
  leftEnc.write(0);
  rightEnc.write(0);
}

double encError() {                                        // ENCODER HATASI
  long leftPos = leftEnc.read();
  long rightPos = rightEnc.read();
  double leftStep = (leftPos / (297.92 * 12));
  double rightStep = (rightPos / (297.92 * 12));
   Serial.print("left step: ");
   Serial.print(leftStep);
   Serial.print("***Right step: ");
   Serial.println(rightStep);
     Serial.println(rightStep-leftStep);

  return (rightStep - leftStep);
}

void readEnc() {                                                // ENKODER OKUMA
  int left = leftEnc.read();
  int right = rightEnc.read();
  Serial.print("left: ");
  Serial.print(left);
  Serial.print(" *** right: ");
  Serial.println(right);
  Serial.println("");
  Serial.print("error");
  Serial.println(left - right);
}

void goStepNoStop(double target) {
  resetEncoders();
  while (true) {
    goForward();
    long leftPos = leftEnc.read();
    double stepp = leftPos / (297.92 * 12);
    if (stepp >= target)
    break;
   // Serial.println(stepp);
  }
setMotors(0,0);
}

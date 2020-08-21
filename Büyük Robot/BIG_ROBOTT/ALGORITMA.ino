
void saveA() {
  goOnLine();
  delay(500);
  duzGit(1.62);
  delay(500);
  turnLeft();
  delay(500);
  goToLine();
  delay(500);
  duzGit(0.05);
  turnLeft();
  goOnLine();
  delay(500);
  duzGit(0.2);
  delay(500);// kapıyı aç
  turnBack();
  delay(500);
  followLine();
  delay(3000);
  setMotors(0,0);
  delay(500);
  turnRight();
  delay(500);
  duzGit(0.83);
  delay(500);
  turnLeft();
  delay(500);
  goToLine();
  delay(500);
  goOnLine(); 
  goOnLine();
  geriGit(0.08);
}

void saveB() {
  goOnLine();
  delay(500);
  duzGit(1.62);
  delay(500);
  turnLeft();
  delay(500);
  goToLine();
  delay(500);
  duzGit(0.05);
  turnRight();
  goOnLine();
  delay(500);
  duzGit(0.2);
  delay(500);// kapıyı aç
  turnBack();
  delay(500);
  followLine();
  delay(3000);
  setMotors(0,0);
  delay(500);
  turnLeft();
  delay(500);
  duzGit(0.83);
  delay(500);
  turnLeft();
  delay(500);
  goToLine();
  delay(500);
  goOnLine(); 
  goOnLine();
  geriGit(0.08);
 }

void saveC() {
  goOnLine();
  delay(500);
  duzGit(1.62);
  delay(500);
  turnRight();
  delay(500);
  goToLine();
  delay(500);
  duzGit(0.05);
  turnLeft();
  goOnLine();
  delay(500);
  duzGit(0.2);
  delay(500);// kapıyı aç
  turnBack();
  delay(500);
  followLine();
  delay(3000);
  setMotors(0,0);
  delay(500);
  turnLeft();
  delay(500);
  duzGit(0.83);
  delay(500);
  turnRight();
  delay(500);
  goToLine();
  delay(500);
  goOnLine();
  goOnLine();
  geriGit(0.08); 
}

void saveD() {
  goOnLine();
  delay(500);
  duzGit(1.62);
  delay(500);
  turnRight();
  delay(500);
  goToLine();
  delay(500);
  duzGit(0.05);
  turnLeft();
  goOnLine();
  delay(500);
  duzGit(0.2);
  delay(500);// kapıyı aç
  turnBack();
  delay(500);
  followLine();
  delay(3000);
  setMotors(0,0);
  delay(500);
  turnRight();
  delay(500);
  duzGit(0.83);
  delay(500);
  turnRight();
  delay(500);
  goToLine();
  delay(500);
  goOnLine(); 
  goOnLine();
  geriGit(0.08);
}
 void geriGit(double target){
  resetEncoders();
  while(true){
  setMotors(-defaultRightSpeed , -defaultLeftSpeed+2.85);
  long leftPos = leftEnc.read();
  double stepp = leftPos / (297.92 * 12);
  if (stepp >= target) break;
  }
  setMotors(0,0);
}

void findKid() {
  while (1) {
    takeMessage();
    Serial.println(message);
    if (message == 'A' || message  == 'B' || message == 'C' || message == 'D'){
      break;
    }
  }
}

void saveKid() {
  if (message == 'A') {
    saveA();
  } else if (message == 'B') {
    saveB();
  } else if (message == 'C') {
    saveC();
  } else if (message == 'D') {
    saveD();
  }
}

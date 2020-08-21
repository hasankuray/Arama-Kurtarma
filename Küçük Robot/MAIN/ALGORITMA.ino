void goC() {
  turnRight();
  delay(500);
  goToLine();
  delay(500);
  goStepNoStop(0.015);
  turnRight();
  goRightStep(0.013);
  delay(500);
  goOnLine();
  delay(800);
  goStepNoStop(0.3);    // odadan içeri girdi
  //setMotors(67,70);
  //delay(1000);
  //setMotors(0,0);
  delay(500);
  lightFreqs[0] = calcLight();
  delay(2500);
  turnBack();
  delay(500);
  goToLine();
  delay(500);
}
void goD(){
  goOnLine();
  delay(500);
  //goStepNoStop(0.3);
  //delay(500);
  setMotors(70,70);
  delay(1000);
  setMotors(0,0);
  delay(500);
  lightFreqs[1] = calcLight();
  delay(2500);
  turnBack();
  delay(500);
  goToLine();
  delay(500);
} 
void goA(){
  goStepNoStop(0.34);
  delay(500);
  turnRight();
  delay(500);
  goToLine();
  delay(500);
  goStepNoStop(0.015);
  turnLeft();
  goLeftStep(0.013);
    delay(500);
  goOnLine();
    delay(500);
  setMotors(70,70);
  delay(1000);
  setMotors(0,0);
  delay(500);
  lightFreqs[2]=calcLight();
  delay(2500);
  turnBack();
//goLeftStep(0.228);
  delay(500);
  goToLine();
  delay(500);
  goStepNoStop(0.34);
  delay(500);
  turnRight();
//goLeftStep(0.093);
  delay(500);
  goStepNoStop(0.73);
  delay(500);
  turnLeft();
  delay(500);
  goToLine();
  delay(500);
  goOnLine();
  }
 


void travelRoomss(){
  goOnLine();
  delay(500);
  goStepNoStop(1.15);
  delay(500);
  goC();
  goD();
  goA();
}

void goHome(){
  if(room == 'A'){
   followLine();
   delay(1500);
   turnRight();
   delay(500);
   duzGit(0.73);  //goStepNoStep(0.73);
    delay(500);
   turnLeft();
    delay(500);
   goToLine();
    delay(500);
   goOnLine();
    delay(500);
   duzGit(0.05);
  }
  else if(room== 'B'){
    followLine();
   delay(1500);
   turnLeft();
   delay(500);
   duzGit(0.73);   //goStepNoStep(0.73);
    delay(500);
   turnLeft();
    delay(500);
   goToLine();
    delay(500);
   goOnLine();
    delay(500);
   duzGit(0.05);
  }
  else if(room== 'C'){
    followLine();
   delay(1500);
   turnLeft();
   delay(500);
   duzGit(0.73);    //goStepNoStep(0.73);
    delay(500);
   turnRight();
    delay(500);
   goToLine();
    delay(500);
   goOnLine();
    delay(500);
   duzGit(0.05);
  }
  else if(room== 'D'){
    followLine();
   delay(1500);
   turnRight();
   delay(500);
   duzGit(0.73);    //goStepNoStep(0.73);
    delay(500);
   turnRight();
    delay(500);
   goToLine();
    delay(500);
   goOnLine();
    delay(500);
   duzGit(0.05);
  }
  }


void toparlaKendini(){
  setMotors(66,71);
  delay(500);
  setMotors(0,0);
  }

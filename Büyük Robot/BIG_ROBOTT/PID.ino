

PID myPID(&Input, &Output, &Setpoint, kp, ki, kd, DIRECT);
PID encPID(&Input3, &Output3, &Setpoint3, kp3, ki3, kd3, DIRECT);



void initPID() {  
  Setpoint = 0;
  Input = 0;
  myPID.SetOutputLimits(-255, 255);               
  myPID.SetMode(AUTOMATIC);
}

void initEncPID() { // konuldu
  Setpoint3 = 0.005;
  Input3 = 0;
  encPID.SetOutputLimits(-20, 20);
  encPID.SetMode(AUTOMATIC);
}

void followLine() {      //ÇİZGİ TAKİP
  pos = getPosition();
  positionLast = pos;
  Input = pos; 
  myPID.Compute();
  Serial.println(Output);
  setMotors(cizgiSag + Output, cizgiSol - Output);

}

void goForward() {                                             
  Input3 = encError();
  //Serial.println(Input3);
  encPID.Compute();
  Serial.println(Output3);
 //Serial.print("Output: ");
 //Serial.println(Output3);
  setMotors(defaultRightSpeed + Output3, defaultLeftSpeed - Output3);
 
}

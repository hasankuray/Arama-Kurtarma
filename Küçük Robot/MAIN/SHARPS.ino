int mesafe = 0;
int sure = 0;
int mesafe2 = 0;
int sure2 = 0;
int solaDondu = 0;
int duzGitt = 0;
int duzGitt2 = 0;

void ultrasonik(){
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
}
void ultrasonik2(){
  pinMode(trig2 , OUTPUT);
  pinMode(echo2 , INPUT);
}
int solMesafe(){
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig,LOW);

  sure = pulseIn(echo, HIGH);
  mesafe = (sure/2) / 29.1 ;
  Serial.println(mesafe);
  delay(250);
  return mesafe;
}

int onMesafe(){
  digitalWrite(trig2 , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig2,LOW);

  sure2 = pulseIn(echo2, HIGH);
  mesafe2 = (sure2/2) / 29.1 ;
  Serial.println(mesafe2);
  delay(250);
  return mesafe2;
}
void exitRoom(){
  while(!solaDondu){
    solMesafe();
    onMesafe();
    if(mesafe >! 4 || mesafe <! 10){
      setMotors(-defaultRightSpeed, defaultLeftSpeed);
      delay(200);
      setMotors(0,0);
      delay(100);
      Serial.println(mesafe);
      
   /*   for(int i = 0 ; i <10; i++){
        if(i == 9 && !solaDondu){
          setMotors(75,65);
          delay(1000);
          setMotors(0,0);
          delay(100); 
      
          Serial.println("Fora girdi");
        }
      }
     Serial.println("cikti");
     */
     if(mesafe >= 4 && mesafe <= 10){
     solaDondu == 1;
        Serial.println("gördük");
      setMotors(0,0);
      break;
     
      
   }
    }
     
  }
Serial.println("ciktik");

 
 solMesafe();
 onMesafe();
 if(mesafe2 == 4){
  turnRight();
 }
  while(duzGitt){
    setMotors(defaultRightSpeed , defaultLeftSpeed);
  if(solMesafe() > 4  || solMesafe() < 10  ){
    setMotors(0,0);
    break;
  }    
    if(onMesafe() == 4){
    turnRight();
    duzGitt = 1 ;
    break;
   }
  }
  

 while(duzGitt2){
  setMotors(defaultRightSpeed , defaultLeftSpeed);
  if(solMesafe() > 4  || solMesafe() < 10  ){
    setMotors(0,0);
    break;
  }
    if(onMesafe() == 4){
    turnRight();
    duzGitt2 = 1 ;
    break;
   }
  }
  
}












   void exitRoomm() {
  int a = 1;
  while (a) {
    if (!(solMesafe() > 4) || !(solMesafe() < 10)) {
      setMotors(-defaultRightSpeed, defaultLeftSpeed);
      delay(200);
      setMotors(0, 0);
      delay(100);
      //Serial.println(mesafe);
    }
    else {

      setMotors(-defaultRightSpeed, defaultLeftSpeed);
      delay(200);
      setMotors(0, 0);
      delay(100);
      setMotors(-defaultRightSpeed, defaultLeftSpeed);
      delay(200);
      setMotors(0, 0);
      delay(100);
      a = 0;
    }
  }

  while (onMesafe() > 6) {
    setMotors(66, 66);
    delay(100);

  }
  setMotors(0, 0);
  rightStepEnhanced();
  while (solMesafe() > 4) {
    while (onMesafe() > 6) {
      setMotors(66, 66);


    }
    setMotors(0, 0);
   // goRightStep(0.118);
   rightStepEnhanced();
  }
  setMotors(66, 66);
  delay(700);
  goLeftStep(0.288);

}




void rightStepEnhanced() {
int a = 1;
  while (a) {
    if (onMesafe() < 10){
      setMotors(-defaultRightSpeed, defaultLeftSpeed);
      delay(200);
      setMotors(0, 0);
      delay(100);
      //Serial.println(mesafe);
    }
    else {

      setMotors(-defaultRightSpeed, defaultLeftSpeed);
      delay(200);
      setMotors(0, 0);
      delay(100);
      setMotors(-defaultRightSpeed, defaultLeftSpeed);
      delay(200);
      setMotors(0, 0);
      delay(100);
      a = 0;
    }
  }
}

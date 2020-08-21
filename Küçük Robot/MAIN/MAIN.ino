#include <Encoder.h>
#include <PID_v1.h>
#include <AFMotor.h>
#include <nRF24L01p.h>
#include <SPI.h>



#define CE_PIN 9
#define CSN_PIN 10
#define ldr 42

const int trig = 2 ;
const int echo = 3 ;

const int trig2 = 6 ;
const int echo2 = 7 ;


nRF24L01p  transmitter(CSN_PIN , CE_PIN);
char room = '';


#define qtr 8
#define lim 9

const byte IN1 = 46, IN2 = 47;
const byte IN3 = 44, IN4 = 45;
const byte enA = 5, enB = 4;

const byte encLeft1 = 18, encLeft2 = 19;
const byte encRight1 = 21, encRight2 = 20;

const byte qtrPins[] = {22, 23, 24, 25, 26, 27, 28, 29};

int defaultLeftSpeed =70 ; 
int defaultRightSpeed = 70;
int cizgiSag = 66;
int cizgiSol = 66;

Encoder leftEnc(encLeft2, encLeft1);
Encoder rightEnc(encRight1, encRight2);

double Setpoint, Input, Output;
double Setpoint3, Input3, Output3;

AF_DCMotor motorRight(2);
AF_DCMotor motorLeft(1);

int qtrVal[] = {0, 0, 0, 0, 0, 0, 0, 0};

int lightFreqs[] = {0, 0, 0};

char message = "";


int positionLast;
int pos;

float kp = 2.7;   
float ki = 0.4;  
float kd = 0.5;  

float kp3 = 30;   // 30 -80
float ki3 = 6;     //6 -37
float kd3 = 0.01;   // 0.01-60

enum directions {
  RIGHT,
  LEFT
};

boolean imSafe = false;
boolean findMe = false;

void setup() {
  Serial.begin(9600);
    //defineQtr();
    //defineMotors();
    //solMesafe();
    //ultrasonik();
    //ultrasonik2();
    //setMotors(70,70 );
    //initPID();
   initEncPID();
   //duzGit(0.73);
   goStepNoStop(0.6);
   
   delay(2000);
      initNrfTrans();
    //goLeftStep(0.093);    // sola dön
   // goRightStep(0.105);   // sağa dön 0.106
    //goBackStep(0.22);
   //goLeftStep(0.228);    // geri dön
    //exitRoom();
   
     
    }


void loop(){
 
 if(!imSafe){
   travelRoomss();
      imSafe = true;
}
   whereAmI();
   while (1){
   int bekleme = millis();
   bekleme /= 1000;
   Serial.println(bekleme);
   sendMessage();
   if(bekleme == 60)
   break;
  }
exitRoom();
goHome();
}

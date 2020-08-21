#include <Encoder.h>
#include <PID_v1.h>
#include <AFMotor.h>
#include <nRF24L01p.h>
#include <SPI.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10
#define ldr 42

nRF24L01p  receiver(CSN_PIN , CE_PIN);


#define qtr 8
#define lim 9

char roomName;
const byte IN1 = 46, IN2 = 47;
const byte IN3 = 44, IN4 = 45;
const byte enA = 5, enB = 4;

const byte encLeft1 = 18, encLeft2 = 19;
const byte encRight1 = 21, encRight2 = 20;

const byte qtrPins[] = {22, 23, 24, 25, 26, 27, 28, 29};

int defaultLeftSpeed =30 ; 
int defaultRightSpeed = 38;
int cizgiSag = 40;
int cizgiSol = 40;

Encoder leftEnc(encLeft2, encLeft1);
Encoder rightEnc(encRight1, encRight2);

double Setpoint, Input, Output;
double Setpoint3, Input3, Output3;


int qtrVal[] = {0, 0, 0, 0, 0, 0, 0, 0};




int positionLast;
int pos;
String message = "";

float kp = 2.7;   
float ki = 0.4;  
float kd = 0.5;  

float kp3 = 30;   // 30 -80
float ki3 = 6;     //6 -37
float kd3 = 0.01;   // 0.01-60


boolean imSafe = false;

void setup() {
  Serial.begin(9600);
    defineQtr();
    defineMotors();
    //setMotors(70,70 );
   initPID();
   initEncPID();
    initNrf();
    //goLeftStep(0.4);    // sola dön
    //goRightStep(0.25);   // sağa dön 0.106
    //goBackStep(0.22);
   //goLeftStep(0.85);    // geri dön
   // duzGit(0.2);    // kapıyı aç
     
    }


void loop() {
   findKid();
   saveKid();

}

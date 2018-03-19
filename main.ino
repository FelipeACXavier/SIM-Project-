#include <StopWatch.h>
#include <Adafruit_TCS34725.h>
#include <Wire.h>
#include <NewPing.h>
#include <Servo.h>
#include <Stepper.h>

//STATE
#define PICKING 0
#define DRIVING 1
#define DROP 2

//Dc motor pins
#define speedPin_Right 11
#define speedPin_Left 3
#define movePin_Right 12
#define movePin_Left 13
#define breakPin_Right 8
#define breakPin_Left 9
#define motorspeed 255

//Infrared sensor
#define FCS 39
#define FLS 49
#define FRS 45
#define FMLS 33
#define FMRS 31

//State machine for arm
#define SPIN_TO_FIND 0
#define COLOR_CHECK 1
#define PICKUP_POSITION 2
#define PICKUP_OBJECT 3
#define SPIN_POSITION 4
#define SPIN_TO_BIN 5
#define RELEASE_OBJECT 6
#define FIND_POSITION 7

//Ultrasonic sensor
#define trigPin 34
#define echoPin 37

//Arm lenghts
#define length_shoulder 30.0
#define length_upper 26
#define length_lower 14.2

//Servo pins
#define SRpin 9
#define SLpin 10
#define ELBpin A8
#define HANDpin A9
#define FINGpin A7

//Junctions
#define first_Junction 0
#define pickup_Junction 1
#define end_t_Junction 2
#define endLine 3

//----------------------------------------------------------------------------------------------------
//Set the clock object
StopWatch myClock;
StopWatch myClock2;

//Set the new ping object
NewPing sonar(trigPin, echoPin, 40);

//Set the color sensor object and variables
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
uint16_t r, g, b, c;

//Dc motor variables
const int stepsPerRevolution = 200;
const int motorSpeed = 50;
const int turn_speed = 60;
int juncounter = 0;
int juncounter2 = 1;

//Set stepper motor
Stepper myStepper(stepsPerRevolution, 4, 5, 2, 7);

//Set the servo motors
Servo finger;
Servo hand;
Servo elbow;
Servo shoulderLeft;
Servo shoulderRight;

//Infrared sensors
float FCS_1;
float FLS_1;
float FRS_1;
float FMLS_1;
float FMRS_1;

//Other variables
int state = 7;
int counter = 0;
int servoCounter = 0;
int truer = 1;
double angleShoulder, angleUpper, angleLower;
double dangShoulder, dangUpper;
int junction = 0;
int STATE;

float obj_X, obj_Y = 30;
float distance = 90;

//----------------------------------------------------------------------------------------------------
void setup() {
  //Set stepper speed
  myStepper.setSpeed(50);

  // Set pins for the servos
  finger.attach(FINGpin);
  hand.attach(HANDpin);
  elbow.attach(ELBpin);
  shoulderLeft.attach(SLpin);  //Shoulder left is normal (x)
  shoulderRight.attach(SRpin); //Shoulder left is normal (x)

  //Set pins used by the ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Infrared sensor
  pinMode(FCS, INPUT);
  pinMode(FLS, INPUT);
  pinMode(FRS, INPUT);
  pinMode(FMLS, INPUT);
  pinMode(FMRS, INPUT);
  pinMode(50, OUTPUT);

  //Initialize communication with computer
  Serial.begin(9600);
  
  //Initialize STATE
  STATE = DRIVING;
}

//----------------------------------------------------------------------------------------------------
void loop() {
  //Initialize the state machine
  if (STATE == DRIVING) {
    sensor_readdigital();
    driving();
  } else if (STATE == DROP) {
    picking();
  } else {

  }
}

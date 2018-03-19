//Function that checks and distance and if nothing is found, spin 20 steps
void movetoObject() {
  distance = getDistanceAndSend2Serial();
  if (distance < 2)
    distance = 90;
  if (distance < 20) {
    obj_X = distance;
    state = COLOR_CHECK;
  } else {
    myStepper.setSpeed(50);
    myStepper.step(10);
    delay(200);
    counter++;
    delay(200);
  }
}
//------------------------------------------------------------------------
void move_stopped_bin() {
  myStepper.setSpeed(50);
  myStepper.step(0);
  delay(1000);
}
//------------------------------------------------------------------------
//Determine the height of the object based on the cell color
void color_check(uint16_t R, uint16_t G, uint16_t B) {
  if (B > R && B > G) {
    Serial.println("Blue");

  } else if (G > B && R < 600 ) {
    Serial.println("Green");

  } else if (R > B && R > G && R < 2000) {
    Serial.println("Red");

  } else if (R > B && G > B) {
    Serial.println("Yellow");
  }
}
//------------------------------------------------------------------------
//Calculate the angles needed based on distance and height and put the servos in position
void pickupPosition() {
  findAngle(obj_X, obj_Y);
  hand.write(90 - angleLower);
  delay(500);
  elbow.write(180 - dangUpper);
  delay(500);
  shoulderLeft.write(dangShoulder);
  shoulderRight.write(180 - dangShoulder);
  delay(500);
}
//------------------------------------------------------------------------
void grabObject() {
  finger.write(10);
  delay(500);
}
//------------------------------------------------------------------------
void findPosition() {
  hand.write(170);
  delay(200);
  elbow.write(60);
  delay(200);
  shoulderLeft.write(80);
  shoulderRight.write(180 - 80);
  delay(500);
}
//------------------------------------------------------------------------
void movetoBin() {
  while (counter > 0) {
    myStepper.setSpeed(50);
    myStepper.step(-10);
    delay(200);
    counter--;
    delay(100);
  }
  myStepper.setSpeed(0);
  delay(200);
}
//------------------------------------------------------------------------
void releaseObject() {
  finger.write(90);
  delay(500);
}
//------------------------------------------------------------------------
void startPosition() {
  //put stepper
  //put stepper
  delay(200);
  //put stepper
  delay(500);
}
//------------------------------------------------------------------------
void stopPosition() {
  finger.write(10);
  delay(500);
  shoulderLeft.write(115);
  shoulderRight.write(180 - 115);
  delay(1000);
  hand.write(10);
  delay(500);
  elbow.write(80);
  delay(400);
  elbow.write(60);
  delay(500);
}
//------------------------------------------------------------------------
void moveHand(float value) {
  int angle;
  if (servoCounter == 0)
    angle = hand.read();

  if (angle > value) {
    for (int i = angle; i > value; i = i - 1) {
      hand.write(i);
      delay(60);
    }
  }
  else if (angle < value) {
    for (int i = angle; i < value; i = i + 1) {
      hand.write(i);
      delay(60);
    }
  }
}
//------------------------------------------------------------------------
void moveElbow(float value) {
  int angle;
  if (servoCounter == 0)
    angle = elbow.read();

  if (angle > value) {
    for (int i = angle; i > value; i = i - 1) {
      elbow.write(i);
      delay(60);
    }
  }
  else if (angle < value) {
    for (int i = angle; i < value; i = i + 1) {
      elbow.write(i);
      delay(60);
    }
  }
}
//------------------------------------------------------------------------
void moveShoulder(float value) {
  int angle;
  if (servoCounter == 0)
    angle = shoulderLeft.read();

  if (angle > value) {
    for (int i = angle; i > value; i = i - 1) {
      shoulderLeft.write(i);
      shoulderRight.write(180 - i);
      delay(60);
    }
  }
  else if (angle < value) {
    for (int i = angle; i < value; i = i + 1) {
      shoulderRight.write(180 - i);
      delay(60);
    }
  }
}

/*void clockStart() {
  myClock.reset();
  myClock.start();
}

void clockStart2() {
  myClock2.reset();
  myClock2.start();
}

bool clockCheck() {
  if (myClock.elapsed() >= 5000) {
    myClock.stop();
    return true;
  } else {
    return false;
  }
}
bool clockCheck2() {
  if (myClock2.elapsed() >= 5000) {
    myClock2.stop();
    return true;
  } else {
    return false;
  }
}
bool clockCheck3() {
  if (myClock2.elapsed() >= 1500) {
    myClock2.stop();
    return true;
  } else {
    return false;
  }
}
bool clockCheck4() {
  if (myClock2.elapsed() >= 10000) {
    myClock2.stop();
    return true;
  } else {
    return false;
  }
}*/
float getDistanceAndSend2Serial() {

  float cm = sonar.ping_cm();
  Serial.print(",");
  Serial.println(cm, DEC);

  return cm;
}
//Read all sensors at once and save the values in the float variables
void sensor_readdigital(){
  FCS_1 = digitalRead(FCS);
  FLS_1 = digitalRead(FLS);
  FRS_1 = digitalRead(FRS);
  FMLS_1 = digitalRead(FMLS);
  FMRS_1 = digitalRead(FMRS);
}
//Debuging
void show_values() {
  sensor_readdigital();
  Serial.write("Front center sensor ");
  Serial.println(FCS_1);
  Serial.write("Front left sensor ");
  Serial.println(FLS_1);
  Serial.write("Front right sensor ");
  Serial.println(FRS_1);
  Serial.write("Front Most left sensor ");
  Serial.println(FMLS_1);
  Serial.write("Front Most right sensor ");
  Serial.println(FMRS_1);
  Serial.write("---------------------------------\n");
  delay(1000);
}
//Decides what color is read by the sensor (Debuging)
void whichColor(uint16_t R, uint16_t G, uint16_t B) {

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


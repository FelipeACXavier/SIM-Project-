//Kinematic equations for the three jointed arm
void findAngle(float x , float y) {

  //The hand will always be in 90 degrees in relation to the floor so
  float height = length_lower + y;
  Serial.print("Height: ");
  Serial.println(height);
  
  //With this we find the real distance from the object (x,y)
  float hip = sqrt(pow(height, 2) + pow(x, 2));
  Serial.print("Hipotenuse: ");
  Serial.println(hip);
  
  //The angle of the real distance in relation to the floor
  float phi4 = +atan(height / x);
  Serial.print("phi4: ");
  Serial.println(phi4);
  
  //This will find the angle between the arm and the real distance line
  float phi1 = +acos((pow(length_upper, 2) - pow(length_shoulder, 2) - pow(hip, 2)) / (-2 * length_shoulder * hip));
  Serial.print("phi1: ");
  Serial.println(phi1);
  
  //This will find the angle between upper and lower arms
  float phi2 = acos((pow(hip, 2) - pow(length_shoulder, 2) - pow(length_upper, 2)) / (-2 * length_shoulder * length_upper));
  Serial.print("phi2: ");
  Serial.println(phi2);
    
  //The actual shoulder angle is the sum of the angle from arm to real distance line and real distance line to floor
  angleShoulder = phi1 + phi4;

  //The angle of the elbow is PI minus the angle between upper and lower arms
  angleUpper = PI - phi2;

  //This is the angle between object and real distance line
  float phi3 = +acos(x / hip);
  float phi5 = PI - phi2 - phi1;

  //Find angle lower
  angleLower = PI - phi3 - phi5;

  Serial.print("Shoulder: ");
  Serial.println(angleShoulder);
  Serial.print("Elbow: ");
  Serial.println(angleUpper);
  Serial.print("Hand: ");
  Serial.println(angleLower);
  //-------------------------------------------------------------------
  dangShoulder = angleShoulder * 180 / PI;

  dangUpper = angleUpper * 180 / PI;
  //dangUpper = 180 - angleUpper;

  angleLower = angleLower * 180 / PI;
  Serial.print("Shoulder: ");
  Serial.println(dangShoulder);
  Serial.print("Elbow: ");
  Serial.println(dangUpper);
  Serial.print("Hand: ");
  Serial.println(angleLower);
  Serial.println("-------------------------------------------------");
}




void move_Forward()
{
  analogWrite(speedPin_Right, motorSpeed);
  digitalWrite(movePin_Right, HIGH);
  digitalWrite(breakPin_Right, LOW);
  analogWrite(speedPin_Left, motorSpeed);
  digitalWrite(movePin_Left, LOW);
  digitalWrite(breakPin_Left, LOW);
}
void move_Backward()
{
  analogWrite(speedPin_Right, motorSpeed);
  digitalWrite(movePin_Right, LOW);
  digitalWrite(breakPin_Right, LOW);
  analogWrite(speedPin_Left, motorSpeed);
  digitalWrite(movePin_Left, HIGH);
  digitalWrite(breakPin_Left, LOW);
}
void stop_Movement()
{
  analogWrite(speedPin_Right, 0);
  digitalWrite(movePin_Right, LOW);
  digitalWrite(breakPin_Right, HIGH);
  analogWrite(speedPin_Left, 0);
  digitalWrite(movePin_Left, LOW);
  digitalWrite(breakPin_Left, HIGH);
}
void turn_Left()
{
  analogWrite(speedPin_Right, turn_speed);
  digitalWrite(movePin_Right, LOW);
  digitalWrite(breakPin_Right, LOW);
  analogWrite(speedPin_Left, turn_speed);
  digitalWrite(movePin_Left, LOW);
  digitalWrite(breakPin_Left, LOW);
}
void turn_Right()
{
  analogWrite(speedPin_Right, turn_speed);
  digitalWrite(movePin_Right, HIGH);
  digitalWrite(breakPin_Right, LOW);
  analogWrite(speedPin_Left, turn_speed);
  digitalWrite(movePin_Left, HIGH);
  digitalWrite(breakPin_Left, LOW);
}

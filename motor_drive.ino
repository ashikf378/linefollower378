void lineFollow()
{
  int pid;

  //Read the mask values and calculate error
  error = line_follow();
 
  p = error * kp;
  i = (i + error) * ki; //i=i+ilast;
  d = (error - prevError) * kd;
  pid = int(p + i + d);

  //lasti=i;
  //motor_control();
  motor(leftBaseSpeed - pid, rightBaseSpeed + pid);
  prevError = error;
  if (error - prevError == 0) delay(10);
 }

void motor(int leftSpeed, int rightSpeed)
{
  if ( leftSpeed == 0)
  {
    digitalWrite(inC, 1);
    digitalWrite(inD, HIGH);
  }
  if ( leftSpeed > 0)
  {
    digitalWrite(inC, 1);
    digitalWrite(inD, 0);
    //delay(5);
  }
  else if ( leftSpeed < 0)
  {
    digitalWrite(inC, 0);
    digitalWrite(inD, 1);
    //delay(5);
  }

  if (rightSpeed == 0)
  {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, HIGH);
  }
  if ( rightSpeed > 0)
  {
    digitalWrite(inA, 1);
    digitalWrite(inB, 0);
    //delay(10);
  }
  else if ( rightSpeed < 0)
  {
    digitalWrite(inA, 0);
    digitalWrite(inB, 1);
    //delay(10);
  }
  if (abs(leftSpeed) > maxSpeed) leftSpeed = maxSpeed;
  if (abs(rightSpeed) > maxSpeed) rightSpeed = maxSpeed;

  analogWrite(enA, abs(rightSpeed));
  analogWrite(enB, abs(leftSpeed));
}

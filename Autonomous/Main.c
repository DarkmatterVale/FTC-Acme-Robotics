//Put main code for Autonomous Program

void MoveRobotForward( int speed )
{
  motor[leftRobotMotor] = speed;
  motor[rightRobotMotor] = speed;
}

void MoveRobotForward( int speed, int timeToMove )
{
  motor[leftRobotMotor] = speed;
  motor[rightRobotMotor] = speed;
  wait1Msec( timeToMove );
  motor[leftRobotMotor] = 0;
  motor[rightRobotMotor] = 0;
}

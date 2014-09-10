//Put main code for Autonomous Program

void MoveRobotForward()
{
  motor[leftRobotMotor] = 75;
  motor[rightRobotMotor] = 75;
}

void MoveRobotForward( int timeToMove )
{
  motor[leftRobotMotor] = 75;
  motor[rightRobotMotor] = 75;
  wait1Msec( timeToMove );
  motor[leftRobotMotor] = 0;
  motor[rightRobotMotor] = 0;
}

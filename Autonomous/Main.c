//Put main code for Autonomous Program

void MoveRobotForward( int speed )
{
  motor[leftRobotMotor] = speed;
  motor[rightRobotMotor] = speed;
}

void MoveRobotForward( int speed, int timeToMove )
{
  motor[leftRobotMotor] = 0;
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  motor[leftRobotMotor] = speed;
  motor[rightRobotMotor] = speed;
  wait1Msec( timeToMove );
  
  motor[leftRobotMotor] = 0;
  motor[rightRobotMotor] = 0;
}

void MoveRobotLeft( int speed )
{
  motor[leftRobotMotor] = -speed;
  motor[rightRobotMotor] = speed;
}

void MoveRobotLeft( int speed, int timeToMove )
{
  motor[leftRobotMotor] = 0;
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  motor[leftRobotMotor] = -speed;
  motor[rightRobotMotor] = speed;
  wait1Msec( timeToMove );
  
  motor[leftRobotMotor] = 0;
  motor[rightRobotMotor] = 0;
}
task main()
{
  //In here will be the main part of the autonomous program
  
  //We should call a function to complete the Catapult launch part of the autonomous stage
  /*
    call catapult launcher ( will handle everything including getting sensorvalues and determing the correct course of action )
  */
}

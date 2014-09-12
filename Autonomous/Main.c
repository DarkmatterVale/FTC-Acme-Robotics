//Put main code for Autonomous Program

void MoveRobotForward( int speed ) //function for moving robot forward at a certain speed infinitesimally
{
  motor[leftRobotMotor] = 0; //stopping motors to eliminate course deviations
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  motor[leftRobotMotor] = speed; //setting the motors to the passed speed variable level power level
  motor[rightRobotMotor] = speed;
}

void MoveRobotForward( int speed, int encoderValue ) //function for moving robot forward at a certain speed and for a certain amount of time
{
  motor[leftRobotMotor] = 0; //stopping motors to eliminate course deviations
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  nMotorEncoder[leftRobotMotor] = 0; //resetting encoder values
  nMotorEncoder[rightRobotMotor] = 0;
  
  while ( nMotorEncoder[leftRobotMotor] <= encoderValue && nMotorEncoder[rightRobotMotor] <= encoderValue ) //while encoders have not moved past allowed distance
  {
    motor[leftRobotMotor] = speed; //setting motors to passed speed variable power level
    motor[rightRobotMotor] = speed;
  }
  
  motor[leftRobotMotor] = 0; //stopping motors after movement duration has occurred
  motor[rightRobotMotor] = 0;
}

void MoveRobotLeft( int speed ) //function for turning the robot left at the passed speed variable infinitesimally
{
  motor[leftRobotMotor] = 0; //stopping motors to eliminate course deviations
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  motor[leftRobotMotor] = -speed; //setting motors to speed variable. Since I want to turn left, making the left motor the negative of the value for the second motor
  motor[rightRobotMotor] = speed;
}

void MoveRobotLeft( int speed, int encoderValue ) //function for turning the robot left at a passed speed value for a certain amount of time
{
  motor[leftRobotMotor] = 0; //stopping motors to prevent course deviations
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  nMotorEncoder[leftRobotMotor] = 0; //resetting encoder values
  nMotorEncoder[rightRobotMotor] = 0;
  
  while ( nMotorEncoder[leftRobotMotor] <= encoderValue && nMotorEncoder[rightRobotMotor] <= encoderValue ) //while encoders have not moved past allowed distance
  {
    motor[leftRobotMotor] = -speed; //setting motors to passed speed variable power level
    motor[rightRobotMotor] = speed;
  }
  
  motor[leftRobotMotor] = 0; //stopping motors after the robots have moved for the set amount of time
  motor[rightRobotMotor] = 0;
}
task main() //main function; where the program will start at run
{
  //In here will be the main part of the autonomous program
  
  //We should call a function to complete the Catapult launch part of the autonomous stage
  /*
    call catapult launcher ( will handle everything including getting sensorvalues and determing the correct course of action )
  */
}

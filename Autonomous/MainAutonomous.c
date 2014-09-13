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

void moveRobotBackward( int speed ) //function for moving the robot backward
{
  motor[leftRobotMotor] = 0; //reset motors
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  motor[leftRobotMotor] = -speed; //go backward
  motor[rightRobotMotor] = -speed;
}

void moveRobotBackward( int speed, int encoderValue ) //function for moving the robot backward
{
  motor[leftRobotMotor] = 0; //reset motors
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  nMotorEncoder[leftRobotMotor] = 0; //reset motor encoders
  nMotorEncoder[rightRobotMotor] = 0;
  
  while ( nMotorEncoder[leftRobotMotor] <= encoderValue && nMotorEncoder[rightRobotMotor] <= encoderValue ) //while encoders havent gone pase what is allowed
  {
    motor[leftRobotMotor] = -speed; //go backward
    motor[rightRobotMotor] = -speed;
  }
  
  motor[leftRobotMotor] = 0; //stop motors
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

void moveRobotRight( int speed ) //function for moving right at a certain speed infinitesimally
{
  motor[leftRobotMotor] = 0; //reset motors
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  motor[leftRobotMotor] = speed; //turn right
  motor[rightRobotMotor] = -speed;
}

void moveRobotRight( int speed, int encoderValue ) //function for passing number of encoder ticks that motors should move before stopping
{
  motor[leftRobotMotor] = 0; //resetting motors
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  nMotorEncoder[leftRobotMove] = 0; //resetting robot motor encoders
  nMotorEncoder[rightRobotMove] = 0;
  
  while ( nMotorEncoder[leftRobotMotor] <= encoderValue && nMotorEncoder[rightRobotMotor] <= encoderValue ) //move while encoder ticks is less than the wanted amount
  {
    motor[leftRobotMotor] = speed; //turn right
    motor[rightRobotMotor] = -speed;
  }
  
  motor[leftRobotMotor] = 0; //once done, stop motors
  motor[rightRobotMotor] = 0;
}

void InitializeRobot() //function for initializing robot
{
  //In here, we should test all of the motors/moving parts of the robot by testing them for a couple of seconds, and then resetting the parts
}

void moveManipulator1( int encoderValue ) //function for moving the first manipulator ( Catapult ) a certain distance
{
  //In here, we need to move the first manipulator ( Catapult ) a certain degrees ( hence the encoderValue variable )
}

void moveManipulator1() //function for moving the first manipulator ( Catapult ) infinitesimally
{
  //In here, move the first manipulator ( Catapult )
}

void moveManipulator2( int encoderValue ) //function for moving the second manipulator ( lifter ) a certain height
{
  //In here, we need the "tower" to go up and drop the balls into the rolling ball "goal"
}

void moveManipulator2() //function for moving the second manipulator ( lifter ) a certain height
{
  //In here, move second manipulator ( lifter )
}

void catapultLauncher()
{
  //In here, we need to find IRBeacon and go to correct location
  //call moveManipulator2() with the eed 
}

task main() //main function; where the program will start at run
{
  //In here will be the main part of the autonomous program
  
  //Call InitializeRobot method
  
  //Move into position to launch catapult
  
  //We should call a function to complete the Catapult launch part of the autonomous stage
  /*
    call catapult launcher ( will handle everything including getting sensorvalues and determing the correct course of action )
  */
  
  //use ball in main ball manipulator to get into center ball holder
  //go to location used we want to be at when the autonomous stage is complete
}

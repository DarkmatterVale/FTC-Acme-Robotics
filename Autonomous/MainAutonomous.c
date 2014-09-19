//Put main code for Autonomous Program

//Var/Config lines
//Motors:
  //leftMotor
  //rightMotor
  //liftMotor
  //catapultMotor
//Sensors:
  //lightSensor
  //IRSensor
  //Accelerometer
  //DistanceSensor

void moveRobotForward( int speed ) //function for moving robot forward at a certain speed infinitesimally
{
  motor[leftRobotMotor] = 0; //stopping motors to eliminate course deviations
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  motor[leftRobotMotor] = speed; //setting the motors to the passed speed variable level power level
  motor[rightRobotMotor] = speed;
}

void moveRobotForward( int speed, int encoderValue ) //function for moving robot forward at a certain speed and for a certain amount of time
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

void initializeRobot() //function for initializing robot
{
  //In here, we should test all of the motors/moving parts of the robot by testing them for a couple of seconds, and then resetting the parts

  //Test main motors
    //Left movement motor and thus the left tread
    //right movement motor and thus the right tread
  
  //Test sensors, provide feedback on a small LED matrix, green for in the clear, red for not in the clear
  
  //Test lift
    //Bring lift up
    //Move ball container around
  
  //Test rolling goal holder
  
  //Test Catapult/Thrower ( POSSIBLE, NOT SET IN STONE )
}

void moveManipulator1( int encoderValue ) //function for moving the first manipulator ( Catapult ) a certain distance
{
  //In here, we need to move the first manipulator ( Catapult ) a certain degrees ( hence the encoderValue variable )
  
  //motor[catapultMotor] = 0;
  
  //while ( nMotorEncoder[catapultMotor] <= encoderValue )
  //{
  //}
  
  //motor[catapultMotor] = 0;
}

void moveManipulator1() //function for moving the first manipulator ( Catapult ) infinitesimally
{
  //In here, move the first manipulator ( Catapult )
  
  //move Manipulator1 motor ( motor[catapultMotor] = SPEED; )
}

void moveManipulator2( int encoderValue ) //function for moving the second manipulator ( lifter ) a certain height
{
  //In here, we need the "tower" to go up and drop the balls into the rolling ball "goal"
  
  //motor[liftMotor] = SPEED;
  
  //while ( nMotorEncoder[liftMotor] <= encoderValue )
  //{
  //}
  
  //motor[liftMotor] = 0;
  }
}

void moveManipulator2() //function for moving the second manipulator ( lifter ) a certain height
{
  //In here, move second manipulator ( lifter )
  
  //move Manipulator2 motor ( motor[liftMotor] = SPEED; )
}

void catapultLauncher() //function for dealing with the logic required to find the correct position, launch at a certain value of power
{
  //In here, we need to find IRBeacon and go to correct location
  
  //call findIRBeacon ( overloaded method, one for catapult, another for lift)
  
  //call moveManipulator1/2() with the correct encoder value
}

void pullBallHolder() //function for having the robot push the ball holders to the designated area
{
  //In here, we will need to have the robot push the ball holders/rollers into the box
  
  //find ball holder
    //seek IR beacon
    //based on location of IR Beacon and robot, move robot towards ball holder
  
  //drop ball holder "posts"
}

void seekIrBeacon()
{
  //Robot will successfully find IR beacon and drop ball in tube
  
  //find IR beacon
    //use tetrix IR sensor's grid to move:
      //right if the value is < than 5
      //left if the value is > than 5
      //straight if the value is = to 5
  
  //drop ball into container
}
task main() //main function; where the program will start at run
{
  //initializeRobot(); //initializing everything pertaining to the robot's function
  
  //seekIrBeacon(); //example calls
  
  //moveRobotForward(50);
  
  //here will be a function to raise the arm and lower it to drop starting ball into tube
  
  //In here will be the main part of the autonomous program
  
  //Call InitializeRobot method
  
  //POSSIBLE, NOT DECIDED
    //Move into position to launch catapult
  
    //We should call a function to complete the Catapult launch part of the autonomous stage
    /*
      call catapult launcher ( will handle everything including getting sensorvalues and determing the correct course of action )
    */
  
  //use ball in main ball manipulator to get into center ball holder
  
  //drop balls from center ball holder ( the one filled with balls at the beginning of the game )
  
  //move team goals to scoring area
  
  //go to location used we want to be at when the autonomous stage is complete
  
  //stop and wait for autonomous to end
}

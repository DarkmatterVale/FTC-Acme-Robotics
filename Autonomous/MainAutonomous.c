//Main source code for autonomous period goes in here

//Var/Config lines
//Motors:
  //leftMotor
  //rightMotor
  //liftMotor
  //catapultMotor
//Sensors:
  //lightSensor ( two at the front of the robot )
  //IRSensor
    //WE MIGHT USE MULTIPLE IRSENSORS. IT MIGHT BE NEEDED TO TRIANGULATE IRBEACON
  //Accelerometer
  //DistanceSensor ( double ultrasonic sensors )
  //Compass sensor
    //WE MIGHT NEED THIS TO DETERMINE WHERE WE ARE FACING, TO HELP US DECIDE HOW TO MOVE ( Forwards, backwards, left, right )
  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                        Autonomous mode program for FTC Team 7983
//
//In this program, our overall goal is to have the robot score as many points as possible, in as little time as possible
//
//                                                Goals for Autonomous mode:
//                                            1. Drive robot from ramp to floor
//                                          2. Drop kickstand in center ball holder
//                                3. Load/Shoot autonomous loaded balls into center ball holders
//                                                4. Grab a goal and hold it
//                              5. Move to position we would like it to be at at end of autonomous
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

***VERY IMPORTANT***

NOT ALL OF THE FOLLOWING METHODS WILL BE USED. I HAVE INCLUDED THEM ALL JUST TO BE ON THE SAFE SIDE OF WHAT MIGHT BE USEFUL

Additionally, we might only have 1 manipulator, eliminating one set of manipulator methods. We might eliminate both of these
manipulators and their associated methods and add additional methods to best suite a new manipulator.

*/

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

void findThreshHold() //function for finding/setting the threshhold for the light sensor
{
  //In this function, we need to set the threshhold for the light sensor
  
  //We need to get values for:
    //Red ramp
    //Blue ramp
    //Red ground
    //Blue ground
    //Normal ground ( grey mat )
    //Yellow platform
    //Red stick in center yellow
    //Blue stick in center yellow
  
  /*
  
  NOT ALL OF THE FOLLOWING VALUES WILL BE USED. I JUST ADDED THEM TO MAKE SURE WE HAVE ALL THAT WE COULD NEED
  
  */
    
  //Get Red ramp value
  nxtDisplayTextLine( 0, "%s", "Place light sensor over " );
  nxtDisplayTextLine( 1, "%s", "the red ramp, then " );
  nxtDisplayTextLine( 2, "%s", "push the orange button" );

  while ( !( nNxtButtonPressed == 3 ) )
  {
	nxtDisplayTextLine( 3, "%s, %d", "light value: ", SensorValue[ lightSensor ] );
  }

  VARIABLE USED = SensorValue[ lightSensor ];
  
  //Get Blue ramp value
  nxtDisplayTextLine( 0, "%s", "Place light sensor over " );
  nxtDisplayTextLine( 1, "%s", "tbe blue ramp, then " );
  nxtDisplayTextLine( 2, "%s", "push the orange button" );

  while ( !( nNxtButtonPressed == 3 ) )
  {
	nxtDisplayTextLine( 3, "%s, %d", "light value: ", SensorValue[ lightSensor ] );
  }

  VARIABLE USED = SensorValue[ lightSensor ];
  
  //Get red surface value
  nxtDisplayTextLine( 0, "%s", "Place light sensor over " );
  nxtDisplayTextLine( 1, "%s", "red surface line, then " );
  nxtDisplayTextLine( 2, "%s", "push the orange button" );

  while ( !( nNxtButtonPressed == 3 ) )
  {
	nxtDisplayTextLine( 3, "%s, %d", "light value: ", SensorValue[ lightSensor ] );
  }

  VARIABLE USED = SensorValue[ lightSensor ];
  
  //Get blue surface value
  nxtDisplayTextLine( 0, "%s", "Place light sensor over " );
  nxtDisplayTextLine( 1, "%s", "blue surface line, then " );
  nxtDisplayTextLine( 2, "%s", "push the orange button" );

  while ( !( nNxtButtonPressed == 3 ) )
  {
	nxtDisplayTextLine( 3, "%s, %d", "light value: ", SensorValue[ lightSensor ] );
  }

  VARIABLE USED = SensorValue[ lightSensor ];
  
  //Get grey mat value
  nxtDisplayTextLine( 0, "%s", "Place light sensor over " );
  nxtDisplayTextLine( 1, "%s", "gray mat, then " );
  nxtDisplayTextLine( 2, "%s", "push the orange button" );

  while ( !( nNxtButtonPressed == 3 ) )
  {
	nxtDisplayTextLine( 3, "%s, %d", "light value: ", SensorValue[ lightSensor ] );
  }

  VARIABLE USED = SensorValue[ lightSensor ];
  
  //Get yellow platform value
  nxtDisplayTextLine( 0, "%s", "Place light sensor over " );
  nxtDisplayTextLine( 1, "%s", "yellow platform, then " );
  nxtDisplayTextLine( 2, "%s", "push the orange button" );

  while ( !( nNxtButtonPressed == 3 ) )
  {
	nxtDisplayTextLine( 3, "%s, %d", "light value: ", SensorValue[ lightSensor ] );
  }

  VARIABLE USED = SensorValue[ lightSensor ];
  
  //Get red stick value
  nxtDisplayTextLine( 0, "%s", "Place light sensor on " );
  nxtDisplayTextLine( 1, "%s", "red stick, then " );
  nxtDisplayTextLine( 2, "%s", "push the orange button" );

  while ( !( nNxtButtonPressed == 3 ) )
  {
	nxtDisplayTextLine( 3, "%s, %d", "light value: ", SensorValue[ lightSensor ] );
  }

  VARIABLE USED = SensorValue[ lightSensor ];
  
  //Get blue stick value
  nxtDisplayTextLine( 0, "%s", "Place light sensor on " );
  nxtDisplayTextLine( 1, "%s", "blue stick, then " );
  nxtDisplayTextLine( 2, "%s", "push the orange button" );

  while ( !( nNxtButtonPressed == 3 ) )
  {
	nxtDisplayTextLine( 3, "%s, %d", "light value: ", SensorValue[ lightSensor ] );
  }

  VARIABLE USED = SensorValue[ lightSensor ];
}

void initializeRobot() //function for initializing robot
{
  //In here, we should test all of the motors/moving parts of the robot by testing them for a couple of seconds, and then resetting the parts

  //Find/Set threshhold for light sensor by calling findThreshHold()
  
  //Test main motors
    //Left movement motor and thus the left tread
    //right movement motor and thus the right tread
    
    //example:
      //motor[rightMotor] = 70;
      //motor[leftMotor] = 70;
  
  //Test sensors, provide feedback on a small LED matrix, green for in the clear, red for not in the clear
    //feedback from the distance sensor ( SensorValue[distanceSensor] != 0 )
    //feedback from the light sensor ( SensorValue[lightSensor] != 0 )
    //feedback from the accelerometer ( SensorValue[accelerometerSensor] != 0 )
    //feedback from the IR Sensor ( SensorValue[IRSensor] != 0 )
  
  //Test lift
    //Bring lift up
      //motor[liftMotor] = 70;
      //for a certain amount of time:
        //wait1Msec( HEIGHT WANTED )
        //motor[liftMotor] = 0;
        //
        //while ( nMotorEncoder[liftMotor] <= HEIGHT WANTED )
        //{
        //}
        //motor[liftMotor] = 0;
        
    //Move ball container around
      //move servo a full rotation
  
  //Test rolling goal holder
    //drop posts
  
  //Test Catapult/Thrower ( POSSIBLE, NOT SET IN STONE )
    //Mock launch as a test
}

void moveManipulator1( int encoderValue ) //function for moving the first manipulator ( Catapult ) a certain distance
{
  //In here, we need to move the first manipulator ( Catapult ) a certain degrees ( hence the encoderValue variable )
  
  //motor[catapultMotor] = SPEED;
  
  //while ( nMotorEncoder[catapultMotor] <= encoderValue )
  //{
  //}
  
  //motor[catapultMotor] = 0;
}

void moveManipulator1( int encoderValue, int speed ) //function for moving the first manipulator ( Catapult ) a certain distance
{
  //In here, we need to move the first manipulator ( Catapult ) a certain degrees ( hence the encoderValue variable )
  
  //motor[catapultMotor] = speed;
  
  //while ( nMotorEncoder[catapultMotor] <= encoderValue )
  //{
  //}
  
  //motor[catapultMotor] = 0;
}

void moveManipulator1() //function for moving the first manipulator ( Catapult ) infinitesimally
{
  //In here, move the first manipulator ( Catapult )
  
  //move Manipulator1
  
  //motor ( motor[catapultMotor] = SPEED; )
}

void moveManipulator1( int speed ) //function for moving the first manipulator ( Catapult ) infinitesimally
{
  //In here, move the first manipulator ( Catapult )
  
  //move Manipulator1
  
  //motor ( motor[catapultMotor] = speed; )
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

void moveManipulator2( int encoderValue, int speed ) //function for moving the second manipulator ( lifter ) a certain height
{
  //In here, we need the "tower" to go up and drop the balls into the rolling ball "goal"
  
  //motor[liftMotor] = speed;
  
  //while ( nMotorEncoder[liftMotor] <= encoderValue )
  //{
  //}
  
  //motor[liftMotor] = 0;
}

void moveManipulator2() //function for moving the second manipulator ( lifter ) a certain height
{
  //In here, move second manipulator ( lifter )
  
  //move Manipulator2
  
  //motor ( motor[liftMotor] = SPEED; )
}

void moveManipulator2( int speed ) //function for moving the second manipulator ( lifter ) a certain height
{
  //In here, move second manipulator ( lifter )
  
  //move Manipulator2
  
  //motor ( motor[liftMotor] = speed; )
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
      //call findIRBeacon
        //MAYBE WE SHOULD OVERLOAD THE METHOD, ALLOWING FOR A MORE CASE BY CASE DEALING WITH WHAT WE DO WHEN WE FIND THE IR BEACON
    //based on location of IR Beacon and robot, move robot towards ball holder
  
  //drop ball holder posts
}

void seekIrBeacon() //function for finding and moving to IR Beacon
{
  //Robot will successfully find IR beacon and drop ball in tube
  
  //find IR beacon
    //use tetrix IR sensor's grid to move:
      //if the value is < than 5
        //turn robot to the right
      //if the value is > than 5
        //turn robot to the left
      //if the value is = to 5
        //go straight
  
  //drop ball into container
    //call moveManipulator1/2( lift ) with encodervalue
    //bring manipulator/lift back down
      //call moveManipulator1/2( lift ) with -encodervalue and -speed level
}

void dragGoalsIntoScoringZone() //function for dragging goals into scoring zone
{
  //Successfully have robot drag goals into scoring zone
  
  //for ( int i = 0; i < 3; i++ )
  //{
    //find goals
      //find current position
        //find IR beacon
      //move towards goal
      //turn around
  
    //grab goal
      //drop posts
  
    //drag to scoring zone
      //move towards scoring zone
  //}
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

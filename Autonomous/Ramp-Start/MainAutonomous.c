//Var/Config pragma lines
	//Motors:
  		//leftMotor
  		//rightMotor
  		//liftMotor
  		//catapultMotor
	//Sensors:
  		//lightSensor ( two at the front of the robot )
  		//IRSensor
  		//Accelerometer
  		//DistanceSensor
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

Author(s):
	- Vale Tolpegin
	
*/

/*

***VERY IMPORTANT---PLEASE READ***

NOT ALL OF THE FOLLOWING METHODS WILL BE USED. I HAVE INCLUDED THEM ALL JUST TO BE ON THE SAFE SIDE OF WHAT MIGHT BE USEFUL

Additionally, we might only have 1 manipulator, eliminating one set of manipulator methods. We might eliminate both of these
manipulators and their associated methods and add additional methods to best suite a new manipulator.

*/

//GLOBAL VARIABLES
	//GLOBAL VARIABLES' DECLARATIONS GO HERE
	
/*
To Do list:
	- Move manipulator 1 method needs to be overloaded

*/
void HTSMUXhalt( tSensors smux )
{
  //Creating message to send
  ubyte sendMsg[4];
  
  //Assigning message info
  sendMsg[0] = 3;
  sendMsg[1] = 0x10;
  sendMsg[2] = 0x20;
  sendMsg[3] = 0;
  
  //Sending message
  sendI2CMsg( smux, sendMsg, 0 );
  
  //Required wait time
  wait1Msec( 50 );
}

void HTSMUXautodetect( tSensors smux )
{
  //Creating message to send
  ubyte sendMsg[4];
  
  //Assigning message info
  sendMsg[0] = 3;
  sendMsg[1] = 0x10;
  sendMsg[2] = 0x20;
  sendMsg[3] = 1;
  
  //Sending message
  sendI2CMsg( smux, sendMsg, 0 );
  
  //Required wait time
  wait1Msec( 500 );
}

void HTSMUXrun( tSensors smux )
{
  //Creating message to send
  ubyte sendMsg[4];
  
  //Assigning message info
  sendMsg[0] = 3;
  sendMsg[1] = 0x10;
  sendMsg[2] = 0x20;
  sendMsg[3] = 2;
  
  //Send message
  sendI2CMsg( smux, sendMsg, 0 );
}

void moveRobotForward( int speed )
{
  /*
  Rev 1.0
  This function will move the robot forward at a certain speed infinitesimally
  
  Variables Used:
  	speed        ---used to set power level that the motors are set
  
  Inputs:
  	Passed speed variable
  Outputs:
  	leftRobotMotor
  	rightRobotMotor
  	
  To Do:
  	NONE
  	
  Author(s):
  	Vale Tolpegin
  */
  	
  	
  motor[leftRobotMotor] = 0; //stopping motors to eliminate any possible course deviations
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  motor[leftRobotMotor] = speed; //setting the motors to the passed speed variable level power level ( in percent of highest possible speed )
  motor[rightRobotMotor] = speed;
}

void moveRobotForward( int speed, int encoderValue )
{
  /*
  Rev 1.0
  This function will move the robot forward at a certain speed for a certain number of encoder ticks
  
  Variables Used:
  	speed        ---used to set power level for the motors
  	encoderValue ---used as the judge for when to stop the motors
  
  Inputs:
  	Passed speed variable
  	Passed encoderValue variable
  	leftRobotMotor encoder
  	rightRobotMotor encoder
  Outputs:
  	leftRobotMotor
  	rightRobotMotor
  	
  To Do:
  	NONE
  
  Author(s):
  	Vale Tolpegin
  */
  	
  	
  motor[leftRobotMotor] = 0; //stopping motors to eliminate any possible course deviations
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

void moveRobotBackward( int speed )
{
  /*
  Rev 1.0
  This function is used to move the robot backward at a certain speed
  
  Variables Used:
  	speed        ---used to set the power level for the motors
  
  Inputs:
  	Passed speed variable
  Outputs:
  	leftRobotMotor
  	rightRobotMotor
  	
  To Do:
  	NONE
  
  Author(s):
  	Vale Tolpegin
  */	
  	
  	
  motor[leftRobotMotor] = 0; //reset motors
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  motor[leftRobotMotor] = -speed; //go backward
  motor[rightRobotMotor] = -speed;
}

void moveRobotBackward( int speed, int encoderValue )
{
  /*
  Rev 1.0
  This function is used for moving the robot backward at a certain speed for a certain number of encoder ticks
  
  Variables Used:
  	speed        ---used to set the power level for the motors
  	encoderValue ---used as the judge for when to stop the motors
  
  Inputs:
  	Passed speed variable
  	Passed encoderValue variable
  	leftRobotMotor encoder
  	rightRobotMotor encoder
  Outputs:
  	leftRobotMotor
  	RightRobotMotor
  
  To Do:
  	NONE
  
  Author(s):
  	Vale Tolpegin
  */
  	
  	
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

void moveRobotLeft( int speed )
{
  /*
  Rev 1.0
  This function is used for turning the robot left at the passed speed variable infinitesimally
  
  Inputs:
  	Passed speed variable
  Outputs:
  	leftRobotMotor
  	RightRobotMotor
  
  To Do:
  	NONE
  
  Author(s):
  	Vale Tolpegin
  */	
  	
  	
  motor[leftRobotMotor] = 0; //stopping motors to eliminate course deviations
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  motor[leftRobotMotor] = -speed; //setting motors to speed variable. Since I want to turn left, making the left motor the negative of the value for the second motor
  motor[rightRobotMotor] = speed;
}

void moveRobotLeft( int speed, int encoderValue )
{
  /*
  Rev 1.0
  This function is used for turning the robot left at a passed speed value for a certain number of encoder ticks
  
  Inputs:
  	Passed speed variable
  	Passed encoderValue variable
  	leftRobotMotor encoder
  	rightRobotMotor encoder
  Outputs:
  	leftRobotMotor
  	rightRobotMotor
  
  To Do:
  	NONE
  	
  Author(s):
  	Vale Tolpegin
  */
  
  
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

void moveRobotRight( int speed )
{
  /*
  Rev 1.1
  This function is used for turning the robot to the right at a certain speed infinitesimally
  
  Inputs:
  	Passed speed variable
  Outputs:
  	leftRobotMotor
  	rightRobotMotor
  
  To Do:
  	NONE
  	
  Author(s):
  	Vale Tolpegin
  */
  
  
  motor[leftRobotMotor] = 0; //reset motors
  motor[rightRobotMotor] = 0;
  wait1Msec( 50 );
  
  motor[leftRobotMotor] = speed; //turn right
  motor[rightRobotMotor] = -speed;
}

void moveRobotRight( int speed, int encoderValue )
{
  /*
  Rev 1.0
  This function is used for turning the robot to the right at a certain speed for a certain number of encoder ticks
  
  Inputs:
  	Passed speed variable
  	Passed encoderValue variable
  	leftRobotMotor encoder
  	rightRobotMotor encoder
  	
  Outputs:
  	leftRobotMotor
  	rightRobotMotor
  
  To Do:
  	NONE
  	
  Author(s):
  	Vale Tolpegin
  */
  
  
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

void findThreshHold()
{
  /*
  Rev 2.0
  In this function, we need to set the threshhold(s) for the light sensor and tell it the values of all of the lines on the board
  
  Inputs:
  	color sensor
  	orange button on NXT
  	
  Outputs:
  	Variables' values
  
  To Do:
  	Figure out variable scheme ( what variables that are set here need to be global, what variables do we need, etc )
  
  Author(s):
  	Vale Tolpegin
  */
  
  //We need to get values for:
    //ramp
    //ground tape
    //Normal ground ( grey mat )
    
  //Get ramp value
  nxtDisplayTextLine( 0, "%s", "Place light sensor over " );
  nxtDisplayTextLine( 1, "%s", "the red ramp, then " );
  nxtDisplayTextLine( 2, "%s", "push the orange button" );

  while ( !( nNxtButtonPressed == 3 ) )
  {
	nxtDisplayTextLine( 3, "%s, %d", "light value: ", SensorValue[ lightSensor ] );
  }

  VARIABLE USED = SensorValue[ lightSensor ];
  
  //Get surface value
  nxtDisplayTextLine( 0, "%s", "Place light sensor over " );
  nxtDisplayTextLine( 1, "%s", "red surface line, then " );
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
}

void initializeRobot()
{
  /*
  Rev 1.1
  In here, we should test all of the motors/moving parts of the robot by testing them for a couple of seconds, and then resetting the parts

  Inputs:
  	servos
  	sensors
  Outputs:
  	servos
  
  To Do:
  	Remove code related to motors
  	Continue to develop until working prototype
  
  Author(s):
  	Vale Tolpegin
  */
  
  
  //Find/Set threshhold for light sensor by calling findThreshHold()
  
  //Test main motors
    //Left movement motor and thus the left tread
    	//motor[leftMotor] = 70;
    //right movement motor and thus the right tread
      //motor[rightMotor] = 70;
  
  //Test sensors, provide feedback on a small LED matrix, green for in the clear, red for not in the clear
    //feedback from the distance sensor ( SensorValue[distanceSensor] != 0 )
    //feedback from the 2nd distance sensor ( SensorValue[distanceSensor2] != 0 )
    //feedback from the light sensor ( SensorValue[lightSensor] != 0 )
    //feedback from the 2nd light sensor ( SensorValue[lightSensor2] != 0 )
    //feedback from the gyroscope ( SensorValue[gyroscopeSensor] != 0 )
    //feedback from the IR Sensor ( SensorValue[IRSensor] != 0 )
    //feedback from the 2nd IR Sensor ( SensorValue[IRSensor2] != 0 )
    //feedback from the Compass ( SensorValue[compassSensor] != 0 )
  
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
    //drop post
}

void moveManipulator( int encoderValue )
{
  /*
  Rev 1.0
  In here, we need the "tower" to go up and drop the balls into the rolling ball "goal"
  
  Inputs:
  	Passed encoderValue variable
  	liftMotor encoder value
  Outputs:
  	liftMotor
  
  To Do:
  	Add SPEED value
  	Change method name more appropriate for procedure function
  
  Author(s):
  	Vale Tolpegin
  */
  
  
  //motor[liftMotor] = SPEED;
  
  //while ( nMotorEncoder[liftMotor] <= encoderValue )
  //{
  //}
  
  //motor[liftMotor] = 0;
}

void moveManipulator( int encoderValue, int speed )
{
  /*
  Rev 1.0
  In here, we need the "tower" to go up and drop the balls into the rolling ball "goal"
  
  Inputs:
  	Passed encoderValue variable
  	Passed speed variable
  	liftMotor encoder value
  Outputs:
  	liftMotor
  
  To Do:
  	Add SPEED value
  	Change method name more appropriate for procedure function
  
  Author(s):
  	Vale Tolpegin
  */
  
  
  //motor[liftMotor] = SPEED;
  
  //while ( nMotorEncoder[liftMotor] <= encoderValue )
  //{
  //}
  
  //motor[liftMotor] = 0;
}

void dragGoalsIntoScoringZone() //function for dragging goals into scoring zone
{
  /*
  Rev 1.0
  In here, we will need to have the robot push the ball holders/rollers into the box
  
  Inputs:
  	IR sensor
  	Compass sensor
  Outputs:
  	functions invoked
  
  To Do:
  	Change method name more appropriate for procedure function
  	Edit and be more detailed in Inputs and Outputs area
  
  Author(s):
  	Vale Tolpegin
  */
  
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

task main()
{
  /*
  Rev 1.0
  This is the main task which begins running once the competition starts
  
  To Do:
  	NONE
  
  Author(s):
  	Vale Tolpegin
  */
  
  //Call InitializeRobot method
  
  //drop balls for center ball holder ( the one filled with balls at the beginning of the game )
  
  //move team goals to scoring area
  
  //stop and wait for autonomous to end
}

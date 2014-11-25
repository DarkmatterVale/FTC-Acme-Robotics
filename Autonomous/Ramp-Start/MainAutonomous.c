#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     lightSensor,    sensorNone)
#pragma config(Sensor, S2,     SonarSensor,    sensorNone)
#pragma config(Motor,  mtr_S1_C1_1,     leftDriveMotor, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     rightDriveMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)r
	//Sensors:
  		//lightSensor ( two at the front of the robot )
  		//lightSensor 2
  		//IRSensor
  		//IRSensor 2
  		//Gyroscope
  		//DistanceSensor
  		//DistanceSensor 2
  		//Compass sensor
  
//Defines
//motors
#define FORWARD_STANDARD 70
#define FORWARD_FULL 100
#define STOP 0
#define BACKWARD_STANDARD 70
#define BACKWARD_FULL 100

//lift
#define LIFT_POSITION_0 0
#define LIFT_POSITION_1 100
#define LIFT_POSITION_2 200
#define LIFT_POSITION_3 300
#define LIFT_POSITION_4 400

//servo
#define SERVO_DOWN 180
#define SERVO_UP 0

//Includes
#include "drivers/hitechnic-sensormux.h"
#include "drivers/hitechnic-colour-v2.h"
#include "drivers/hitechnic-compass.h"
#include "drivers/hitechnic-gyro.h"
#include "drivers/hitechnic-irseeker-v2.h"
#include "drivers/lego-ultrasound.h"
  
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

//Global variables' declarations
int matValue =     0;
int surfaceValue = 0;
int rampValue =    0;

void haltRobot()
{
  /*
  Rev 1.0
  This function is used to stop the robot
  
  Variables Used:
  	NONE
  
  Inputs:
  	NONE
  Outputs:
  	leftRobotMotor ( left drive motor )
  	rightRobotMotor ( right drive motor )
  	
  To Do:
  	NONE
  
  Author(s):
  	Vale Tolpegin
  */
  
  motor[ leftDriveMotor ]  = 0;
  motor[ rightDriveMotor ] = 0;
  wait1Msec( 100 );
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
  	
  	
  motor[ leftDriveMotor ]  = 0; //stopping motors to eliminate any possible course deviations
  motor[ rightDriveMotor ] = 0;
  wait1Msec( 50 );
  
  motor[ leftDriveMotor ]  = speed; //setting the motors to the passed speed variable level power level ( in percent of highest possible speed )
  motor[ rightDriveMotor ] = speed;
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
  	
  	
  motor[ leftDriveMotor ]  = 0; //stopping motors to eliminate any possible course deviations
  motor[ rightDriveMotor ] = 0;
  wait1Msec( 50 );
  
  nMotorEncoder[ leftDriveMotor ]  = 0; //resetting encoder values
  nMotorEncoder[ rightDriveMotor ] = 0;
  
  while ( nMotorEncoder[ leftDriveMotor ] <= encoderValue && nMotorEncoder[ rightDriveMotor ] <= encoderValue ) //while encoders have not moved past allowed distance
  {
    motor[ leftDriveMotor ]  = speed; //setting motors to passed speed variable power level
    motor[ rightDriveMotor ] = speed;
  }
  
  motor[ leftDriveMotor ]  = 0; //stopping motors after movement duration has occurred
  motor[ rightDriveMotor ] = 0;
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
  
  	
  motor[ leftDriveMotor ]  = 0; //reset motors
  motor[ rightDriveMotor ] = 0;
  wait1Msec( 50 );
  
  motor[ leftDriveMotor ]  = -speed; //go backward
  motor[ rightDriveMotor ] = -speed;
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
  	
  	
  motor[ leftDriveMotor ]  = 0; //reset motors
  motor[ rightDriveMotor ] = 0;
  wait1Msec( 50 );
  
  nMotorEncoder[ leftDriveMotor ]  = 0; //reset motor encoders
  nMotorEncoder[ rightDriveMotor ] = 0;
  
  while ( nMotorEncoder[ leftDriveMotor ] <= encoderValue && nMotorEncoder[ rightDriveMotor ] <= encoderValue ) //while encoders havent gone pase what is allowed
  {
    motor[ leftDriveMotor ]  = -speed; //go backward
    motor[ rightDriveMotor ] = -speed;
  }
  
  motor[ leftDriveMotor ]  = 0; //stop motors
  motor[ rightDriveMotor ] = 0;
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
  	
  	
  motor[ leftDriveMotor ]  = 0; //stopping motors to eliminate course deviations
  motor[ rightDriveMotor ] = 0;
  wait1Msec( 50 );
  
  motor[ leftDriveMotor ]  = -speed; //setting motors to speed variable. Since I want to turn left, making the left motor the negative of the value for the second motor
  motor[rightDriveMotor ] = speed;
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
  
  
  motor[ leftDriveMotor ]  = 0; //stopping motors to prevent course deviations
  motor[ rightDriveMotor ] = 0;
  wait1Msec( 50 );
  
  nMotorEncoder[ leftDriveMotor ]  = 0; //resetting encoder values
  nMotorEncoder[ rightDriveMotor ] = 0;
  
  while ( nMotorEncoder[ leftDriveMotor ] <= encoderValue && nMotorEncoder[ rightDriveMotor ] <= encoderValue ) //while encoders have not moved past allowed distance
  {
    motor[ leftDriveMotor ]  = -speed; //setting motors to passed speed variable power level
    motor[ rightDriveMotor ] = speed;
  }
  
  motor[ leftDriveMotor ]  = 0; //stopping motors after the robots have moved for the set amount of time
  motor[ rightDriveMotor ] = 0;
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
  
  
  motor[leftDriveMotor] = 0; //reset motors
  motor[rightDriveMotor] = 0;
  wait1Msec( 50 );
  
  motor[ leftDriveMotor ]  = speed; //turn right
  motor[ rightDriveMotor ] = -speed;
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
  
  
  motor[ leftDriveMotor]   = 0; //resetting motors
  motor[ rightDriveMotor ] = 0;
  wait1Msec( 50 );
  
  nMotorEncoder[ leftDriveMotor ]  = 0; //resetting robot motor encoders
  nMotorEncoder[ rightDriveMotor ] = 0;
  
  while ( nMotorEncoder[ leftDriveMotor ] <= encoderValue && nMotorEncoder[ rightDriveMotor ] <= encoderValue ) //move while encoder ticks is less than the wanted amount
  {
    motor[ leftDriveMotor ]  = speed; //turn right
    motor[ rightDriveMotor ] = -speed;
  }
  
  motor[ leftDriveMotor ]  = 0; //once done, stop motors
  motor[ rightDriveMotor ] = 0;
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
  	NONE
  
  Author(s):
  	Vale Tolpegin
  */
  
  //We need to get values for:
    //ramp
    //ground tape
    //Normal ground ( grey mat )
    
  //Get ramp value
  nxtDisplayCenteredTextLine( 0, "Place light sensor over " );
  nxtDisplayCenteredTextLine( 1, "the red ramp, then " );
  nxtDisplayCenteredTextLine( 2, "push the orange button" );

  while ( !( nNxtButtonPressed == 3 ) )
  {
	nxtDisplayCenteredTextLine( 3, " light value: %d", SensorValue[ lightSensor ] );
  }

  rampValue = SensorValue[ lightSensor ];
  
  //Get surface value
  nxtDisplayCenteredTextLine( 0, "Place light sensor over " );
  nxtDisplayCenteredTextLine( 1, "red surface line, then " );
  nxtDisplayCenteredTextLine( 2, "push the orange button" );

  while ( !( nNxtButtonPressed == 3 ) )
  {
	nxtDisplayCenteredTextLine( 3, "light value: %d", SensorValue[ lightSensor ] );
  }

  surfaceValue = SensorValue[ lightSensor ];
  
  //Get grey mat value
  nxtDisplayCenteredTextLine( 0, "Place light sensor over " );
  nxtDisplayCenteredTextLine( 1, "gray mat, then " );
  nxtDisplayCenteredTextLine( 2, "push the orange button" );

  while ( !( nNxtButtonPressed == 3 ) )
  {
	nxtDisplayCenteredTextLine( 3, "light value: %d", SensorValue[ lightSensor ] );
  }

  matValue = SensorValue[ lightSensor ];
}

void initializeRobot()
{
  /*
  Rev 1.4
  In here, we should test all of the motors/moving parts of the robot by testing them for a couple of seconds, and then resetting the parts

  Inputs:
  	servos
  	sensors
  Outputs:
  	servos
  	motors
  
  To Do:
  	NONE
  
  Author(s):
  	Vale Tolpegin
  */
  
  
  //Find/Set threshhold for light sensor by calling findThreshHold()
  findThreshHold();
  
  //Test main motors
  motor[ leftDriveMotor ]  = 10;
  motor[ rightDriveMotor ] = 10;
  wait1Msec( 1000 );
  
  haltRobot();
  
  //Test lift
  motor[ liftMotor ] = 70;
  wait1Msec( 2000 );
  
  haltRobot();
        
  //Move ball container around
  servo[ servo1 ] = 180;
  wait1Msec( 1000 );
  servo[ servo1 ] = 0;
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
  	NONE
  
  Author(s):
  	Vale Tolpegin
  */
  
  //reset encoder
  nMotorEncoder[ liftMotor ] = 0;
  
  //start lift motor
  motor[liftMotor] = FORWARD_STANDARD;
  
  if ( encoderValue > 0 )
  {
  	//while lift has not reached wanted position
  	while ( nMotorEncoder[liftMotor] < encoderValue )
  	{
  	}
  	
  	motor[ liftMotor ] = STOP;
  } else if ( encoderValue < 0 )
  {
  	//while lift has not reached wanted position
  	while ( nMotorEncoder[liftMotor] > encoderValue )
  	{
  	}
  	
  	motor[ liftMotor ] = STOP;
  }
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
	NONE
  
  Author(s):
  	Vale Tolpegin
  */
  
  
  //reset encoder
  nMotorEncoder[ liftMotor ] = 0;
  
  //start lift motor
  motor[liftMotor] = speed;
  
  if ( encoderValue > 0 )
  {
  	//while lift has not reached wanted position
  	while ( nMotorEncoder[liftMotor] < encoderValue )
  	{
  	}
  	
  	motor[ liftMotor ] = STOP;
  } else if ( encoderValue < 0 )
  {
  	//while lift has not reached wanted position
  	while ( nMotorEncoder[liftMotor] > encoderValue )
  	{
  	}
  	
  	motor[ liftMotor ] = STOP;
  }
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
      //drop post
  
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
  	Add code
  
  Author(s):
  	Vale Tolpegin
  */
  
  //Call InitializeRobot method
  initializeRobot();
  
  //move toward goal(s)
  moveRobotBackward( 70, 18720 );	
  
  //grab goal
  servo[ servo1 ] = 0;
  
  //drop ball in goal
  moveManipulator( 100, 90 );
  
  //turn the robot
  moveRobotRight( 50, 800 );
  
  //move team goals to scoring area
  while ( SensorValue[ SonarSensor ] > 20 )
  {
  	motor[ leftDriveMotor ]  = 70;
  	motor[ rightDriveMotor ] = 70;
  }
  
  //stop
  haltRobot();
}

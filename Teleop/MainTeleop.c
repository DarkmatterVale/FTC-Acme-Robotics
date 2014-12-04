#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftDriveMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     rightDriveMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     liftMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//defines
#define FIRST_LIFT_POSITION 100
#define SECOND_LIFT_POSITION 200
#define THIRD_LIFT_POSITION 300
#define FOURTH_LIFT_POSITION 400
#define ZERO_LIFT_POSITION 0

#define GOAL_HOLDER_ACTIVE 100
#define GOAL_HOLDER_INACTIVE 0

#define BTN_X 0 //Switch to match button numbers
#define BTN_Y 1 //Swtich to match button numbers

/*

  Joystick 1 will move the robot's drive motors -> Aiden will be the driver
  Joystick 2 will move the robot's lift -> Vale will drive the lift and other manipulators

*/

//includes
#include "JoystickDriver.c";

void moveMotor( int encoderValue, int speed );

task main()
{
  /*
  Rev 1.0
  This is the main task that will allow the robot to be driven and controlled during teleop

  Variables Used:
  	NONE

  Inputs:
  	Joysticks
  Outputs:
  	Drive motors ( leftDriveMotor and rightDriveMotor )
  	Lift motor
  	Goal holder

  To Do:
  	-Add code for 2nd joystick

  Author(s):
  	Vale Tolpegin
  */

  //creating variables that will hold position values for manipulators
  int liftPosition = 0;
  int goalHolderPosition = 0;

  //while loop ( forever ) or until program terminated
  while ( true )
  {
    //getjoysticksettings()
    getJoystickSettings( joystick );

    //set the drive motors
    motor[ rightDriveMotor ]  = -1 * ( int ) pow( 0.000046 * joystick.joy1_y1, 3 );
    motor[ leftDriveMotor ] = -1 * ( int ) pow( 0.000046 * joystick.joy1_y2, 3 );

    //getjoysticksettings
    getJoystickSettings( joystick );

    //if joystick button ( button that will use tower lift to go up) is pressed
    if ( joy2Btn( 3 ) == 1 )
    {
      //move tower lift up to the next position
      switch ( liftPosition )
      {
        case 0:
          moveMotor( FIRST_LIFT_POSITION, 60 );
          break;
        case 1:
          moveMotor( SECOND_LIFT_POSITION, 60 );
          break;
        case 2:
          moveMotor( THIRD_LIFT_POSITION, 60 );
          break;
        case 3:
          moveMotor( FOURTH_LIFT_POSITION, 60 );
          break;
        case 4:
          break;
      }
    }

    //if joystick button ( button that will use tower lift to go down) is pressed
    else if ( joy2Btn( 0 ) == 1 )
    {
      //move tower lift down to the next position
      switch ( liftPosition )
      {
        case 0:
          break;
        case 1:
          moveMotor( -1 * FIRST_LIFT_POSITION, -60 );
          break;
        case 2:
          moveMotor( -1 * SECOND_LIFT_POSITION, -60 );
          break;
        case 3:
          moveMotor( -1 * THIRD_LIFT_POSITION, -60 );
          break;
        case 4:
          moveMotor( -1 * FOURTH_LIFT_POSITION, -60 );
          break;
      }
    }

    //if button to lock rolling goal to robot is pressed
    if ( joy1Btn( 1 ) == 1 )
    {
      //lock goal to robot
      servo[ servo1 ] = 0;
    }

    //else if button ( button to release goal ) is pressed
    else if ( joy1Btn( 2 ) == 1 )
    {
      //release goal
      servo[ servo1 ] = 130;
    }

  } //end while loop
}

void moveMotor( int encoderValue, int speed )
{
  int tempEncoderValue = nMotorEncoder[ liftMotor ];

  if ( nMotorEncoder[ liftMotor ] > 0 )
  {
    while ( ( nMotorEncoder[ liftMotor ] - tempEncoderValue ) < encoderValue )
    {
      motor[ liftMotor ] = speed;
    }

    motor[ liftMotor ] = 0;
  } else if ( nMotorEncoder[ liftMotor ] < 0 )
  {
    while ( ( nMotorEncoder[ liftMotor ] - tempEncoderValue ) > encoderValue )
    {
      motor[ liftMotor ] = speed;
    }

    motor[ liftMotor ] = 0;
  }
  Wait1MSec(10);
}

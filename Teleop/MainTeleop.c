//Add config variables here

#define FIRST_LIFT_POSITION 100 //Add value here
#define SECOND_LIFT_POSITION 200 //Add value here
#define THIRD_LIFT_POSITION 300 //Add value here
#define FOURTH_LIFT_POSITION 400 //Add value here
#define ZERO_LIFT_POSITION 0 //Add value here

#define GOAL_HOLDER_ACTIVE 100 //Add encoder value here
#define GOAL_HOLDER_INACTIVE 0 //Add encoder value here

/*

  Joystick 1 will move the robot's drive motors -> Aiden will be the driver
  Joystick 2 will move the robot's lift -> Vale will drive the lift and other manipulators

*/

#include "JoystickDriver.c";

void moveMotor( String motorName, int encoderValue, int speed );

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
    motor[ leftDriveMotor ]  = ( int ) pow( 0.000046 * joystick.joy1_y1, 3 );
    motor[ rightDriveMotor ] = ( int ) pow( 0.000046 * joystick.joy1_y2, 3 );
      
    //getjoysticksettings
    getJoystickSettings( joystick );
    
    //if joystick button ( button that will use tower lift to go up) is pressed
    if ( )
    {
      //move tower lift up to the next position
      switch ( liftPosition )
      {
        case 0:
          moveMotor( "liftMotor", FIRST_LIFT_POSITION, 60 );
          break;
        case 1:
          moveMotor( "liftMotor", SECOND_LIFT_POSITION, 60 );
          break;
        case 2:
          moveMotor( "liftMotor", THIRD_LIFT_POSITION, 60 );
          break;
        case 3:
          moveMotor( "liftMotor", FOURTH_LIFT_POSITION, 60 );
          break;
        case 4:
          break;
      }
    }
    
    //if joystick button ( button that will use tower lift to go down) is pressed
    else if ( )
    {
      //move tower lift down to the next position
      switch ( liftPosition )
      {
        case 0:
          break;
        case 1:
          moveMotor( "liftMotor", -1 * FIRST_LIFT_POSITION, -60 );
          break;
        case 2:
          moveMotor( "liftMotor", -1 * SECOND_LIFT_POSITION, -60 );
          break;
        case 3:
          moveMotor( "liftMotor", -1 * THIRD_LIFT_POSITION, -60 );
          break;
        case 4:
          moveMotor( "liftMotor", -1 * FOURTH_LIFT_POSITION, -60 );
          break;
      }
    }
      
    //if button ( button to lock rolling goal to robot ) is pressed
    if ( )
    {
      //lock goal to robot
    }
      
    //else if button ( button to release goal ) is pressed
    else if ( )
    {
      //release goal
    }
      
  } //end while loop
}

void moveMotor( String motorName, int encoderValue, int speed )
{
  int tempEncoderValue = nMotorEncoder[ motorName ];
  
  if ( nMotorEncoder[ motorName ] > 0 )
  {
    while ( ( nMotorEncoder[ motorName ] - tempEncoderValue ) < encoderValue )
    {
      motor[ motorName ] = speed;
    }
  
    motor[ motorName ] = 0;
  } else if ( nMotorEncoder[ motorName ] < 0 )
  {
    while ( ( nMotorEncoder[ motorName ] - tempEncoderValue ) > encoderValue )
    {
      motor[ motorName ] = speed;
    }
  
    motor[ motorName ] = 0;
  }
}

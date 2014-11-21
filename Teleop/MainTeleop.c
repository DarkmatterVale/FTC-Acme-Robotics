//Add config variables here

#define FIRST_LIFT_POSITION //Add encoder value here
#define SECOND_LIFT_POSITION //Add encoder value here
#define THIRD_LIFT_POSITION //Add encoder value here
#define FOURTH_LIFT_POSITION //Add encoder value here
#define ZERO_LIFT_POSITION //Add encoder value here

#define GOAL_HOLDER_ACTIVE //Add encoder value here
#define GOAL_HOLDER_INACTIVE //Add encoder value here

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
  
  //while loop ( forever ) or until program terminated
  while ( true )
  {
    //getjoysticksettings()
    getJoystickSettings( joystick );
    
    //set the drive motors
    motor[ leftDriveMotor ]  = ( int ) pow( 0.006 * joystick.joy1_y1, 2 ) - 1;
    motor[ rightDriveMotor ] = ( int ) pow( 0.006 * joystick.joy1_y2, 2 ) - 1;
      
    //getjoysticksettings
    getJoystickSettings( joystick );
    
    //if joystick button ( button that will use tower lift to go up) is pressed
    if ( )
    {
      //move tower lift up to the next position
    }
    
    //if joystick button ( button that will use tower lift to go down) is pressed
    else if ( )
    {
      //move tower lift down to the next position
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
  nMotorEncoder[ motorName ] = 0;
  
  while ( nMotorEncoder[ motorName ] < encoderValue )
  {
    motor[ motorName ] = speed;
  }
  
  motor[ motorName ] = 0;
}

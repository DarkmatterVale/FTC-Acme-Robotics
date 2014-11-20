//Add config variables here

/*

  Joystick 1 will move the robot's drive motors
  Joystick 2 will move the robot's lift

*/

#include "JoystickDriver.c";

task main()
{
  //while loop ( forever )
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
      //move tower lift up
    }
    
    //if joystick button ( button that will use tower lift to go down) is pressed
    else if ( )
    {
      //move tower lift down
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

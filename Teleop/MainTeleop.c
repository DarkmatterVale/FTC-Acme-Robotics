//Add config variables here

#include "JoystickDriver.c";

task main()
{
  //while loop ( forever )
  while ( true )
  {
    //getjoysticksettings()
    getJoystickSettings( joystick );
    
    motor[ leftDriveMotor ] = ( int ) pow( 0.006( joystick.joy1_y1 ), 2 ) - 1;
    motor[ rightDriveMotor ] = ( int ) pow( 0.006( joystick.joy1_y2 ), 2 ) - 1;
      
    //getjoysticksettings
    getJoystickSettings( joystick );
    
    //if joystick button ( button that will use tower lift ) is pressed
      //move tower lift upward
    //else if joystick button ( button to launch catapult ) is pressed
      //launch catapult
    //else if button ( button to lock rolling goal to robot ) is pressed
      //lock goal to robot
    //else if button ( button to release goal ) is pressed
      //release goal
      
  //end while loop
}

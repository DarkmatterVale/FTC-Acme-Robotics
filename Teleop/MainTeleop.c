//Add config variables here

#include "JoystickDriver.c";

task main()
{
  //while loop ( forever )
  while ( true )
  {
    //getjoysticksettings()
    getJoystickSettings( joystick );
    
    //if joystick controls ( y1 & y2 ) have high values
      //go forward at full power
    //else if joystick controls ( y1 & y2 ) do not have high values
      //go backward
      
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

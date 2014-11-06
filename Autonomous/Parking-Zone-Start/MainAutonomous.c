//File containing instructions for parking zone start

void seekIrBeacon()
{
  /*
  Rev 1.0
  Robot will successfully find IR beacon and drop ball in tube
  
  Inputs:
  	IR sensor
  Outputs:
  	leftRobotMotor
  	rightRobotMotor
  
  To Do:
  	Edit/Add to Inputs and Outputs
  
  Author(s):
  	Vale Tolpegin
  */
  
  
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

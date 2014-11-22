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

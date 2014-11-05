//Test to just prove communication between NXT and SMUX

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

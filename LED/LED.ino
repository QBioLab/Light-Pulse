/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  modified 2 Feb 2018
  by H.F.
  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT); // LED
  digitalWrite(2, LOW ); //Close LED
  pinMode(3, OUTPUT); // Camera
  digitalWrite(3, LOW); //Close Camera

  //capture the initation pictures
  digitalWrite(2, HIGH); // Open stimulate LED
  digitalWrite(3, HIGH); // Capture two times
  delay(250);
  digitalWrite(3, LOW);
  delay(250);
  digitalWrite(3, HIGH);
  delay(250);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(2, HIGH);   // Open LED
  delay(500);              // for 0.5s
  
  digitalWrite(2, LOW);    // Close LED
  delay(1500);             // break 1.5s
  digitalWrite(3, HIGH);   // Open Camera, capture
  delay(500);             // keep 0.5s
  digitalWrite(3, LOW);   // Close camera
  delay(1500);             // break 1.5 second  
  // FPS=0.25FPS
 
}

/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#define trigPin1 24
#define echoPin1 25

// Define variables:
long duration1;
int distance1;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 180;    // variable to store the servo position

void setup() {
  myservo.attach(22);  // attaches the servo on pin 9 to the servo object
    // Define inputs and outputs:
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
    //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
   digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);

  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculate the distance:
  distance1 = duration1 * 0.034 / 2;

  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  Serial.print("Distance1 = ");
  Serial.print(distance1);
  Serial.println(" cm");

  delay(50);
  for (pos = 0; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 120; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

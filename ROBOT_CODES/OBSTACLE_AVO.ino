\
/* Example code for HC-SR04 ultrasonic distance sensor with Arduino. No library required. More info: https://www.makerguides.com */

// Define Trig and Echo pin:
#define trigPin1 22
#define echoPin1 23
#define trigPin 9 
#define echoPin 10
int revleft4 = 5; //REVerse motion of Left motor
int fwdleft5 = 4; //ForWarD motion of Left motor
int revright6 = 7; //REVerse motion of Right motor
int fwdright7 = 6; //ForWarD motion of Right motor
int speed_value_revleft4; // value for motor speed
int speed_value_fwdleft5; // value for motor speed
int speed_value_revright6; // value for motor speed
int speed_value_fwdright7; // value for motor speed

// Define variables:
long duration1;
int distance1;
long duration;
int distance;

void setup() {
  // Define inputs and outputs:
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(revleft4, OUTPUT); // set Motor pins as output
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright7, OUTPUT);
  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
  u();
 u1();
 delay(400);
 if (distance > 19)
{
digitalWrite(fwdright7, HIGH); // move forward
digitalWrite(revright6, LOW);
digitalWrite(fwdleft5, HIGH);
digitalWrite(revleft4, LOW);
}
if (distance < 18)
{
digitalWrite(fwdright7, LOW); //Stop
digitalWrite(revright6, LOW);
digitalWrite(fwdleft5, LOW);
digitalWrite(revleft4, LOW);
delay(500);
digitalWrite(fwdright7, LOW); //movebackword
digitalWrite(revright6, HIGH);
digitalWrite(fwdleft5, LOW);
digitalWrite(revleft4, HIGH);
delay(500);
digitalWrite(fwdright7, LOW); //Stop
digitalWrite(revright6, LOW);
digitalWrite(fwdleft5, LOW);
digitalWrite(revleft4, LOW);
delay(100);
digitalWrite(fwdright7, HIGH);
digitalWrite(revright6, LOW);
digitalWrite(revleft4, HIGH);
digitalWrite(fwdleft5, LOW);
delay(500);
}
}
//control the speed 0- 255
//speed_value_revleft4 = 255; // full speed
//speed_value_fwdleft5 = 255; // full speed
//speed_value_revright6 = 255; // full speed
//speed_value_fwdright7 = 255;
void u(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  distance = duration * 0.034 / 2;

  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(50);
}
void u1(){
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
}

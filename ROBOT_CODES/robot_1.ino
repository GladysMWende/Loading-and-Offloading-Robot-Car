int trigPin = 9; // trig pin of HC-SR04
int echoPin = 10; // Echo pin of HC-SR04
int trigPin1 = 22; // trig pin of HC-SR04
int echoPin1 = 23; // Echo pin of HC-SR04
int revleft4 = 5; //REVerse motion of Left motor
int fwdleft5 = 4; //ForWarD motion of Left motor
int revright6 = 7; //REVerse motion of Right motor
int fwdright7 = 6; //ForWarD motion of Right motor
int speed_value_revleft4; // value for motor speed
int speed_value_fwdleft5; // value for motor speed
int speed_value_revright6; // value for motor speed
int speed_value_fwdright7; // value for motor speed
int A=13;

//int speedPin1=4;
//int speedPin2=5;
//int speedPin3=6;
//int speedPin4=7;

long duration1, distance1;
long duration, distance;
void setup() {
//delay(random(500,2000)); // delay for random time
Serial.begin(9600);
pinMode(revleft4, OUTPUT); // set Motor pins as output
pinMode(fwdleft5, OUTPUT);
pinMode(A, OUTPUT);
pinMode(revright6, OUTPUT);
pinMode(fwdright7, OUTPUT);
pinMode(trigPin, OUTPUT); // set trig pin as output
pinMode(echoPin, INPUT); //set echo pin as input to capture reflected waves
pinMode(trigPin1, OUTPUT); // set trig pin as output
pinMode(echoPin1, INPUT); //set echo pin as input to capture reflected waves
delay(1000);
}
void loop() {


ultrasonic1();
ultrasonic2();
Serial.print("distance"); 
Serial.println(distance); 
Serial.print("distance1"); 
Serial.println(distance1); 
delay(500);
 //If you dont get proper movements of your robot then alter the pin numbers
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
//control the speed 0- 255
speed_value_revleft4 = 255; // full speed
speed_value_fwdleft5 = 255; // full speed
speed_value_revright6 = 255; // full speed
speed_value_fwdright7 = 255;
//digitalWrite(speedPin1, speed_value_revleft4); // output speed as
////PWM value
//digitalWrite(speedPin2, speed_value_fwdleft5);
//digitalWrite(speedPin3, speed_value_revright6); // output speed as
////PWM value
//digitalWrite(speedPin4, speed_value_fwdright7);
}
void ultrasonic1(){
  delay(10);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH); // send waves for 10 us
delayMicroseconds(10);
duration = pulseIn(echoPin, HIGH); // receive reflected waves
distance = duration / 58.2; // convert to distance
}
void ultrasonic2(){
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
//  Serial.print("Distance = ");
//  Serial.print(distance);
//  Serial.println(" cm");

  delay(50);
}
//My samples codes kindly go through them and test each code kindly try it out
//#include <NewPing.h> //Ultrasonic sensor function library. You must install this library
////our L298N control pins
//const int LeftMotorForward = 7;
//const int LeftMotorBackward = 6;
//const int RightMotorForward = 4;
//const int RightMotorBackward = 5;
////sensor pins
//#define trig_pin A1 //analog input 1
//#define echo_pin A2 //analog input 2
//#define maximum_distance 200
//boolean goesForward = false;
//int distance = 100;
//NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
//void setup(){
//pinMode(RightMotorForward, OUTPUT);
//pinMode(LeftMotorForward, OUTPUT);
//pinMode(LeftMotorBackward, OUTPUT);
//pinMode(RightMotorBackward, OUTPUT);
//void loop();
//{
//distance = readPing();
//delay(10);
//int distanceRight = 0;
//int distanceLeft = 0;
//delay(10);
//if (distance <= 20){
//moveStop();
//delay(300);
//moveBackward();
//delay(400);
//moveStop();
//delay(300);
//distanceRight = lookRight();
//delay(300);
//distanceLeft = lookLeft();
//delay(300);
//if (distanceRight >= distanceLeft){
//turnRight();
//moveStop();
//}
//else{
//turnLeft();
//moveStop();
//}
//}
//else{
//moveForward();
//}
//distance = readPing();
//}
//int lookRight();
//{
//int distance = readPing();
//delay(100);
//return distance;
//}
//int lookLeft();
//{
//delay(500);
//distance = readPing();
//delay(100);
//return distance;
//delay(100);
//}
//int readPing();
//{
//delay(70);
//int cm;
//cm = sonar.ping_cm();
//if (cm==0){
//cm=250;
//}
//return cm;
//}
//void moveStop();
//{
//digitalWrite(RightMotorForward, LOW);
//digitalWrite(LeftMotorForward, LOW);
//digitalWrite(RightMotorBackward, LOW);
//digitalWrite(LeftMotorBackward, LOW);
//}
//void moveForward();
//{
//if(!goesForward){
//goesForward=true;
//digitalWrite(LeftMotorForward, HIGH);
//digitalWrite(RightMotorForward, HIGH);
//digitalWrite(LeftMotorBackward, LOW);
//digitalWrite(RightMotorBackward, LOW);
//}
//}
//void moveBackward();
//{
//goesForward=false;
//digitalWrite(LeftMotorBackward, HIGH);
//digitalWrite(RightMotorBackward, HIGH);
//digitalWrite(LeftMotorForward, LOW);
//digitalWrite(RightMotorForward, LOW);
//}
//void turnRight();
//{
//digitalWrite(LeftMotorForward, HIGH);
//digitalWrite(RightMotorBackward, HIGH);
//digitalWrite(LeftMotorBackward, LOW);
//digitalWrite(RightMotorForward, LOW);
//delay(500);
//digitalWrite(LeftMotorForward, HIGH);
//digitalWrite(RightMotorForward, HIGH);
//digitalWrite(LeftMotorBackward, LOW);
//digitalWrite(RightMotorBackward, LOW);
//}
//void turnLeft();
//{
//digitalWrite(LeftMotorBackward, HIGH);
//digitalWrite(RightMotorForward, HIGH);
//digitalWrite(LeftMotorForward, LOW);
//digitalWrite(RightMotorBackward, LOW);
//delay(500);
//digitalWrite(LeftMotorForward, HIGH);
//digitalWrite(RightMotorForward, HIGH);
//digitalWrite(LeftMotorBackward, LOW);
//digitalWrite(RightMotorBackward, LOW);
//}

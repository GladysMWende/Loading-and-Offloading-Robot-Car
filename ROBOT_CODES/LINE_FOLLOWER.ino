
int trigPin = 9;      // trig pin of HC-SR04
int echoPin = 10;     // Echo pin of HC-SR04

int revleft4 = 4;       //REVerse motion of Left motor
int fwdleft5 = 5;       //ForWarD motion of Left motor
int revright6 = 6;      //REVerse motion of Right motor
int fwdright7 = 7;      //ForWarD motion of Right motor
int speed_value_revleft4; // value for motor speed
int speed_value_fwdleft5; // value for motor speed
int speed_value_revright6; // value for motor speed
int speed_value_fwdright7; // value for motor speed
int speedPin1=4;
int speedPin2=5;
int speedPin3=6;
int speedPin4=7;
long duration, distance;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(revleft4, OUTPUT);      // set Motor pins as output
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright7, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration / 58.2;   // convert to distance
  delay(10);
    // If you dont get proper movements of your robot then alter the pin numbers
  if (distance > 19)            
  {
    digitalWrite(fwdright7, HIGH);                    // move forward
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft4, LOW);                                                       
  }

  if (distance < 18)
  {
    digitalWrite(fwdright7, LOW);  //Stop                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);
    delay(500);
    digitalWrite(fwdright7, LOW);      //movebackword         
    digitalWrite(revright6, HIGH);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, HIGH);
    delay(500);
    digitalWrite(fwdright7, LOW);  //Stop                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);  
    delay(100);  
    digitalWrite(fwdright7, HIGH);       
    digitalWrite(revright6, LOW);   
    digitalWrite(revleft4, LOW);                                 
    digitalWrite(fwdleft5, LOW);  
    delay(500);
  }
  //control the speed 0- 255
speed_value_revleft4 = 255; // full speed
speed_value_fwdleft5 = 255; // full speed
speed_value_revright6 = 255; // full speed
speed_value_fwdright7 = 255;
 digitalWrite(speedPin1, speed_value_revleft4); // output speed as 
 //PWM value

digitalWrite(speedPin2, speed_value_fwdleft5);
 digitalWrite(speedPin3, speed_value_revright6); // output speed as 
 //PWM value

digitalWrite(speedPin4, speed_value_fwdright7);
}

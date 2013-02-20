
#include <Servo.h> 
 
#define SONAR_PIN 0
#define SERVO_PIN 9
#define SONAR_THRS 20

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position
int SonarSensor = 0;
 
void setup() 
{ 
  myservo.attach(SERVO_PIN);  // attaches the servo on pin 9 to the servo object 
    // initialize serial:
  Serial.begin(9600);
} 
 
 
void loop() 
{ 

    for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
    { // in steps of 1 degree 
      SonarSensor = analogRead(SONAR_PIN);
      Serial.println(SonarSensor); 
      if (SonarSensor > SONAR_THRS)
      {
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(30);                       // waits 15ms for the servo to reach the position 
      }
      else
      {
        pos -= 1;
      }
    } 
    for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
    {  
      SonarSensor = analogRead(SONAR_PIN);
      Serial.println(SonarSensor); 
      if (SonarSensor > SONAR_THRS)
      {      
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(30);                       // waits 15ms for the servo to reach the position 
      }
      else
      {
        pos += 1;
      }
    }

} 

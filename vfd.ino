#include <math.h>
float potvalue;
float i, j, f, no_of_divisions;
float tp, time_for_single_division, angle_step_rate;
const int sPWMpin1 = 10;
const int sPWMpin2 = 9;



void setup() {
  pinMode(sPWMpin1, OUTPUT);
  pinMode(sPWMpin2, OUTPUT);
  Serial.begin(9600);
}



void loop() {
  potvalue = analogRead(A0);
  float speedvalue = potvalue * (5.0 / 1023.0);
  if (speedvalue<=1.0)
  { f = 10;
  }
  else if (speedvalue<=2.0)
  {  f = 20;
  }
  else if (speedvalue<=3.0)
  { f = 25;
  }
  else if (speedvalue<=4.0)
  {  f = 40;
  }
  else if (speedvalue<=5.0)
  {  f = 50;
  }
  
   tp = 1000/f; // value in milli seconds
  
   no_of_divisions = 200;// for high resolution 200 and for low resolution 100
  
   time_for_single_division = tp*1000/no_of_divisions; // value in micro seconds
  
   angle_step_rate = 360/no_of_divisions; // to get sine fashioned delay time
  
  Serial.println(f);
  
  for (i=0; i< no_of_divisions/2; i++) // loop for pwm 1
  {
    
    float Ton1 = time_for_single_division * sin(angle_step_rate * i * 3.14/180); // to get sine fashioned delay time
    digitalWrite(sPWMpin1, HIGH);
  delay (Ton1);
    Serial.print(Ton1);
    Serial.print("\t");
    delay(300);
    digitalWrite(sPWMpin1, LOW);
  delay (time_for_single_division - Ton1);
    Serial.print(time_for_single_division - Ton1);
    Serial.print("\t");
    delay(300);
    Serial.println(i);
    
   }
 Serial.println ("end of pwm1");
  
    for (j=0; j< no_of_divisions/2; j++)
  {
    float Ton2 = time_for_single_division* sin(angle_step_rate * j * 3.14/180);
    digitalWrite(sPWMpin2, HIGH);
  delay (Ton2);
    Serial.print(Ton2);
    Serial.print("\t");
    delay(300);
    digitalWrite(sPWMpin2, LOW);
  delay (time_for_single_division - Ton2); 
    Serial.print(time_for_single_division - Ton2);
    Serial.print("\t");
    delay(300);
    Serial.println(j);
  }
 Serial.println ("end of pwm2");
}

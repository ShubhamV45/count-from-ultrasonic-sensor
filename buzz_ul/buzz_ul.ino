#include <LiquidCrystal.h>
int const trigPin = 11;
int const echoPin = 10;
int const buzzPin = 9;
int i=0;
int disp_pin[7];  /* array for a-g pins of 7-Segment display */

void define_segment_pins(int a, int b, int c, int d, int e, int f, int g) /* Assigns 7-segment display pins to board */
{  
  disp_pin[0] = a;
  disp_pin[1] = b;
  disp_pin[2] = c;
  disp_pin[3] = d;
  disp_pin[4] = e;
  disp_pin[5] = f;
  disp_pin[6] = g;
}

void display_number(int num)  /* Function to display number (0-9) */
{
  switch(num)
  {
    default:
    i=0;
    digitalWrite(disp_pin[0], HIGH);
    digitalWrite(disp_pin[1], HIGH); 
    digitalWrite(disp_pin[2], HIGH);
    digitalWrite(disp_pin[3], HIGH);
    digitalWrite(disp_pin[4], HIGH);
    digitalWrite(disp_pin[5], HIGH);
    digitalWrite(disp_pin[6], LOW); 
    break;
    case 1:
    digitalWrite(disp_pin[0], LOW); 
    digitalWrite(disp_pin[1], HIGH);
    digitalWrite(disp_pin[2], HIGH);
    digitalWrite(disp_pin[3], LOW);  
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], LOW);
    digitalWrite(disp_pin[6], LOW);
    break;
    case 2:
    digitalWrite(disp_pin[0], HIGH);
    digitalWrite(disp_pin[1], HIGH);
    digitalWrite(disp_pin[2], LOW);
    digitalWrite(disp_pin[3], HIGH);
    digitalWrite(disp_pin[4], HIGH);
    digitalWrite(disp_pin[5], LOW);
    digitalWrite(disp_pin[6], HIGH);
    break;
    case 3:
    digitalWrite(disp_pin[0], HIGH);
    digitalWrite(disp_pin[1], HIGH);
    digitalWrite(disp_pin[2], HIGH);
    digitalWrite(disp_pin[3], HIGH);
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], LOW);
    digitalWrite(disp_pin[6], HIGH);
    break;
    case 4:
    digitalWrite(disp_pin[0], LOW);
    digitalWrite(disp_pin[1], HIGH);
    digitalWrite(disp_pin[2], HIGH);
    digitalWrite(disp_pin[3], LOW);
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], HIGH);
    digitalWrite(disp_pin[6], HIGH);
    break;
    case 5:
    digitalWrite(disp_pin[0], HIGH);
    digitalWrite(disp_pin[1], LOW);
    digitalWrite(disp_pin[2], HIGH);
    digitalWrite(disp_pin[3], HIGH);
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], HIGH);
    digitalWrite(disp_pin[6], HIGH);
    break;
    case 6:
    digitalWrite(disp_pin[0], HIGH);
    digitalWrite(disp_pin[1], LOW);
    digitalWrite(disp_pin[2], HIGH);
    digitalWrite(disp_pin[3], HIGH);
    digitalWrite(disp_pin[4], HIGH);
    digitalWrite(disp_pin[5], HIGH);
    digitalWrite(disp_pin[6], HIGH);
    break;
    case 7:
    digitalWrite(disp_pin[0], HIGH);
    digitalWrite(disp_pin[1], HIGH);
    digitalWrite(disp_pin[2], HIGH);
    digitalWrite(disp_pin[3], LOW);
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], LOW);
    digitalWrite(disp_pin[6], LOW);
    break;
    case 8:
    digitalWrite(disp_pin[0], HIGH);
    digitalWrite(disp_pin[1], HIGH);
    digitalWrite(disp_pin[2], HIGH);
    digitalWrite(disp_pin[3], HIGH);
    digitalWrite(disp_pin[4], HIGH);
    digitalWrite(disp_pin[5], HIGH);
    digitalWrite(disp_pin[6], HIGH);
    break;
    case 9:
    digitalWrite(disp_pin[0], HIGH);
    digitalWrite(disp_pin[1], HIGH);
    digitalWrite(disp_pin[2], HIGH);
    digitalWrite(disp_pin[3], HIGH);
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], HIGH);
    digitalWrite(disp_pin[6], HIGH);
    break;
  }
}

void setup()
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzPin, OUTPUT); 
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  define_segment_pins(8,7,6,5,4,3,2);
}
void loop()
{
int duration, distance;
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
// Distance is half the duration devided by 29.1 as mentioned in datasheet(HCSR04)
distance = (duration/2) / 29.1;
if(distance <= 10 && distance >= 0){
++i;
digitalWrite(buzzPin, HIGH);
 display_number(i);
 here:delay(6);

} else {
// Don't buzz
digitalWrite(buzzPin, LOW);
}
// Waiting 60 ms won't hurt any one
delay(600);
}

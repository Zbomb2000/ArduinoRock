#include <hcsr04.h>

// This the first hcs module
#define ECHO_PIN_1 9
#define TRIG_PIN_1 10
HCSR04 hcsr04_1(TRIG_PIN_1, ECHO_PIN_1, 20, 4000);

// This is the secondary hcs module
#define ECHO_PIN_2 11
#define TRIG_PIN_2 12
HCSR04 hcsr04_2(TRIG_PIN_2, ECHO_PIN_2, 20, 4000);

// Defines pins
int sound_1 = 8;  // Sound pin 1
int sound_2 = 7;  // Sound pin 2
int sound_3 = 6;  // Sound pin 3
int range_light = 2;  // This light turns on if there is a person in range

// These are used to check the distance from the hcsr04 modules
int distance_1;
int distance_2;

// This is used to break loops
bool exit_value;

// Setup function
void setup() {
  // Sound pins
  pinMode(sound_1, OUTPUT);
  pinMode(sound_2, OUTPUT);
  pinMode(sound_3, OUTPUT);
  pinMode(range_light, OUTPUT);
  
  digitalWrite(sound_1, HIGH);
  digitalWrite(sound_2, HIGH);
  digitalWrite(sound_3, HIGH);

  // Serial monitor
  Serial.begin(9600);
  Serial.println(hcsr04_1.distanceInMillimeters());
}

// Loop
void loop() {
  // Prints distance
  printDistance();
  
  // Turns the range light off
  digitalWrite(range_light, LOW);

  // Loop while not in distance
  while (true) {
    // This checks the distance from the hcsr04 modules
    exit_value = distanceCompare(hcsr04_1.distanceInMillimeters(), hcsr04_2.distanceInMillimeters());
    if (exit_value == true) {
      break;
    }
    // Short delay to improve performance
    delay(50);
  }

  // Short delay to improve performance
  delay(50);
  
  // Turns the range light on
  digitalWrite(range_light, HIGH);
  
  while (true) {
    exit_value = distanceCompare();
    if (exit_value == false) {
      break;
    }
    // Short delay to improve performance
    delay(50);
  }
  Serial.println(hcsr04_1.distanceInMillimeters());
  digitalWrite(range_light, LOW);
}

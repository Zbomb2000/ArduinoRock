#include <hcsr04.h>

// This the first hcs module
#define ECHO_PIN_1 9
#define TRIG_PIN_1 10
HCSR04 hcsr04_1(TRIG_PIN_1, ECHO_PIN_1, 20, 4000);

// This is the secondary hcs module
#define ECHO_PIN_2 11
#define TRIG_PIN_2 12
HCSR04 hcsr04_2(TRIG_PIN_2, ECHO_PIN_2, 20, 4000);

// This function prints the distance from the hcsr04 modules
void printDistance() {
  // Prints current distance
  Serial.println("");
  Serial.println("Distance from hcsr04_1: ");
  Serial.print(hcsr04_1.distanceInMillimeters);
  Serial.println("Distance from hcsr04_2: ");
  Serial.print(hcsr04_2.distanceInMillimeters);
  Serial.println("");
}

// This function returns true if the distance on both modules is less than 750
bool distanceCompare(int dist1, int dist2) {
  // Creates bool variable
  bool returnBool = true;

  // Checks if an object is in range
  Serial.println("");
  if (dist1 > 750) {
    returnBool = false;
    Serial.println("Module 1 not in range");
  }
  if (dist2 > 750) {
    returnBool = false;
    Serial.println("Module 2 not in range");
  }
  Serial.println("");
  
  // Short delay
  delay(50);
  // Returns value
  return returnBool;
}

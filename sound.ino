// Function for sound 1
bool playSound1() {
  digitalWrite(sound_1, LOW);
  delay(2000);
  digitalWrite(sound_1, HIGH);
  delay(6500);
  // Gets distance in millimeters
  distance = hcsr04.distanceInMillimeters();
  if (distance < 750) {
    return true;
  }
  else {
    return false;
  }
}

// Function for sound 2
bool playSound2() {
  digitalWrite(sound_2, LOW);
  delay(2500);
  digitalWrite(sound_2, HIGH);
  delay(6000);
  // Gets distance in millimeters
  distance = hcsr04.distanceInMillimeters();
  if (distance < 750) {
    return true;
  }
  else {
    return false;
  }
}

// Function for sound 3
void playSound3() {
  digitalWrite(sound_3, LOW);
  delay(6750);
  digitalWrite(sound_3, HIGH);

  // Short delay
  delay(50);
}

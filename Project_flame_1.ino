const int flame = 27;    // Flame sensor connected to GPIO27 (digital pin)
const int relay = 18;    // Relay connected to GPIO18 (digital pin)

int val = 0;             // Variable to store the flame sensor value

void setup() {
  Serial.begin(115200);  // Start serial communication for debugging

  pinMode(relay, OUTPUT);
  pinMode(flame, INPUT);

  digitalWrite(relay, HIGH); //off
}

void loop() {
  // Read the digital value of the flame sensor
  val = digitalRead(flame);  // Use digitalRead() for digital sensor
  
  Serial.print("Sensor Value: ");
  Serial.println(val);  // Output the sensor value (HIGH or LOW)
  
  // Check if flame is detected (val will be HIGH or LOW)
  if (val == LOW) {  // If flame is detected (LOW indicates flame on most digital sensors)
    digitalWrite(relay, LOW); // Activate the relay (water pump)
    Serial.println("Flame Detected! Activating pump.");
  } else {
    digitalWrite(relay, HIGH);  // Deactivate the relay (water pump)
    Serial.println("No Flame Detected.");
  }

  delay(100);  // Wait 100ms before the next reading
}

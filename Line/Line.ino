// Pin definitions
const int sensorPin = 2;    // KY-033 sensor digital output pin
const int ledPin = 13;      // On-board LED for indicating sensor output

void setup() {
  // Set sensorPin as input and ledPin as output
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the sensor value (HIGH or LOW)
  int sensorValue = digitalRead(sensorPin);

  // If the sensor detects black (reflection is low), turn on the LED
  if (sensorValue == LOW) {
    digitalWrite(ledPin, HIGH);  // Turn on LED
    Serial.println("Black detected");
  } else {
    digitalWrite(ledPin, LOW);   // Turn off LED
    Serial.println("White detected");
  }

  delay(100);  // Small delay for stability
}

// Pin definitions
const int leftSensorPin = 2;    // KY-033 left sensor
const int rightSensorPin = 3;   // KY-033 right sensor
const int leftMotorPin1 = 8;    // Left motor control pins
const int leftMotorPin2 = 9;
const int rightMotorPin1 = 10;  // Right motor control pins
const int rightMotorPin2 = 11;

void setup() {
  // Set sensor pins as input
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  
  // Set motor pins as output
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
}

void loop() {
  // Read sensor values (LOW = black, HIGH = white)
  int leftSensorValue = digitalRead(leftSensorPin);
  int rightSensorValue = digitalRead(rightSensorPin);

  // If both sensors are on the line (black), move forward
  if (leftSensorValue == LOW && rightSensorValue == LOW) {
    moveForward();
  }
  // If the left sensor is off the line (white) and the right sensor is on the line (black), turn right
  else if (leftSensorValue == HIGH && rightSensorValue == LOW) {
    turnRight();
  }
  // If the right sensor is off the line (white) and the left sensor is on the line (black), turn left
  else if (leftSensorValue == LOW && rightSensorValue == HIGH) {
    turnLeft();
  }
  // If both sensors are off the line (white), stop
  else {
    stopMotors();
  }
}

// Function to move forward
void moveForward() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

// Function to turn right
void turnRight() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
}

// Function to turn left
void turnLeft() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

// Function to stop the motors
void stopMotors() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
}

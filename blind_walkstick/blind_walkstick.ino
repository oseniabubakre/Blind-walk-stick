// Blind Stick - Obstacle Detection using Ultrasonic Sensor

// Define pins
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 6;
//const int vibrationPin = 5; // optional

// Distance threshold in centimeters
const int distanceThreshold = 50;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  //pinMode(vibrationPin, OUTPUT);
  
  Serial.begin(9600); // for debugging
}

void loop() {
  long duration;
  int distance;

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the echo duration
  duration = pulseIn(echoPin, HIGH);

  // Convert duration to distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if object is within threshold
  if (distance > 0 && distance < distanceThreshold) {
    digitalWrite(buzzerPin, HIGH);
  //digitalWrite(vibrationPin, HIGH); // optional
  } else {
    digitalWrite(buzzerPin, LOW);
   //digitalWrite(vibrationPin, LOW); // optional
  }

  delay(200); // slight delay for stability
}

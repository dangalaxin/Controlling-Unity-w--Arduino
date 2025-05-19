#define trigPin 9
#define echoPin 10
#define LED_PIN 11

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Distance measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  Serial.println(distance); // Send to Unity
  delay(100);

  // Receive command from Unity
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');
    message.trim();

    if (message == "LED_ON") {
      digitalWrite(LED_PIN, HIGH);
    }
    else if (message == "LED_OFF") {
      digitalWrite(LED_PIN, LOW);
    }
  }
}

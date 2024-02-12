const int MOTION_PIN = 2;
const int LIGHT_PIN = 0;
const int LED_PIN = 7;
const int LIGHT_THRESHOLD = 50; // Original: 15

int motion_state_old = LOW;
int motion_state_new = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(MOTION_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Program Started...");
}

void loop() {
  int light_level = analogRead(LIGHT_PIN);
  if (light_level <= LIGHT_THRESHOLD) {
    motion_state_old = motion_state_new;
    motion_state_new = digitalRead(MOTION_PIN);

    if (motion_state_old == LOW && motion_state_new == HIGH) {
      Serial.println("Motion found");
      Serial.print("light level = ");
      Serial.println(light_level);
      // turn LED on
      digitalWrite(LED_PIN, HIGH);
    } else if (motion_state_old == HIGH && motion_state_new == LOW) {
      Serial.print("light level = ");
      Serial.println(light_level);
      Serial.println("Motion stopped");
      // turn LED off
      digitalWrite(LED_PIN, LOW);
    }
  }

}

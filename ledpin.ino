#define LED_1_PIN 11 // led 1 to pin 11
#define LED_2_PIN 10 // led 2 to pin 10
#define LED_3_PIN 9 // led 3 to pin 9
#define BUTTON_PIN 4 // button to pin 4

void setup() // sets mode for pins
{
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // push button
}

void loop()
{
  byte buttonState = digitalRead(BUTTON_PIN); // "HIGH" means release, "LOW" means pressed
  
  if (buttonState == LOW) { // when button is pressed, led lights power on
    digitalWrite(LED_1_PIN, HIGH);
    digitalWrite(LED_2_PIN, HIGH);
    digitalWrite(LED_3_PIN, HIGH);
  }
  else { // when button is released or not pressed, led lights power off
    digitalWrite(LED_1_PIN, LOW);
    digitalWrite(LED_2_PIN, LOW);
    digitalWrite(LED_3_PIN, LOW);
  }
}

#define LED_1_PIN 11
#define LED_2_PIN 10
#define LED_3_PIN 9
#define BUTTON_PIN 4

#define LED_NUMBER 3

byte LEDPinArray[LED_NUMBER] = { LED_1_PIN,
                                 LED_2_PIN,
                                 LED_3_PIN };

unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonStateChanged = 0;

byte lastButtonState = HIGH;

int LEDIndex = 0;

void initAllLEDs()
{
  for (int i = 0; i < LED_NUMBER; i++) {
    pinMode(LEDPinArray[i], OUTPUT);
  }
}

void powerOnSelectedLEDOnly(int index)
{
  for (int i = 0; i < LED_NUMBER; i++) {
    if (i == index) {
      digitalWrite(LEDPinArray[i], HIGH);
    }
    else {
      digitalWrite(LEDPinArray[i], LOW);
    }
  }
}

void setup()
{
  initAllLEDs();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(LEDPinArray[LEDIndex], HIGH);
}

void loop()
{
  unsigned long timeNow = millis();
  if (timeNow - lastTimeButtonStateChanged > debounceDuration) {
      byte buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != lastButtonState) {
      lastTimeButtonStateChanged = timeNow;
      lastButtonState = buttonState;
      if (buttonState == HIGH) { // button has been released
        LEDIndex++;
        if (LEDIndex >= LED_NUMBER) {
          LEDIndex = 0;
        }
        powerOnSelectedLEDOnly(LEDIndex);
      }
    }
  }
}

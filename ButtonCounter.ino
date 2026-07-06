/*
  Button Press Counter
  Counts the number of button presses using software debouncing.
*/

const int buttonPin = 2;

int buttonState = HIGH;
int lastButtonState = HIGH;
int pressCount = 0;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);

  Serial.println("===== Button Press Counter =====");
  Serial.println("Press the button...");
}

void loop() {

  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        pressCount++;

        Serial.print("Button Press Count: ");
        Serial.println(pressCount);
      }
    }
  }

  lastButtonState = reading;
}

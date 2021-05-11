const int buttonPin = 7;    // the number of the pushbutton pin
const int ledPin = 5;      // the number of the LED pin
const int ledPin1 = 4;
const int ledPin2 = 3;

// Variables will change:
int ledState = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
bool REALLY = false;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
  digitalWrite(ledPin1, ledState);
  digitalWrite(ledPin2, ledState);
}
void lightUp()
{
  digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
    delay(50);
    digitalWrite(ledPin1, HIGH);
    delay(50);
    digitalWrite(ledPin1, LOW);
    delay(50);
    digitalWrite(ledPin2, HIGH);
    delay(50);
    digitalWrite(ledPin2, LOW);
    delay(50);
}

void loop() {
  // read the state of the switch into a local variable:
  if(REALLY)
  {
    lightUp();
  }
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        Serial.println("AAA");
        REALLY = !REALLY;
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}
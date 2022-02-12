const int LED = 9;
const int BUTTON = 2;

bool lastButtonValue = LOW;
bool currentButtonValue = LOW;
bool ledOn = false;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

bool debounce(boolean lastValue) {
  bool currentValue = digitalRead(BUTTON);

  if (lastValue != currentValue) {
    delay(10);
    currentValue = digitalRead(BUTTON);
    return currentValue;
  }
}

void loop() {
  currentButtonValue = debounce(lastButtonValue);

  if (lastButtonValue == LOW && currentButtonValue == HIGH)
    ledOn = !ledOn;

  lastButtonValue = currentButtonValue;
  
  digitalWrite(LED, ledOn);
}

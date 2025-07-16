const int buttonPin = 2;
const int tempPin = A0;

int count = 0;
bool lastButtonState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.println("System Initialized");
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  // Detect button press (rising edge)
  if (buttonState == HIGH && lastButtonState == LOW) {
    count++;
    delay(200);  // Debounce
  }
  lastButtonState = buttonState;

  // Read LM35 sensor
  int reading = analogRead(tempPin);
  float voltage = reading * (5.0 / 1023.0);
  float temperatureC = voltage * 100.0;

  // Print to Serial Monitor
  Serial.print("Button Count: ");
  Serial.print(count);
  Serial.print(" | Temp: ");
  Serial.print(temperatureC, 1);  // One decimal place
  Serial.println(" C");

  delay(1000); // 1 second delay
}

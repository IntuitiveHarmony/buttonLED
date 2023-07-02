const int buttonPin = A0;     // Analog pin for the button
const int segmentA = 2;       // Pin for Each segment of the 7 LED
const int segmentB = 3;
const int segmentC = 4;
const int segmentD = 5;
const int segmentE = 6;
const int segmentF = 7;
const int segmentG = 8;
const int segmentDP = 13;       // Pin for the built-in LED

int number = 0;              // Number to be incremented

int buttonState = 0;         // Current state of the button
int lastButtonState = 0;     // Previous state of the button

void setup() {
  pinMode(segmentDP, OUTPUT);      // Set the LED pin as an output
  pinMode(buttonPin, INPUT);    // Set the button pin as an input
  digitalWrite(buttonPin, HIGH); // Enable the internal pull-up resistor for the button pin
  Serial.begin(9600);           // Initialize serial communication (optional)
  pinMode(2, OUTPUT);
}

void loop() {
  buttonState = analogRead(buttonPin);  // Read the current state of the button

  // Check if the button is pressed (threshold below a certain value)
  if (buttonState < 500 && lastButtonState >= 500) {
    number++;                             // Increment the number
    Serial.print("Number: ");              // Print the number (optional)
    Serial.println(number);
    digitalWrite(segmentDP, HIGH);            // Turn on the LED
    delay(200);                            // Debounce delay to avoid multiple increments on a single button press
  }
  
  // Update the last button state
  lastButtonState = buttonState;

  // Turn off the LED if the button is not pressed
  if (buttonState >= 500) {
    digitalWrite(segmentDP, LOW);
  }
  if (number > 0) {
    digitalWrite(2, HIGH);
  }

}

const int buttonPin = A0;     // Analog pin for the button
const int segA = 2;       // Pin for Each seg of the 7 LED
const int segB = 3;
const int segC = 4;
const int segD = 5;
const int segE = 6;
const int segF = 7;
const int segG = 8;
const int segDP = 13;       // Pin for the built-in LED

int number = 0;              // Number to be incremented

int buttonState = 0;         // Current state of the button
int lastButtonState = 0;     // Previous state of the button

void setup() {
  pinMode(buttonPin, INPUT);    // Set the button pin as an input
  digitalWrite(buttonPin, HIGH); // Enable the internal pull-up resistor for the button pin
  Serial.begin(9600);           // Initialize serial communication (optional)
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDP, OUTPUT);      // Set the LED pin as an output
}

void loop() {
  buttonState = analogRead(buttonPin);  // Read the current state of the button

  // Check if the button is pressed (threshold below a certain value)
  if (buttonState < 500 && lastButtonState >= 500) {
    if (number == 9) {                  // count 0 - 9
      number = 0;
    } else {
      number++;                             // Increment the number
    }
    Serial.print("Number: ");              // Print the number (optional)
    Serial.println(number);
    digitalWrite(segDP, HIGH);            // Turn on the LED
    delay(200);                            // Debounce delay to avoid multiple increments on a single button press
  }
  
  // Update the last button state
  lastButtonState = buttonState;

  // Turn off the LED if the button is not pressed
  if (buttonState >= 500) {
    digitalWrite(segDP, LOW);
  }

  // Display the corresponding number on the 7-segment display
  digitalWrite(segA, number == 0 || number == 2 || number == 3 || number == 5 || number == 6 || number == 7 || number == 8 || number == 9);
  digitalWrite(segB, number == 0 || number == 1 || number == 2 || number == 3 || number == 4 || number == 7 || number == 8 || number == 9);
  digitalWrite(segC, number == 0 || number == 1 || number == 3 || number == 4 || number == 5 || number == 6 || number == 7 || number == 8 || number == 9);
  digitalWrite(segD, number == 0 || number == 2 || number == 3 || number == 5 || number == 6 || number == 8 || number == 9);
  digitalWrite(segE, number == 0 || number == 2 || number == 6 || number == 8);
  digitalWrite(segF, number == 0 || number == 4 || number == 5 || number == 6 || number == 8 || number == 9);
  digitalWrite(segG, number == 2 || number == 3 || number == 4 || number == 5 || number == 6 || number == 8 || number == 9);

}





















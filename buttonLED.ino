const int buttonPin = A0;               // Analog pin for the increment button
const int randomButtonPin = A1;         // Analog pin for the random button
const int segA = 2;                     // Pin for Each segment of the 7 LED
const int segB = 3;
const int segC = 4;
const int segD = 5;
const int segE = 6;
const int segF = 7;
const int segG = 8;
const int segDP = 13;                   // Pin for the built-in LED and the decimal 

int number = 0;                         // Number to be displayed

int buttonState = 0;                    // Current state of the increment button
int lastButtonState = 0;                // Previous state of the increment button

int randomButtonState = 0;              // Current state of the random button
int lastRandomButtonState = 0;          // Previous state of random button

void writeNumber() {
  // Display the corresponding number on the 7-segment display
  digitalWrite(segA, number == 0 || number == 2 || number == 3 || number == 5 || number == 6 || number == 7 || number == 8 || number == 9);
  digitalWrite(segB, number == 0 || number == 1 || number == 2 || number == 3 || number == 4 || number == 7 || number == 8 || number == 9);
  digitalWrite(segC, number == 0 || number == 1 || number == 3 || number == 4 || number == 5 || number == 6 || number == 7 || number == 8 || number == 9);
  digitalWrite(segD, number == 0 || number == 2 || number == 3 || number == 5 || number == 6 || number == 8 || number == 9);
  digitalWrite(segE, number == 0 || number == 2 || number == 6 || number == 8);
  digitalWrite(segF, number == 0 || number == 4 || number == 5 || number == 6 || number == 8 || number == 9);
  digitalWrite(segG, number == 2 || number == 3 || number == 4 || number == 5 || number == 6 || number == 8 || number == 9);
}

void setup() {
  pinMode(buttonPin, INPUT);            // Set the increment pin as an input
  digitalWrite(buttonPin, true);        // Enable the internal pull-up resistor for the pin
  pinMode(randomButtonPin, INPUT);      // Set the random pin as an input
  digitalWrite(randomButtonPin, true);  // Enable the internal pull-up resistor for the pin
  Serial.begin(9600);                   // Initialize serial communication (optional)
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDP, OUTPUT);               // Set the LED pin as an output
}

void loop() {
  unsigned long currentTime = millis();


  buttonState = analogRead(buttonPin);  // Read the current state of the button
  randomButtonState = analogRead(randomButtonPin);

  // Check if the button is pressed (threshold below a certain value)
  if (buttonState < 500 && lastButtonState >= 500) {
    if (number == 9) {                  // count 0 - 9
      number = 0;
    } else {
      number++;                         // Increment the number
    }
    Serial.print("Number: ");           // Print the number
    Serial.println(number);
    digitalWrite(segDP, true);          // Turn on the LED
    delay(200);                         // Debounce delay to avoid multiple increments on a single button press
  }

  // Button 2 - random number
  if (randomButtonState < 500 && lastRandomButtonState >= 500) {
    // Flash a bunch of random numbers and the DP first
    for (int i = 0; i < 7; i++) {
      digitalWrite(segDP, true);        // Turn on the LED
      delay(50);
      number = random(0, 9);
      writeNumber();
      digitalWrite(segDP, false);       // Turn off the LED
      delay(50);
      number = random(0, 9);
      writeNumber();
    }
    Serial.print("Random number: ");
    Serial.println(number);
    delay(200);                         // Debounce delay to avoid multiple increments on a single button press
  }

  // Update the last button state
  lastButtonState = buttonState;
  lastRandomButtonState = randomButtonState;

  // Turn off the LED if the button is not pressed
  if (buttonState >= 500) {
    digitalWrite(segDP, false);
  }

  writeNumber();
}





















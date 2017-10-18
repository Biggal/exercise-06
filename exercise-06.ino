const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int major = 1;
const int minor = 0;
const int build = 3;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {

  Serial.begin(115200);
  while (!Serial) {
    
  }
  delay(2000);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  Serial.println(">> OPTIONS:");
  Serial.println("");
  Serial.println("1 - HELP");
  Serial.println("2 - SEE FIRMWARE VERSION");
}
 
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  if (Serial.available()) {
    char c = Serial.read();
    if(c == '1') {
      Serial.println("");
      Serial.println("---------------------------------------------");
      Serial.println("HELP");
      Serial.println("");
      Serial.println("1. Blink led (frequency: 700 ms)");
      Serial.println("2. Press button to enable blink led.");
      Serial.println(">> Send 0 to go back to OPTIONS.");
      Serial.println("---------------------------------------------");
    }
    if(c == '2') {
      Serial.println("");
      Serial.println("Version: 1.0.13");
      Serial.println(">> Send 0 to go back to OPTIONS.");
    }
    if(c == '0') {
      Serial.println("");
      Serial.println(">> OPTIONS:");
      Serial.println("");
      Serial.println("1 - HELP");
      Serial.println("2 - SEE FIRMWARE VERSION");
    }
    
  }  
 
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(700);              // wait for a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(700);              // wait for a second
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}

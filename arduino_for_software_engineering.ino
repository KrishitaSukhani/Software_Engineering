// Declaring Pins
const int buzzerPin = 5;
const int ledPin = 6;
const int motionPin = 7;
const int buttonPin = 12;

// Setting Buzzer mode to False
boolean buzzer_mode = false;

// For LED
int ledState = HIGH;
long previousMillis = 2; 
long interval = 5000;  // Interval at which LED blinks

void setup()
{
  Serial.begin(9600);
  //The Following are our output
  pinMode(ledPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);

  //Button is our Input
  pinMode(buttonPin, INPUT);
  pinMode(motionPin, INPUT);
  
  // Wait before starting the alarm
//  delay(5000);
}

void loop()
{
  // To chech whether the motion is detected or not
  int motion = digitalRead(motionPin);
  if (motion) {
    buzzer_mode = true;
  }

  // If our button is pressed Switch off ringing and Setup
  int button_state = digitalRead(buttonPin);
  if (button_state) {
    buzzer_mode = false;
  }

  // If alarm mode is on,blink our LED
  if (buzzer_mode){
    tone(buzzerPin,2);
    digitalWrite(ledPin, HIGH);
  } else {
    // No tone & LED off
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
  }
}

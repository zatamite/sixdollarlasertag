/* TinyTone for ATtiny85 */

// Notes
const int Note_C  = 239;
const int Note_CS = 225;
const int Note_D  = 213;
const int Note_DS = 201;
const int Note_E  = 190;
const int Note_F  = 179;
const int Note_FS = 169;
const int Note_G  = 159;
const int Note_GS = 150;
const int Note_A  = 142;
const int Note_AS = 134;
const int Note_B  = 127;
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  3;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int Speaker = 1;
void setup()
{
  pinMode(Speaker, OUTPUT);
  pinMode(buttonPin, INPUT);  
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH); 
    playTune();
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
}


void TinyTone(unsigned char divisor, unsigned char octave, unsigned long duration)
{
  TCCR1 = 0x90 | (8-octave); // for 1MHz clock
  // TCCR1 = 0x90 | (11-octave); // for 8MHz clock
  OCR1C = divisor-1;         // set the OCR
  delay(duration);
  TCCR1 = 0x90;              // stop the counter
}

// Play laser sound
void playTune(void)
{
  for (int thisPin = 0; thisPin < 30; thisPin = thisPin + 5) { 
    int t = random(20);
    TinyTone(Note_C + thisPin - t, 1, 10);
    TinyTone(Note_D + thisPin - t, 3, 10);
    TinyTone(Note_E + thisPin - t, 4, 10);
    TinyTone(Note_C + thisPin -t, 1, 10);
  }
}

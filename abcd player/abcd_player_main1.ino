//pin where signal is received from arduino 2
const int signalToPlay = A0; 

//melody
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440

const unsigned int playRepeat = 3; //set to whole number greater than 1
const int buzzer = 5;

int abcd_melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

int noteType[] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 2, 4, 4, 2,
  4, 4, 2, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2
};

int lengthOfMelody = sizeof(abcd_melody) / sizeof(abcd_melody[0]);

//leds
const int ledPins[] = {13, 12, 11, 10, 9, 8, 7, 6};
const int ledCount = 8;

//do not change as this effects the light animation
const int animation[] = {0, 1, 2, 3, 4, 5, 7, 6, 5, 4, 3, 2};


//-------------------------- VOID SETUP ---------------------
void setup() {
  Serial.begin(9600);
  //pin mode leds
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  //pin mode buzzer
  pinMode(buzzer, OUTPUT);

  //signal
  pinMode(signalToPlay, INPUT);
}
//-------------------------- END OF VOID SETUP ---------------------

//-------------------------- VOID LOOP ---------------------
void loop() {
  //if this receives high meaning Time is 07:00 AM
  int flag = digitalRead(signalToPlay);

  if (flag) {
    //melody and led light loop
    int iterationCount = 0;
    for (int j = 0; j < playRepeat; j++) {
      for (int i = 0; i < lengthOfMelody; i++) {
        if (iterationCount == 12) {
          iterationCount = 0;
        }
        if (iterationCount <= 5) {
          digitalWrite(ledPins[animation[iterationCount]], HIGH);
          digitalWrite(ledPins[animation[iterationCount] + 2], HIGH);
          delay(100);
          digitalWrite(ledPins[animation[iterationCount]], LOW);
          digitalWrite(ledPins[animation[iterationCount] + 2], LOW);
        } else {
          digitalWrite(ledPins[animation[iterationCount]], HIGH);
          digitalWrite(ledPins[animation[iterationCount] - 2], HIGH);
          delay(100);
          digitalWrite(ledPins[animation[iterationCount]], LOW);
          digitalWrite(ledPins[animation[iterationCount] - 2], LOW);
        }
        iterationCount++;
        playNote(i);
      }
    }
  }
}
//-------------------------- END OF VOID LOOP ---------------------

//play note function
void playNote(int noteIndex) {
  int noteDuration = 1000 / noteType[noteIndex];
  tone(buzzer, abcd_melody[noteIndex], noteDuration);
  int pause = noteDuration;
  delay(pause);
  noTone(buzzer);
}
/*
zenzen 4/30/21
*/

//orange wire
#define POTENT_PIN A0 
//red wire
#define VCC_PIN 12 
//green wire
#define BLINK_LED_PIN 13 

//violet wires
int rollLedPins[] = {
  11,10,9,8,7,6,5,4,3,2
};

int sizeOfLedArray = sizeof(rollLedPins)/sizeof(rollLedPins[0]);

//we will implement delay
//without actually using a delay funtion 
//so we wont interrupt the other rolling leds
unsigned long previousMillis = 0;
int blinkLedState = LOW;

void setup(){
  //PIN SETUPS
  for(int i = 0; i < sizeOfLedArray; i++){
    pinMode(rollLedPins[i], OUTPUT);
  }
  pinMode(VCC_PIN, OUTPUT);
  digitalWrite(VCC_PIN, HIGH); //making pin 12 as VCC pin
  pinMode(BLINK_LED_PIN, OUTPUT);
  digitalWrite(BLINK_LED_PIN, blinkLedState);
}

void loop(){
  int potentReading = analogRead(POTENT_PIN);
  //map(value_to_map, sensor_lowest_reading, sensor_highest_reading, your_desired_lowest, your_desired_highest)
  //10 highest because we have 10 leds - counting from 0 index let 0 be off all leds
  int rollValue = map(potentReading, 0, 1023, 0, 10); 
  
  //1000 milliseconds lowest so slow blink when pot is low
  //100 milliseconds delay highest so fast blink when pot is high
  int blinkRate = map(potentReading, 0, 1023, 500, 50); 
  
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= blinkRate){
    previousMillis = currentMillis;
    if(blinkLedState == LOW) blinkLedState = HIGH;
    else blinkLedState = LOW;
  }
  
  //updating blink state
  digitalWrite(BLINK_LED_PIN, blinkLedState);
  
  //ROLLING LED
  if(rollValue > 0){
    for(int i = 0; i < sizeOfLedArray; i++){
      if(i < rollValue) digitalWrite(rollLedPins[i], HIGH); 
      else digitalWrite(rollLedPins[i], LOW);
  	}
  } else digitalWrite(rollLedPins[0], LOW);
}

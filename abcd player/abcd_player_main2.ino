#include <LiquidCrystal.h>

const int signalPin = 3;
bool flag = false;

int hoursTens = 0;
int hourUnit = 6; //change this to offset time
int minuteTens = 0;
int minuteUnit = 0;

String hourTime = "";
String minuteTime = "";

//7 segment data
int seven_seconds[][8] = {
  {0, 0, 0},
  {0, 0, 1},
  {0, 1, 0},
  {0, 1, 1},
  {1, 0, 0},
  {1, 0, 1},
  {1, 1, 0},
  {1, 1, 1}
};

//cd4511 pins
int bcd_pins[] = {11, 10, 9};

LiquidCrystal lcd(12, 13, 4, 5, 6, 7);

//-------------------------- VOID SETUP ---------------------
void setup()
{
   //CD4511 pins
  for (int i = 0; i < 3; i++) {
    pinMode(bcd_pins[i], OUTPUT);
  }
  
  //signal arduino 1 to play sound
  pinMode(signalPin, OUTPUT);
  digitalWrite(signalPin, LOW);

  lcd.begin(16, 2);
  showCurrentTime();
  
  countDown(5);
}
//-------------------------- END OF VOID SETUP ---------------------

//-------------------------- VOID LOOP ---------------------
void loop()
{
  while (!flag) {
    int incrememt = minuteCounter();
    if (incrememt == 1) {
      hourCounter();
    }
    showCurrentTime();
    //adjust delay value to speed up or slow down clock
    //higher delay slower clock
    //lower delay faster clock
    //recommended: keep it lower as simulation is limited
    // but not to low as it can also slow down simulation
    delay(100); 
  }
}
//-------------------------- END OF VOID LOOP ---------------------

void showCurrentTime() {
  lcd.home();
  lcd.print("Time: ");
  String hourTime = String(hoursTens) + String(hourUnit);
  String minuteTime = String(minuteTens) + String(minuteUnit);
  String time = hourTime + ":" + minuteTime;
  lcd.print(time);
  
  int hour = getTimeToInt(hourTime);
  
  if(hour >= 0 && hour <= 11){
    lcd.print(" AM");
  } else {
    lcd.print(" PM");
  }
  
  if(is7AM(hourTime, minuteTime)) 
    digitalWrite(signalPin, HIGH);
  else digitalWrite(signalPin, LOW);
}

//convert string time to int time
int getTimeToInt(String time){
  return time.toInt();
}

//check if 7 am
boolean is7AM(String hour, String minute){
  return (getTimeToInt(hour) == 7 && getTimeToInt(minute) == 0);
}
      
//minute counter
int minuteCounter() {
  int pulse_hour = 0;
  if (minuteUnit == 9) {
    if (minuteTens == 5) {
      pulse_hour = 1;
      minuteUnit = 0;
      minuteTens = 0;
    } else {
      minuteUnit = 0;
      minuteTens += 1;
    }
  } else {
    minuteUnit += 1;
  }
  return pulse_hour;
}

//hour counter
void hourCounter() {
  if (hoursTens == 2 && hourUnit == 3) {
    hourUnit = 0;
    hoursTens = 0;
  } else if (hourUnit == 9) {
    hourUnit = 0;
    hoursTens += 1;
  } else {
    hourUnit += 1;
  }
}

//7 segment countdown
void countDown(int start) {
  for (int i = start; i >= 0; i--) {
    writeToBCD(seven_seconds[i]);
    delay(500);
  }
}

void writeToBCD(int four_bit_data[]) {
  for (int i = 0; i < 3; i++)
    digitalWrite(bcd_pins[i], four_bit_data[i]);
}

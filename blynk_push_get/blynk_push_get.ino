//#define BLYNK_PRINT Serial
#define ledPin 2
#define pushBtnPin 4

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define mainVPin V5

int ledStatus = LOW;
int btnState;
int lastBtnState = LOW;

WidgetLED ledIndicator(V1);

unsigned long lastClickTime = 0;
unsigned long delayClicks = 200UL;


char auth[] = "0A-Hdrnt5Jxr9BrJCNTNjrWydurINH-X";
char ssid[] = "HUAWEI-2.4G-H7Nu";
char pass[] = "j4GSPGsf"; // Set password to "" for open networks.

//http://blynk-cloud.com/0A-Hdrnt5Jxr9BrJCNTNjrWydurINH-X/update/V5?value=0
//http://blynk-cloud.com/0A-Hdrnt5Jxr9BrJCNTNjrWydurINH-X/update/V5?value=1

//http://blynk-cloud.com/0A-Hdrnt5Jxr9BrJCNTNjrWydurINH-X/get/V5

BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  // Setup a function to be called every second
  timer.setInterval(1000L, sendDataEvent);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledStatus);

  pinMode(pushBtnPin, INPUT);

}

void loop() {
  checkButton(digitalRead(pushBtnPin));
  
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
  
}

void checkStatus(){
  if(ledStatus) ledIndicator.on();
  else ledIndicator.off();
}

void checkButton(int reading){

  if ((millis() - lastClickTime) > delayClicks) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != btnState) {
      btnState = reading;

      // only toggle the LED if the new button state is HIGH
      if (btnState == HIGH) {
        ledStatus = !ledStatus;
        checkStatus();
      }
    }
  }
  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastBtnState = reading;
}

//send Data to Blynk App
void sendDataEvent(){
  Serial.println(ledStatus);
  Blynk.virtualWrite(mainVPin, ledStatus);
  digitalWrite(ledPin, ledStatus);
}

//read data from blynk app
BLYNK_WRITE(mainVPin){
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  ledStatus = param.asInt(); // assigning incoming value from pin V5 to a variable
  checkStatus();
  Serial.println(ledStatus);
  digitalWrite(ledPin, ledStatus);
}

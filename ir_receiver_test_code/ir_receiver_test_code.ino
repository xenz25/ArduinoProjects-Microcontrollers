s#include <IRremote.h>
#define RECEIVER_PIN A0
#define on_code 0xB24D4040
#define on_code_relay 0xFE014040
#define RELAY_ON_PIN 2
#define CHANNEL_1_PIN 3
int main_switch = 0;
int channel_1 = 0;
void setup() {
  Serial.begin(115200);
  IrReceiver.begin(RECEIVER_PIN, ENABLE_LED_FEEDBACK);
  pinMode(RELAY_ON_PIN, OUTPUT);
  pinMode(CHANNEL_1_PIN, OUTPUT);
  digitalWrite(CHANNEL_1_PIN, HIGH);
  digitalWrite(RELAY_ON_PIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    switch (IrReceiver.decodedIRData.decodedRawData) {
      case on_code:
        if (main_switch == 0) {
          main_switch = 1;
          digitalWrite(RELAY_ON_PIN, HIGH);
          Serial.println("Switch is On");
        } else if (main_switch == 1) {
          main_switch = 0;
          digitalWrite(RELAY_ON_PIN, LOW);
          Serial.println("Switch is Off");
        }
        break;
        case on_code_relay:
        if (channel_1 == 0 && main_switch == 1) {
          channel_1 = 1;
          digitalWrite(CHANNEL_1_PIN, LOW);
          Serial.println("Relay is On");
        } else if (channel_1 == 1) {
          channel_1 = 0;
          digitalWrite(CHANNEL_1_PIN, HIGH);
          Serial.println("Relay is Off");
        } else {
          Serial.println("The switch is off");
        }
        break;
      default:
        break;
    }
    IrReceiver.resume();
  }
}

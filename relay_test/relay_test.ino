int ON_PIN = 2;
int signal_pin2 = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(ON_PIN, OUTPUT);
  pinMode(signal_pin2, OUTPUT);
  digitalWrite(ON_PIN, HIGH);
  digitalWrite(signal_pin2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*for(int i = 0; i<=5; i++){
    if(i % 2 == 0){
      digitalWrite(ON_PIN, HIGH);
      //digitalWrite(signal_pin2, LOW);
    }else {
      digitalWrite(ON_PIN, LOW);
      //digitalWrite(signal_pin2, HIGH);
    }
    delay(1000);
  }*/
}

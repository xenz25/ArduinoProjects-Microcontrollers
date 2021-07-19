int toggle = 0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);

  digitalWrite(2, HIGH); //relay off
}

void loop() {
  // put your main code here, to run repeatedly:
  int button = digitalRead(4);
  Serial.println(button);
//  if (button == HIGH) {
//    if (toggle % 2 == 0) {
//      toggle = 1;
//      digitalWrite(3, toggle);
//    } else {
//      toggle = 0;
//      digitalWrite(3, toggle);
//    }
//  }


  digitalWrite(3, LOW);
  delay(500);
  digitalWrite(3, HIGH);
  delay(500);
}

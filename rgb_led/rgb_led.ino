const int rgbLedPins[] = {11,9,10};
const int rgbPinSize = 3;

const int mainColors[][8] = {
  {0,0,0}, //all off
  {1,0,0}, //red
  {0,1,0}, //green
  {0,0,1}, //blue
  {1,1,0}, //yellow
  {0,1,1}, //cyan
  {1,0,1}, //purple
  {1,1,1} //white
};

const int mainColorSize = 8;
const int DISPLAY_TIME = 1000;

void setup(){
  for(int i = 0; i <  rgbPinSize; i++){
    pinMode(rgbLedPins[i], OUTPUT);
  }
}

void loop(){
  for(int i = 0; i < mainColorSize; i++){
    lightByColorValue(mainColors[i]);
    delay(DISPLAY_TIME);
  }
}

void lightByColorValue(int rgb[]){
  digitalWrite(rgbLedPins[0], rgb[0]); //red
  digitalWrite(rgbLedPins[1], rgb[1]); //green
  digitalWrite(rgbLedPins[2], rgb[2]); //blue
}

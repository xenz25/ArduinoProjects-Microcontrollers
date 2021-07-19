#import <Math.h>

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  // iterating on strings
  //  String s = "hello";
  //  for(int i = 0; i < s.length(); i++){
  //   Serial.println(s.charAt(i));
  //  }

  //BINARY TO DEC
  //  byte binary_number = B11111001;
  //  String binary = String(binary_number, DEC);
  //  //using toCharArray() requires a buffer
  //  //using c_str() no need fo buffer can directly convert String to const char array
  //
  //  //using CharArray
  //  //char buff[binary.length() + 1];
  //  //binary.toCharArray(buff, binary.length() + 1);
  //
  //  int decimal = binary.toInt();
  //  Serial.println(decimal);

  //  byte binary_number = B11111001;
  //  String hex = String(binary_number, HEX);
  //  hex = "0x"+hex;
  //  strtol
  //  Serial.println(hex.toInt());
  //  int hexCode = hex.toInt();


  //more adaptive converion is by usng strol
  //strtol(const char array, the pointer address to store last reading of the function, the base of conversion 0 makes it auto detect);
  //BINARY TO HEX
  //  byte bin = B11111001;
  //  String temp_str = String(bin, HEX);
  //  temp_str = "0x"+temp_str;
  //  long int hex = strtol(temp_str.c_str(), NULL, 0);
  //  Serial.println(hex);

  //HEX TO DEC
  //  byte hex = 0xf9;
  //  String temp_str = String(hex, DEC);
  //  long int hex2 = strtol(temp_str.c_str(), NULL, 0);
  //  Serial.println(hex2);

  //OCTAL TO DEC
  //  int oct = 0371;
  //  String temp_str = String(oct, DEC);
  //  long int dec = strtol(temp_str.c_str(), NULL, 0);
  //  Serial.println(dec);

  //SIGNED TO BIN
    signed long int dec2 = -12;
    long int number_pos = 0;
    if(dec2 < 0){
      number_pos = abs(dec2);
    } else {
      number_pos = dec2;
    }
    String temp_str = String(dec2, BIN);
    Serial.println(temp_str);
//    signed long int num = strtol(temp_str.c_str(), NULL, 2);
//    Serial.println(num);
}

void loop() {
  // put your main code here, to run repeatedly:

}

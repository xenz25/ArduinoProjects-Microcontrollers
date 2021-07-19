//Allows you to convert in different number formats, DEC, BIN, HEX, OCT

#ifndef zBC
#define zBC

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class zBasicConvert  {
  public:
    // Constructor 
    //zBasicConvert(bool displayMsg=false);

    // Methods
    //decimal conversions 
    xDectoBin(long int decimal = 0);
    xDectoHex(long int decimal = 0);
    xDectoOct(long int decimal = 0);

  private:
    bool _msg;
    float getPi();
};
#endif

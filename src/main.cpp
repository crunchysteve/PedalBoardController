#include <Arduino.h>
#include <EEPROM.h>
#include <EdgieD.h>

#include "scope.h" //  See include/pins.h in project heirarchy
#include "functions.h"  //  See include/functions.h in project heirarchy

//  instantiate button debounce classes
Edge buttonA_BP;        //
Edge buttonA_PS;        //
Edge buttonB_BP;        //
Edge buttonB_PS;        //--  state change detect each button
Edge buttonC_BP;        //
Edge buttonC_PS;        //
Edge buttonD_BP;        //
Edge buttonD_PS;        //

void setup() {
  //  Set Relay and LED pins as OUTPUTS
  for(int i = RELAY_A_BP; i <= RELAY_D_PS; i++) pinMode(i,OUTPUT);
  //  read last used settings on startup
  fromByte(EEPROM.read(0));   //  All changes to current settings update to EEPROM 0
}

void loop() {
  //  Iterate through testing buttons
  bool edges[] {
                buttonA_BP.detect(BUTTON_A_BP),buttonA_PS.detect(BUTTON_A_PS),
                buttonB_BP.detect(BUTTON_B_BP),buttonA_PS.detect(BUTTON_B_PS),
                buttonC_BP.detect(BUTTON_C_BP),buttonC_PS.detect(BUTTON_C_PS),
                buttonD_BP.detect(BUTTON_D_BP),buttonD_PS.detect(BUTTON_D_PS)
               };
  for(int i = 0; i < 8; i++){
    liveBits[i] = buttonTest(edges[i],liveBits[i],relays[i]);
  }
  //  store any changed values in the working memory but only if they are changed
  if(EEPROM.read(0) != ToByte(liveBits)) EEPROM.update(0,ToByte(liveBits));
}
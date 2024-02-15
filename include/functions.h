#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

        //  create 8 character char array from 8 bit bool array
        unsigned char ToByte(bool b[8]){
            unsigned char c = 0;
            //  populate c by leftshifting b[8] into it
            for (int i=0; i < 8; ++i) if (b[i]) c |= 1 << i;
            return c;
        }

        //  extract liveBits[] array from 8 character char array (eg EEPROM location)
        void fromByte(unsigned char c){
            for (int i=0; i < 8; ++i) liveBits[i] = (c & (1<<i)) != 0;
        }

        //  test button, reset relay, return relay state
        bool buttonTest(bool test, bool relayState, int relay){
            if(test) relayState = !relayState;  //  if test is true, toggle state
            digitalWrite(relay,relayState);     //  set output to new state
            return relayState;                  //  return new state
        }
#endif
        
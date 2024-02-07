#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

        unsigned char ToByte(bool b[8]){
            unsigned char c = 0;
            for (int i=0; i < 8; ++i) if (b[i]) c |= 1 << i;
            return c;
        }

        void fromByte(unsigned char c){
            for (int i=0; i < 8; ++i) liveBits[i] = (c & (1<<i)) != 0;
        }

        bool buttonTest(bool test, bool relayState, int relay){
            if(test) relayState = !relayState;
            digitalWrite(relay,relayState);
            return relayState;
        }
#endif
        
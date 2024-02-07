#ifndef CONSTANTS_H
    #define CONSTANTS_H

        //  Define control button input macros
        #define BUTTON_A_BP 2   //  Pair A Bypass
        #define BUTTON_A_PS 3   //  Pair A Pedal Select
        #define BUTTON_B_BP 4   //  Pair B Bypass
        #define BUTTON_B_PS 5   //  Pair B Pedal Select
        #define BUTTON_C_BP 6   //  Pair C Bypass
        #define BUTTON_C_PS 7   //  Pair C Pedal Select
        #define BUTTON_D_BP 8   //  Pair D Bypass
        #define BUTTON_D_PS 9   //  Pair D Pedal Select
        #define BUTTON_PD  10   //  Program Decrement
        #define BUTTON_PI  11   //  Program Increment
        #define BUTTON_ALL 12   //  Bypass all

        //  Define output macros
        #define RELAY_A_BP 16   //  Pedal Bypass Relays (drives both relays for Pair A)
        #define RELAY_A_PS 18   //  Pedal Select Relays (drives both relays for Pair A)
        #define RELAY_B_BP 20   //  Pedal Bypass Relays (drives both relays for Pair A)
        #define RELAY_B_PS 22   //  Pedal Select Relays (drives both relays for Pair A)
        #define RELAY_C_BP 24   //  Pedal Bypass Relays (drives both relays for Pair A)
        #define RELAY_C_PS 26   //  Pedal Select Relays (drives both relays for Pair A)
        #define RELAY_D_BP 28   //  Pedal Bypass Relays (drives both relays for Pair A)
        #define RELAY_D_PS 30   //  Pedal Select Relays (drives both relays for Pair A)

        //  Declare array of output state change variables
        bool liveBits[8];

        //  Declare array of relays
        byte relays[] {
                       RELAY_A_BP, RELAY_A_PS, 
                       RELAY_B_BP, RELAY_B_PS, 
                       RELAY_C_BP, RELAY_C_PS, 
                       RELAY_D_BP, RELAY_D_PS 
                      };

#endif
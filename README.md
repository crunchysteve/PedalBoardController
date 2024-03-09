# Pedal Board Controller

*Maintainer's note: * I've been looking at Joyo's PXL-Pro and Pxl-Live loop switchers, these offer the 
more traditional style loop control and I'm thinking a redesign might be the go. That said, as a sound 
guy, to me, guitar pedals have 6 distinct types, signal conditioning (you only need one set of these), 
signal tracking (pitch and synths), drive (overdrive or distortionO, modulation (chorus or flange) and 
space/impulse (echo and reverb), then your amp or amp sim (you may have 2 amps,  you'll probably only 
have one amp sim with lots of patches, and thise, again, like conditioning, are better switched after 
the loops. So, I'm rethinking my 4x A/B(+optional/C/D) design ans an 8x bypass loop can do this, at 
least to A/B depth. I'm also wondering if the 4xA/B-Y model can be hybridised with the 8xbypass model.

## Introduction
The purpose of this project is to develop a guitar effects pedal switcher that brings the advantages 
of a multi effects unit to an array of discrete effects pedals. Think along the lines of devices 
like the -Moen GEC4 or 5 devices or the Joyo PXL series- (see above note.) Any guitarist will tell you these sorts of 
loop controllers sound better than most multifx systems, but lets not have that argument here 
&#128517;

Suffice to say, the primary disadvantage of a selection of custom effects pedals is a spasmodic 
dance when switching them in and out. The primaray advantage of a multi effect unit is being able to 
tap an **up** or a **down** button to run through a list of presets. This project aims to allow you 
to build a 2 path by 4 slot matrix switcher that brings the multi effects advantage to a custom 
pedal board of "hand chosen," "bespoke" "squash boxes."

Using almost any Arduino or other microcontroller and two 8x single pole, double throw relay modules 
it's possible to switch 2 rows of individually in and out of 4 slots. This shows the signal path...
![Relay Signal Path](./notes/RelaySignalPath.png)

The above shows, from "Pedal Pair A" to "Pedal Pair D", a slot for choice of 2 pitch or tracking 
pedals ("pitch" and "synth"), 2 drive pedals ("British" and "American", my Joyo drive pedals), 2 
modulation pedals ("Chorus and "Flange") and 2 atmospherics/impulse pedals. ("Reverb" and "Echo") 
Each pair can be bypassed completely, too. There will also be a master bypass switch (not a relay) 
in case of logic failure.

Using a larger micro, such as a Mega2560, and more relay modules, it should be possible to switch 
pedals in up to 4 rows and 8 groups, although, for 99% of musicians, 4 by 2 should be more than 
enough. I run a 30 watt, Australian designed, Chinese built, class A tube amp, not unlike an AC30, 
so I don't need a dedicated impulse pair for amp simulation and, if I did, impulse modellers tend to 
already be digital and multimodel selectable, so a single unit, after the switch chain would work 
for me, likewise for signal conditioning at the beginning of the pedal chain such as dynamics and 
preamps.

The various pedal switching configurations will be stored in EEPROM, with location 0 being used to 
hold the current working state, updating it only when a change occurs. The aim is to verify any 
write and, if a write fails on the working memory location, the system will update to using "-1" and 
so on, which, of course, is 4095 for an Arduino Mega2560 or, for an Uno/Nano, is 1023.

Switch patterns will also be saveable to EEPROM as 20 banks of 20, from 21 to 420, leaving, 90 
locations (on Uno/Nano, ~3500 on Mega) for working memory and 19 locations reserved for other system 
values on 328p chips.

## How It Works
8 digital inputs, connected to 8 heavy duty, momentary pushbuttons, will be used to sense pedal 
pair bypass (front row of 4 buttons) and pedal selection. (rear row of 4) The buttons will be 
debonced by the EdgieD library and a button tap wil invert the state of the button's position in 
the liveBits[8] array. The liveBits[8] array states are output to 8 digital outputs to drive the 16 
relays (in pairs, forming a DPDT switch) to select/bypass each pedal/pair and 8 LEDs to indicate 
selection and bypass states, such that off = A and through, on = B and bypass, depending on the 
switch row, select or bypass. 5 other buttons will control bank up/down, memory up/down and store 
memory. 

On 328p Arduino boards, pins will be a bit of a juggle, as I2C will be needed to drive a display. I 
plan to use a MegaMini board, to make this easier, but using an UNO or Nano is doable. The display 
probably only needs to be an LCD0802 or LCD1602. Even a 7 segment LED is probably enough to display 
bank and memory.

## Construction and Layout
For me, the biggest advantage of this kind of system is being able to have the controller and pedals 
on a table, with a switch bank in a box on the floor. This will allow for switching program banks by 
foot operation, but tweaking actual pedal controls, while playing, without having to bend down to 
the floor. Having my pedals closer to eye level also helps as my eyesight is appalling these days! 
Even with glasses!

Using micros such as the ESP32 or ESP8266 would allow this kind of setup to be wireless. Button 
inputs and debouncing on the floor unit, relay outputs and EPROOM/Flash in the switching unit. The 
liveBits[8] array shared from the floor to the switch via Bluetooth. Having a unique ID for each 
build will allow multiple units to operate together, as the floor and swith modules can be 
programmed to respond only to their opposite part. This is beyond the scope of early development, 
but may well be doable in a later version or fork.

## Still To Come (Roadmap)
At this stage, the repo is at a proof-of-concept stage and builds, It hasn't been tested on hardware 
yet. There is also no use of EEPROM yet, other than to establish a "working memory" array that will 
hold current state, for each button tap and update an EEPROM address if the switch settings change.

The plan is to use this state buffer to hold the current working selections until they can be stored to a permanent EEPROM location. An Uno or Nano can theoretically hold 256 memories (on location for selection/bypass byte, one "label" byte) but will be setup by default for 128 EEPROM memories in 8 banks by 16 addresses. A Mega or Mega Mini can address 4096 EEPROM addresses, so you could alter the defaults to run 64 banks of 64 memories, which is probably absurd for even the busiest professional sessions guitarist. This state buffer will hold the working settings in the case of a power failure.

In reality, there may also be a need for some locations as "fail buffers" for the working memory location. You get roughly a few million writes to EEPROM, give or take, so doing a validity check after an update would allow a new EEPROM location to be chosen (and address saved) for use as working buffer. A realistic number of patches is probably 8 banks of 16 (128) locations for storing presets for 4 pairs of switch positions with their address values for an 7 segment LED display to use, hence 256 EEPROM slots for 128 patches, over 8 banks of 16 settings.

This project will eventually have a choice of displays, but the default for now will be a 4 pin, I2C, 7 segment LED.

I'd also like to add a pair of programmable amp control buttons, if possible, so that reverb and clean/dirty channels can be selected, where amps support this, and programmable for the many ways amps do this.

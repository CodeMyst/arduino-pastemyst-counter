# Arduino PasteMyst Counter

A small project that shows the number of currently active pastes on https://paste.myst.rs/ on my Arduino.

![20220527_164325-min](https://user-images.githubusercontent.com/7966628/170723303-51f57220-3f14-4c94-8449-98f86296ebb3.jpg)

## How it works

A small D program fetches the current paste count from the [API](https://paste.myst.rs/api-docs/data) and sends it to the Arduino via serial.

The Arduino then just displays that number on the screen.

## Hardware

I am using a knock-off Arduino UNO connected with an OPEN-SMART 3.2" TFT touchscreen display.

## How to compile

### Arduino

First you need a few libraries: Adafruit_GFX, MCUFRIEND_kbv and Adafruit_BusIO.

To get my specific display to work, you need to modify MCUFRIEND_kbv like so:

1. Edit `utility/mcufriend_shield.h`: `#define USE_SPECIAL`
2. Edit `utility/mcufriend_special.h`: `#define USE_OPENSMART_SHIELD_PINOUT_UNO`
3. Edit `MCUFRIEND_kbv.cpp`: `#define SUPPORT_8352B`

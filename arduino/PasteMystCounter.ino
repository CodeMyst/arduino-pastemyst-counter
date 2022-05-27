#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <Fonts/FreeSansBold24pt7b.h>

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

MCUFRIEND_kbv tft;

void setup() {
    Serial.begin(9600);

    while (!Serial);

    uint16_t id = tft.readID();

    tft.begin(id);
    tft.setRotation(3);
    tft.fillScreen(0x0000);

    tft.setFont(&FreeSansBold24pt7b);
    tft.setCursor(50, 50);
    tft.setTextColor(0xFFFF);
    tft.print("PasteMyst");
}

void loop() {
}

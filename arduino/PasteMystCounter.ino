#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include "UbuntuMono_Med.h"
#include "UbuntuMono_Big.h"

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
    tft.setRotation(1);

    draw(0);
}

void loop() {
    if (Serial.available() > 0) {
        uint8_t packet[8];
        Serial.readBytes(packet, 8);

        // convert 8 bytes to long, big-endian format
        long int num = ((int64_t) packet[0] << 56) | ((int64_t) packet[1] << 48) | ((int64_t) packet[2] << 40) |  ((int64_t) packet[3] << 32) |
                       ((int64_t) packet[4] << 24) | ((int64_t) packet[5] << 16) | ((int64_t) packet[6] << 8)  |  ((int64_t) packet[7]);

        draw(num);
    }
}

void draw(int num) {
    tft.fillScreen(0x0000);

    tft.setFont(&UbuntuMono_R16pt7b);
    tft.setCursor(50, 85);
    tft.setTextColor(0xA534);
    tft.setTextSize(1);
    tft.print("PasteMyst Counter");

    tft.setFont(&UbuntuMono_R34pt7b);
    tft.setCursor(50, 150);
    tft.setTextColor(0xEB61);
    tft.print(num);
}

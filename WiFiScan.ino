/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is almost the same as with the WiFi Shield library,
 *  the most obvious difference being the different file you need to include:
 */
#include "WiFi.h"
#include <SSD1306.h>
#include <Wire.h>
#include "OLEDDisplayUi.h"

#define OLED_ADDR 0x3C
#define OLED_SDA  5
#define OLED_SCL  4

SSD1306 display(OLED_ADDR, OLED_SDA, OLED_SCL);
OLEDDisplayUi ui     ( &display );

void setup()
{
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    display.init();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "WiFi Scanner");
    display.drawString(0, 16, "by David King");
}

void loop() {
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.display();
    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    if (n == 0) {
        display.clear();
        //display.display();
        display.drawString(0, 0, "no networks found");
        display.display();
    } else {
        display.clear();
        display.drawString(0, 0, (String)n);
        display.drawString(10, 0, " networks found");
        for (int i = 0; i < n; ++i) {
          int iadj = i + 1;
            // Print SSID and RSSI for each network found
            //Serial.print(i + 1);
            //Serial.print(": ");
            //Serial.print(WiFi.SSID(i));
            //Serial.print(" (");
            //Serial.print(WiFi.RSSI(i));
            //Serial.print(")");
            //Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            //delay(10);

            // Display on OLED
            // display.drawString(xMove, yMove, msg);
            display.drawString(0, iadj * 10, WiFi.SSID(i));
            //display.drawString(0, iadj * 10, " (");
            //Serial.print(WiFi.RSSI(i));
            //Serial.print(")");
            //Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
          }
          display.display();
          delay(10000);

}
}

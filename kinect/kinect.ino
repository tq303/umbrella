#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

const uint64_t PIPE = 0xE8E8F0F0E1LL;

RF24 radio(9,10);

String formatKinect;

bool hasFeed;
bool endFeed;

void setup(){
    Serial.begin(9600);

    radio.begin();
    radio.openWritingPipe(PIPE);

    formatKinect = "";
}

void loop() {

    int pos = 0;

    // get data from oF app
    while (Serial.available() && (pos < (sizeof(formatKinect) - 1))) {
        if (Serial.read() == ':') {
            hasFeed = true;
        }
        if (hasFeed && !endFeed) {
            formatKinect += Serial.read();
            delay(10);
        }
    }

    // transmit data
    radio.write(formatKinect, sizeof(formatKinect));

    // reset array
    memset(formatKinect, 0, sizeof(formatKinect));
}

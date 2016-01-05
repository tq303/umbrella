#pragma once

#include "Arduino.h"

class Format {

    public:

        Format(void);

        void
            decode(String&),
            encode(),
            setUmbrella(int),
            setSpeed(int),
            setAnimation(int),
            setColour(int,int,int),
            resetArray(int*,int,int),
            splitToArray(int*, int, String&, char);

        int
            stringToInteger(String&),
            getUmbrella(),
            getAnimation(),
            getSpeed(),
            getRed(),
            getGreen(),
            getBlue();

        String getCommunicationString();

    private:

        int
            umbrella,
            animation,
            speed,
            msgElementPos,
            msgElementVariablePos;

        int* colour;

        String communicationString;
};

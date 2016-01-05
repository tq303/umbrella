/**
 * Elements separated by .
 * variables separated by ,
 * message endindicated by ;
 *
 * element[0] = umbrella
 * element[1] = animation
 * element[2] = speed
 * element[3] = color[3]
 *
 */

#include "Format.h"

using namespace std;

Format::Format(void) {
    umbrella = 0;
    animation = 0;
    speed = 100;
    communicationString = "";
    msgElementPos = 0;
    msgElementVariablePos = 0;

    colour = new int[3];

    resetArray(colour, 0, 3);
}

void Format::decode(String& input) {

	String element = "";

    for (int i = 0; i < input.length(); i++) {

        if (input[i] == ':') {
            continue;
        }

        if (input[i] == '.' || i == (input.length() - 1)) {

            if (i == (input.length() - 1)) {
                element += input[i];
            }

            // set variables
			if (msgElementPos == 0) {
                umbrella = stringToInteger(element);
            }  else if (msgElementPos == 1) {
                animation = stringToInteger(element);
            }  else if (msgElementPos == 2) {
                speed = stringToInteger(element);
            }  else if (msgElementPos == 3) {
                splitToArray(colour, 3, element, ',');
            }

            element = "";
            msgElementPos++;
            msgElementVariablePos = 0;
            continue;
        }

        if (input[i] == ',') {
            element += input[i];
            msgElementVariablePos++;
            continue;
        }

        if (input[i] != ',' && input[i] != '.' && input[i] != ';') {
            element += input[i];
            continue;
        }

    }

}

void Format::splitToArray(int* array, int length, String& splitDelegate, char delimiter) {

    String numberStr = "";
    int stringLength = splitDelegate.length();
    int arrayPos = 0;

    for (int i = 0; i < stringLength; i++) {

        if (arrayPos >= length) {
            break;
        }

        if (splitDelegate[i] == delimiter || splitDelegate[i] == ';') {
            array[arrayPos] = stringToInteger(numberStr);
            numberStr = "";
            arrayPos++;
        } else {
            numberStr += splitDelegate[i];
        }
    }

}

int Format::stringToInteger(String& input) {
    if (input.length() > 0) {
        return input.toInt();
    } else {
        return 0;
    }
}

void Format::setUmbrella(int _u) {
    umbrella = _u;
}
void Format::setSpeed(int _s) {
    speed = _s;
}
void Format::setAnimation(int _a) {
    animation = _a;
}
void Format::setColour(int _r, int _g, int _b) {
    colour[0] = _r;
    colour[1] = _g;
    colour[2] = _b;
}
void Format::encode() {
    communicationString = ":";
    communicationString += String(umbrella) += '.';
    communicationString += String(animation) += '.';
    communicationString += String(speed) += '.';
    communicationString += String(colour[0]) += ',';
    communicationString += String(colour[1]) += ',';
    communicationString += String(colour[2]) += ';';
}

String Format::getCommunicationString() {
    return communicationString;
}

void Format::resetArray(int* array, int value, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = value;
    }
}

int Format::getUmbrella() {
    return umbrella;
}

int Format::getAnimation() {
    return animation;
}

int Format::getSpeed() {
    return speed;
}

int Format::getRed() {
    return colour[0];
}

int Format::getGreen() {
    return colour[1];
}

int Format::getBlue() {
    return colour[2];
}

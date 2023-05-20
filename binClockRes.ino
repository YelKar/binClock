#include "arrow.h"


int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
int sec = 0;

clock::Arrow arrow(clockPin, latchPin, dataPin);
clock::Clock clk(&arrow, &arrow, &arrow);

void setup(){}
void loop()
{
    clk.open();
    clk.set(sec++, sec, sec);
    clk.close();
    delay(1000);
    sec %= 60;
}

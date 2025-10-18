#include "NRF51_Radio_library.h"

#define X 1
#define Y 2

NRF51_Radio radio = NRF51_Radio();

void setup() {
  radio.enable();
  radio.setGroup(10);
  radio.setFrequencyBand(42);
  radio.setTransmitPower(4);

  pinMode(X, INPUT);
  pinMode(Y, INPUT);
}

void loop() {
  uint8_t Xval = analogRead(X) / 4; // scale 0-1023 → 0-255
  uint8_t Yval = analogRead(Y) / 4;

  FrameBuffer frame;
  frame.version  = 1;
  frame.group    = 10;
  frame.protocol = 1;
  frame.length   = 2;        
  frame.payload[0] = Xval;
  frame.payload[1] = Yval;

  radio.send(&frame);
  delay(50); // faster update (optional)
}

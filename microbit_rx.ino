#include "NRF51_Radio_library.h"
#include "GyverMotor.h"

NRF51_Radio radio = NRF51_Radio();
GMotor motorR(DRIVER2WIRE, 13, 14);
GMotor motorL(DRIVER2WIRE, 15, 16);

void setup() {
  Serial.begin(115200);
  radio.enable();
  radio.setGroup(10);
  radio.setFrequencyBand(42);
}

void loop() {
  int8_t val1 = 0; // signed values
  int8_t val2 = 0;

  FrameBuffer *rx = radio.recv();
  if (rx != NULL) {
    if (rx->length >= 2) {
      val1 = (int8_t)(rx->payload[0] - 128); // map 0-255 -> -128..127
      val2 = (int8_t)(rx->payload[1] - 128);
    }
    delete rx; // free memory
  }

  int16_t speedL = val1 + val2;
  int16_t speedR = val1 - val2;

  // constrain speeds to motor limits
  speedL = constrain(speedL, -255, 255);
  speedR = constrain(speedR, -255, 255);

  if (speedL >= 0) motorL.setMode(FORWARD); else motorL.setMode(BACKWARD);
  if (speedR >= 0) motorR.setMode(FORWARD); else motorR.setMode(BACKWARD);

  motorL.setSpeed(abs(speedL));
  motorR.setSpeed(abs(speedR));
}


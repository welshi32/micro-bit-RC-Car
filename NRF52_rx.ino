#include <nrf_to_nrf.h>
#include "GyverMotor.h"

nrf_to_nrf radio;
GMotor motorR(DRIVER2WIRE, 13, 14);
GMotor motorL(DRIVER2WIRE, 15, 16);

void setup() {
  Serial.begin(115200);

  radio.begin();
  radio.enableDynamicPayloads();
  radio.openReadingPipe(0, 0xF0F0F0F0E1LL);
  
  // Match TX data rate
  radio.setDataRate(NRF_250KBPS);  

  radio.startListening();
}

void loop() {
  int8_t val1 = 0;
  int8_t val2 = 0;

  if (radio.available()) {
    uint8_t payload[2];
    radio.read(payload, sizeof(payload));

    // map 0-255 -> -128..127
    val1 = (int8_t)(payload[0] - 128);
    val2 = (int8_t)(payload[1] - 128);

    // Optional: print RSSI (signal strength)
    Serial.print("RSSI: ");
    Serial.print(radio.testRPD()); // returns 1 if received power > -64dBm, else 0
    Serial.print(" | Values: ");
    Serial.print(val1);
    Serial.print(", ");
    Serial.println(val2);
  }

  int16_t speedL = val1 + val2;
  int16_t speedR = val1 - val2;

  speedL = constrain(speedL, -255, 255);
  speedR = constrain(speedR, -255, 255);

  if (speedL >= 0) motorL.setMode(FORWARD); else motorL.setMode(BACKWARD);
  if (speedR >= 0) motorR.setMode(FORWARD); else motorR.setMode(BACKWARD);

  motorL.setSpeed(abs(speedL));
  motorR.setSpeed(abs(speedR));
}

#include <nrf_to_nrf.h>

#define X_PIN 1
#define Y_PIN 2

nrf_to_nrf radio;

void setup() {
  Serial.begin(115200);

  radio.begin();
  radio.enableDynamicPayloads();
  radio.openWritingPipe(0xF0F0F0F0E1LL);

  // Set maximum transmit power
  radio.setPALevel(NRF_PA_MAX);    // RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX

  // Set lowest data rate (250 kbps)
  radio.setDataRate(NRF_250KBPS);  // RF24_1MBPS, RF24_2MBPS

  radio.setAutoAck(false);          // optional for faster updates

  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
}

void loop() {
  uint8_t Xval = analogRead(X_PIN) / 4; // 0-1023 -> 0-255
  uint8_t Yval = analogRead(Y_PIN) / 4;

  uint8_t payload[2] = { Xval, Yval };
  radio.write(payload, sizeof(payload));

  delay(50); // 20 Hz update rate
}

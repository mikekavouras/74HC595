#include <SPI.h>

int SSPin = 7;
SPISettings settings(14000000, MSBFIRST, SPI_MODE0);

void setup() {
  SPI.begin();

  pinMode(SSPin, OUTPUT);
  digitalWrite(SSPin, HIGH);
}

void loop() {
  for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
    digitalWrite(SSPin, LOW);

    SPI.beginTransaction(settings);
    SPI.transfer(numberToDisplay);
    SPI.endTransaction();

    digitalWrite(SSPin, HIGH);

    delay(100);
  }
}

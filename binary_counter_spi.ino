#include <SPI.h>

int ssPin = 7;
SPISettings settings(14000000, MSBFIRST, SPI_MODE0);

void setup() {
  SPI.begin();
  pinMode(ssPin, OUTPUT);
  digitalWrite(ssPin, HIGH);
}

void loop() {
  for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
    digitalWrite(ssPin, LOW); 
    SPI.beginTransaction(settings);
    SPI.transfer(numberToDisplay);
    SPI.endTransaction();
    digitalWrite(ssPin, HIGH);
    delay(100);
  }
}

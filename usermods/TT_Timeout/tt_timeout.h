#pragma once

#include "wled.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"

//This is an empty v2 usermod template. Please see the file usermod_v2_example.h in the EXAMPLE_v2 usermod folder for documentation on the functions you can use!

class UsermodTTTimeout : public Usermod {

  Adafruit_7segment matrix1;
  
  public:
    void setup() {
      matrix1 = Adafruit_7segment();
      matrix1.begin(0x70);
    }

    void loop() {
      startCountdown();
    }

  void startCountdown() {
    Serial.print("Timer starting ");
    boolean drawDots = true;
    int minutes = 4;
    writeAllMatrixDigit(drawDots, 0, minutes + 1, 0, 0, 0, 15);
    for (int counter1 = minutes; counter1 >= 0; counter1--) {
      for (uint16_t counter2 = 59; counter2 > 0; counter2--) {
        delay(1000);
        drawDots = !drawDots;
        writeAllMatrixDigit(drawDots, 0, counter1, (counter2 / 10), (counter2 % 10), 0, 15);
      }
    }
    delay(1000);
    writeAllMatrixDigit(true, 0, 0, 0, 0, 2, 1);
    Serial.println("...finished!");
  }
  void writeAllMatrixDigit(bool drawDots, int one, int two, int three, int four, int blinkRate, int brightness) {
    writeDigit(matrix1, drawDots, one, two, three, four, blinkRate, brightness);
  }

  void writeDigit(Adafruit_7segment matrix, bool drawDots, int one, int two, int three, int four, int blinkRate, int brightness) {
    matrix.blinkRate(blinkRate);
    matrix.setBrightness(brightness);
    matrix.writeDigitNum(0, one, drawDots);
    matrix.writeDigitNum(1, two, drawDots);
    matrix.drawColon(drawDots);
    matrix.writeDigitNum(3, three, drawDots);
    matrix.writeDigitNum(4, four, drawDots);
    matrix.writeDisplay();
  }
};
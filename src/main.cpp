#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include "config/display.h"

LiquidCrystal lcd(RS, ENABLE, D0, D1, D2, D3, D4, D5, D6, D7);
uint8_t dinossaur[8] = {0x0, 0x7, 0x5, 0x7, 0x16, 0x1E, 0xA, 0xA};

void drawDino();

void setup() {
  // put your setup code here, to run once:
  pinMode(CONTRAST_PIN, OUTPUT);
  analogWrite(CONTRAST_PIN, CONTRAST);
  lcd.begin(20,4);
  lcd.clear();
  lcd.createChar(0, dinossaur);
}

void loop() {
  // put your main code here, to run repeatedly:
  drawDino();
}

void drawDino(void) {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(char(0));
  delay(1000);
}
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include "config/display.h"

LiquidCrystal lcd(RS, ENABLE, D0, D1, D2, D3, D4, D5, D6, D7);
uint8_t dinossaur[8] = {0b00000, 0b00111, 0b00111, 0b10110, 0b11110, 0b01010, 0b01010, 0b00000};

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
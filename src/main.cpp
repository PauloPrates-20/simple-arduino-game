#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include "display.h"
#include "dino.h"

LiquidCrystal lcd(RS, ENABLE, D0, D1, D2, D3, D4, D5, D6, D7);

void drawDino();

void setup() {
  // put your setup code here, to run once:
  pinMode(CONTRAST_PIN, OUTPUT);
  analogWrite(CONTRAST_PIN, CONTRAST);
  lcd.begin(20,4);
  lcd.clear();
  lcd.createChar(0, dino_standing);
  lcd.createChar(1, dino_left_leg);
  lcd.createChar(2, dino_right_leg);
}

void loop() {
  // put your main code here, to run repeatedly:
  drawDino();
}

void drawDino(void) {
  lcd.clear();
  for (uint8_t i = 0; i < 3; i++) {
    lcd.setCursor(i, 1);
    lcd.print(char(i));
  }
  delay(1000);
}
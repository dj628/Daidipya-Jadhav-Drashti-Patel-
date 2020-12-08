#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,7,6,5,4);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Hello world");

}

void loop() {
  // put your main code here, to run repeatedly:

}

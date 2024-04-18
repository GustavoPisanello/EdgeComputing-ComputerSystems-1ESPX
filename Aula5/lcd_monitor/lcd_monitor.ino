#include <LiquidCrystal.h>
#include <HCSR04.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
HCSR04 hc(8,7);

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  delay(500);
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);

  for(int i = 0; i <= 9; i++){
    lcd.setCursor(2,1);
    lcd.print("Distancia: ");
    lcd.print(hc.dist());
    delay(1000);  
  }
}

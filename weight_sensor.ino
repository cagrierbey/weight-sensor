#include <LiquidCrystal_I2C.h>
#include "HX711.h"

LiquidCrystal_I2C lcd(0x27,16,2);

#define DOUT 3
 
#define CLK 2
 
HX711 scale;
float lbs;
float kg=12.75f;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  //scale.begin(DOUT, CLK);
  
 
  //scale.set_scale(kalibrasyon_faktoru); // Ölçek ayarlandı
 
  //scale.tare(); // Ölçek sıfırlandı
}

void loop() {

  if (kg > 50 )
  {
    // put your main code here, to run repeatedly:
    lcd.setCursor(0,0);
    lcd.print("KG: ");
    lcd.print("OVER 50 KG"); // Okunan kütle değerini yazdırma
    //lcd.print(scale.get_units());
    //lbs = kg * 2.20462;
    lcd.setCursor(0,1);
    lcd.print("LB:  ");
    //lcd.print(lbs);
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("KG:  ");
    lcd.print(kg);
    //lcd.print(scale.get_units());
    lbs = kg * 2.20462;
    lcd.setCursor(0,1);
    lcd.print("LB:  ");
    lcd.print(lbs);
  }
  

  //Serial.println(scale.get_units()); 
  //Serial.println(kalibrasyon_faktoru); 
  
}

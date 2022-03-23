#include <PZEM004Tv30.h>
#include <Wire.h>  
#include <LiquidCrystal_I2C.h>  
PZEM004Tv30 pzem(11, 12); 
LiquidCrystal_I2C lcd(0x27, 16, 2);
int Relay = 8;
//float current = 1;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.clear();
  lcd.noCursor();
  pinMode(Relay, OUTPUT);
 
}

void loop() {
  float voltage = pzem.voltage();
  float current = pzem.current();
  float power = pzem.power();
  float energy = pzem.energy();
  float frequency = pzem.frequency();
  float pf = pzem.pf();
  
  digitalWrite (Relay,LOW);
  lcd.setCursor(0, 0);
  lcd.print(voltage);
  lcd.print("/");
  lcd.print(current);
  lcd.print("/");
  lcd.print(pf);
  lcd.print("      ");

   if (current > 5){
      digitalWrite (Relay,HIGH);
      delay (2000);
  }
  
  Serial.print("Arus = ");
  Serial.print(current);
  Serial.print(";   ");
  Serial.print("Tegangan = ");
  Serial.print(voltage);
  lcd.setCursor(0, 1);
  lcd.print(power);
  lcd.print("/");
  lcd.print(energy,3);
  lcd.print("/");
  lcd.print(frequency,1);
  lcd.print("      ");

  delay (100);
  
}

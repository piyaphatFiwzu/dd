#include <LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define sec 1000
#define SMS_pin A0 
#define reray_pin 8
int mode;
unsigned long  time;
float SMS_read;
float humanity;
void setup() {
  lcd.init();
  //lcd.begin();
  //lcd.display();
  lcd.backlight();
  pinMode(reray_pin,OUTPUT);
  pinMode(SMS_pin,INPUT);
  Serial.begin(9600);
}

void loop() {
SMS_read = analogRead(SMS_pin);
humanity = SMS_read / 10.24;
if ( millis() - time >= sec){
   lcd.print("Humanity:"); lcd.print(humanity); lcd.print("%");//LCD เเสดงค่า ความชื้น
   
   
   lcd.setCursor(0,1);lcd.print("Mode:");lcd.setCursor(6,1);
    if (mode == 0)
    {
      lcd.print("OFF");
    }
    else
    {
     lcd.print("OPEN");
    }
   delay(500);
   lcd.clear();
   time = millis();
}

if (humanity < 70)
{
  open();
}
else{
  off();
}

}


void off(){
  digitalWrite(reray_pin,1);
  mode = 0;
}
void open(){
digitalWrite(reray_pin,0);
 mode = 1;
}
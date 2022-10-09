#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
byte rowPins[4] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad 

byte colPins[4] = {6, 7, 8, 9}; //connect to the row pinouts of the keypad 

const byte ROWS = 4; //four rows 

const byte COLS = 4; //three columns 

char keys[ROWS][COLS] = {{'1','2','3','A'}
, 
{'4','5','6','B'}
,
{'7','8','9','C'}
,
{'*','0','#','D'}
}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char key = 'A';
LiquidCrystal_I2C lcd(0x27, 16, 2);//lcd.setCursor(0;0); lcd.print 

int p = 0;
int C = 0;
int r = 0;
int s=0;
Servo servo_pin_10;

void setup() {
  lcd.begin();
  servo_pin_10.attach(10);


  key = 'A';

  lcd.clear();

  p = 0;

  C = 8;

  r = 0;
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);

  lcd.setCursor(2, 0);
  lcd.print("Please Enter");
  lcd.setCursor(3, 1);
  lcd.print("Password");
  delay( 2000 );
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Password-");

  servo_pin_10.write( 0 );

}

void loop() {
  key = keypad.getKey();
  if (key) {  
    C = ( C + 1 );
    lcd.setCursor(C, 0);
    lcd.print(key);
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(11,LOW);
    r = ( r + 1 );
    //C = ( C + 1 );
    
    if (( key == '0' )) {p = ( p + 2 );
  }
  if (( key == '5' )) {p = ( p / 5 );
}
if (( key == 'A' )) {p = ( p / 4 );
}
if (( key == '2' )) {p = ( p * 10 );
}
if (( ( p == 11 ) && ( r == 7 ) )) {
  p=0;
  r=0;
  C=8;
  digitalWrite(12,HIGH);
  delay(2000);
  digitalWrite(12,LOW);
  servo_pin_10.write(100);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Right Password");
  delay(1000);
  lcd.clear();
}
if (( ( p != 11 ) && ( r == 7 ) )) {
  servo_pin_10.write(0);
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Wrong Password");
  delay(2000);
  lcd.clear();

  p=0;
  r=0;
  C=8;
    lcd.setCursor(2, 0);
  lcd.print("Please Enter");
    lcd.setCursor(1,1 );
  lcd.print("Password Again");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Password-");
}
if((key == '*'))
{servo_pin_10.write(0);
lcd.clear();
lcd.setCursor(2,0);
lcd.print("Reseting...");
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Password-");
p=0;
r=0;
C=8;
  }

  }}

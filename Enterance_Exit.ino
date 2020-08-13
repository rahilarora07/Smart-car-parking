#include<Servo.h>
#include <LiquidCrystal.h>

Servo myservo;

LiquidCrystal lcd(9, 11, 5, 4, 3, 2);

int enter=HIGH;
int escape=HIGH;
int car1=HIGH;
int car2=HIGH;
int car3=HIGH;
int car4=HIGH;
int c1=0,c2=0,c3=0,c4=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(0,INPUT);
  pinMode(12,INPUT);
  pinMode(10,INPUT);
  pinMode(9,INPUT);
  pinMode(8,INPUT);
  pinMode(7,INPUT);
  myservo.attach(13);
  myservo.write(180);
  Serial.begin(9600);
  analogWrite(6,120);
  lcd.begin(16, 2);
  lcd.print("Welcome");
}

void loop() {
  lcd.setCursor(0,1);
  enter=digitalRead(0);
  escape=digitalRead(12);
  car1=digitalRead(10);
  //car2=digitalRead(9);
  car3=digitalRead(8);
  car4=digitalRead(7);
  if(car1==HIGH || car2==HIGH || /*car3==HIGH ||*/ car4==HIGH)
  {
  while(enter==LOW || escape==LOW)
  {
    enter=digitalRead(0);
    escape=digitalRead(12);
    myservo.write(70);
    Serial.println("Open");
  }
  delay(3000);
  myservo.write(180);
  Serial.println("Close");
  }
  
  if(car1==LOW)
    c1=1;
  else 
    c1=0;
  if(car2==LOW)
    c2=1;
  else 
    c2=0;
  /*if(car3==LOW)
    c3=1;
  else 
    c3=0;*/
  if(car4==LOW)
    c4=1;
  else 
    c4=0; 

  if(c1==1 && c2==1 && /*c3==1 &&*/ c4==1)
  {
    
    Serial.print("Full");
    lcd.print("Full");
  }
  else
  {
    if(c1==0)
    {
      Serial.print(" 1");
      lcd.print(" 1");
    }
    if(c2==0)
    {
      Serial.print(" 2");
      lcd.print(" 2");
    }
    /*if(c3==0)
    {
      Serial.print(" 3");
      lcd.print(" 3");
    }*/
    if(c4==0)
    {
      Serial.print(" 4");
      lcd.print(" 4");
    }
    Serial.print(" are empty"); 
    lcd.print(" are empty"); 
  }
  lcd.noDisplay();
}

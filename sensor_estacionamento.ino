#include <LiquidCrystal.h>
#include <Ultrasonic.h>

#define VERMELHO 11
#define VERDE 10
#define GATILHO 12
#define ECHO 13 

LiquidCrystal lcd(8, 9, 5, 4, 3, 2);
 
void setup()
{
  lcd.begin(16, 2);
  pinMode(GATILHO,OUTPUT);
  digitalWrite(GATILHO,LOW);
  delayMicroseconds(10);
  pinMode(ECHO,INPUT);
  pinMode(VERMELHO, OUTPUT);
  pinMode(VERDE, OUTPUT);
}
 
void loop()
{
  float tempo;
  float distancia_cm;
  digitalWrite(GATILHO, HIGH);
  delayMicroseconds(10);
  digitalWrite(GATILHO, LOW);
  tempo = pulseIn(ECHO, HIGH);
 
  distancia_cm = tempo / 29.4 / 2;
 
  lcd.setCursor(0, 0);
  lcd.print("DISTANCIA->");
  lcd.print(distancia_cm/100);
  lcd.print("m");
  lcd.setCursor(0, 1);
  lcd.print("R.DE BATER:");
  lcd.setCursor(11,1);
  if(distancia_cm <= 50){
    lcd.print("ALTO ");
    digitalWrite(VERMELHO, HIGH);
    digitalWrite(VERDE, LOW);
  }
  else if(distancia_cm > 50 && distancia_cm < 200)
    lcd.print("MEDI0 ");
  else if(distancia_cm > 200){
    lcd.print("SAFE ");
    digitalWrite(VERMELHO, LOW);
    digitalWrite(VERDE, HIGH);
  }  
  delay(200);
}

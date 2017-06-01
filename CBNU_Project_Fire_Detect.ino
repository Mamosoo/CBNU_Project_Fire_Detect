#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);
const int gasPin = A0;

int inputPin = 2;

int pirState = LOW;

int val = 0;

int pinSpeaker = 10;

int led = 13;

void setup() {

  lcd.init();
  lcd.backlight();

  pinMode(inputPin, INPUT);

  pinMode(pinSpeaker, OUTPUT);

  Serial.begin(9600);

  pinMode(led, OUTPUT);


}

void loop() {

  val = digitalRead(inputPin);

  if (val == HIGH) {


    delay(150);

    if (pirState == LOW) {

      digitalWrite(led, LOW);
      Serial.println("Beware of fire.");
      lcd.print("Beware of fire");

      pirState = HIGH;
    }

  } else {

    tone(pinSpeaker, 500, 1000);
    delay(30);

    digitalWrite(led, HIGH);

    if (pirState == HIGH) {

      Serial.println("FIRE!!!!");
      lcd.print("FIRE!");
      tone(pinSpeaker, 500, 1000);
      delay(30);

      digitalWrite(led, HIGH);
      delay(10000);

      pirState = LOW;
    }
  }

  if (analogRead(gasPin) > 400)
  {
    tone(pinSpeaker, 500, 1000);
    digitalWrite(led, HIGH);

    Serial.println("GAS!!");
    lcd.print("GAS!");

  }
  else {


    digitalWrite(led, LOW);
  }
}



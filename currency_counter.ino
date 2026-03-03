#include <LiquidCrystal.h>

int OutPut = 13;
unsigned int frequency = 0;


LiquidCrystal lcd(4, 6, 7, 8, 9, 10);

int blue1;
int red1;
int green1;

int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
int total = 10000;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print(" Smart Wallet ");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" by KANCHANA and ");
  lcd.setCursor(0,1);
  lcd.print("HARSHITHA");
  delay(4000);

  lcd.clear();

  pinMode(2, OUTPUT);  //S0
  pinMode(3, OUTPUT);  //S1
  pinMode(11, OUTPUT); //S2
  pinMode(12, OUTPUT); //S3
  pinMode(13, INPUT);  //OUT

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}

void loop() {

  int sensor = analogRead(A0);

  red1 = red();
  blue1 = blue();
  green1 = green();

  Serial.println("RED:");
  Serial.println(red1);
  Serial.println("BLUE:");
  Serial.println(blue1);
  Serial.println("GREEN:");
  Serial.println(green1);
  Serial.println("-----------------------------");

  // Detecting 10 rupees
  if (red1 >= 20 && red1 <= 25 && blue1 >= 30 && blue1 <= 35 && green1 >= 30 && green1 <= 35 && a == 1) {
  } 
  else if (sensor == LOW && a == 1) {
    a = 0;
    if (total >= 10) {
      lcd.setCursor(0, 1);
      lcd.print("10 Rupees!!!");
      total = total - 10;
      delay(1500);
      lcd.clear();
    }
  }

  // Detecting 20 rupees
  if (red1 >= 18 && red1 <= 22 && blue1 >= 28 && blue1 <= 32 && green1 >= 28 && green1 <= 32 && f == 1) {
  } 
  else if (sensor == LOW && f == 1) {
    f = 0;
    if (total >= 20) {
      lcd.setCursor(0, 1);
      lcd.print("20 Rupees!!!");
      total = total - 20;
      delay(1500);
      lcd.clear();
    }
  }

  // Detecting 50 rupees
  if (red1 >= 40 && red1 <= 50 && blue1 >= 45 && blue1 <= 50 && green1 >= 10 && green1 <= 20) {
    b = 1;
  } 
  else if (sensor == LOW && b == 1) {
    b = 0;
    if (total >= 50) {
      lcd.setCursor(0, 1);
      lcd.print("50 Rupees!!!");
      total = total - 50;
      delay(1500);
      lcd.clear();
    }
  }

  // Detecting 100 rupees
  if (red1 >= 515 && red1 <= 525 && blue1 >= 515 && blue1 <= 525 && green1 >= 520 && green1 <= 530) {
    c = 1;
  } 
  else if (sensor == LOW && c == 1) {
    c = 0;
    if (total >= 100) {
      lcd.setCursor(0, 1);
      lcd.print("100 Rupees!!!");
      total = total - 100;
      delay(1500);
      lcd.clear();
    }
  }

  // Detecting 200 rupees
  if (red1 >= 460 && red1 <= 470 && blue1 >= 460 && blue1 <= 470 && green1 >= 560 && green1 <= 570) {
    d = 1;
  } 
  else if (sensor == LOW && d == 1) {
    d = 0;
    if (total >= 200) {
      lcd.setCursor(0, 1);
      lcd.print("200 Rupees!!!");
      total = total - 200;
      delay(1500);
      lcd.clear();
    }
  }

  // Detecting 500 rupees
  if (red1 >= 65 && red1 <= 70 && blue1 >= 65 && blue1 <= 70 && green1 >= 20 && green1 <= 25) {
    e = 1;
  } 
  else if (sensor == LOW && e == 1) {
    e = 0;
    if (total >= 500) {
      lcd.setCursor(0, 1);
      lcd.print("500 Rupees!!!");
      total = total - 500;
      delay(1500);
      lcd.clear();
    }
  }

  lcd.setCursor(0, 0);
  lcd.print("Total Bal:");
  lcd.setCursor(11, 0);
  lcd.print(total);

  delay(1000);
}

int red() {
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  delayMicroseconds(40);
  frequency = pulseIn(OutPut, LOW);
  return frequency;
}

int blue() {
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delayMicroseconds(40);
  frequency = pulseIn(OutPut, LOW);
  return frequency;
}

int green() {
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  delayMicroseconds(40);
  frequency = pulseIn(OutPut, LOW);
  return frequency;
}
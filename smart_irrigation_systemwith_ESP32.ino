#define BLYNK_TEMPLATE_ID "TMPL68c1JDC0y"
#define BLYNK_TEMPLATE_NAME "Plant watering system"
#define BLYNK_AUTH_TOKEN "eBNBgd0LTK0eNZIIH_2a5_29FTKG3oPL"

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define sensor 33
#define relay 4

LiquidCrystal_I2C lcd(0x27, 16, 2);
BlynkTimer timer;
char auth[] = "eBNBgd0LTK0eNZIIH_2a5_29FTKG3oPL";
char ssid[] = "Santo";
char pass[] = "98261";

void setup() {
  
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  lcd.init();
  lcd.backlight();
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);

  lcd.setCursor(1, 0);
  lcd.print("System Loading");
  for (int a = 0; a <= 15; a++) {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(200);
  }
  lcd.clear();
  
}

void soilMoisture() {
  int value = analogRead(sensor);
  value = map(value, 0, 4095, 0, 100);
  value = (value - 100) * -1;
  Blynk.virtualWrite(V0, value);
  Serial.println(value);
  lcd.setCursor(0, 0);
  lcd.print("Moisture :");
  lcd.print(value);
  lcd.print(" ");
}

BLYNK_WRITE(V1) {
  bool Relay = param.asInt();
  if (Relay == 1) {
    digitalWrite(relay, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Motor is OFF ");
  } else {
    digitalWrite(relay, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Motor is ON ");
  }
}

void loop() {
  soilMoisture();
  Blynk.run();

  delay(200);

}
#include <Servo.h>
#include <ESP8266WiFi.h>

#define BLYNK_TEMPLATE_ID "TMPL63xzEd_Ba"
#define BLYNK_TEMPLATE_NAME "catFeeder"
#define BLYNK_AUTH_TOKEN "t58wU_AE453zFsTTMjQTR7tIr5Km0RAK"

#include<BlynkSimpleEsp8266.h>

char auth[] = "t58wU_AE453zFsTTMjQTR7tIr5Km0RAK";

char ssid[] = "RiandRi";
char pass[] = "Btduo1314";

Servo servo;

BLYNK_WRITE(V0) {
  int pinValue = param.asInt();
  if (pinValue == 1) {
    servo.writeMicroseconds(1750);
    delay(220);

    servo.writeMicroseconds(1500);
    delay(300);

    servo.writeMicroseconds(1271);
    delay(220);

    servo.writeMicroseconds(1500);
    delay(3000);
  }
}

void setup() {
  // put your setup code here, to run once:
  Blynk.begin(auth, ssid, pass);
  servo.attach(5);
}

void loop() {
  // rotate counter-clockwise full-speed
  Blynk.run();
}

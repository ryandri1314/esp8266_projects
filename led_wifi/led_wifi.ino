#include <ESP8266WiFi.h>

#define BLYNK_TEMPLATE_ID "TMPL63xzEd_Ba"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_AUTH_TOKEN "t58wU_AE453zFsTTMjQTR7tIr5Km0RAK"

#include<BlynkSimpleEsp8266.h>

char auth[] = "t58wU_AE453zFsTTMjQTR7tIr5Km0RAK";

char ssid[] = "RiandRi";
char pass[] = "Btduo1314";

BLYNK_WRITE(V0) {
  int pinValue = param.asInt();
  digitalWrite(D2, pinValue);
}

void setup() {
  // put your setup code here, to run once:
  Blynk.begin(auth, ssid, pass);
  pinMode(D2, OUTPUT);
  digitalWrite(D2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}

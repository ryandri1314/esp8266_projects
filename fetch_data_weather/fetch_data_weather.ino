#include<ESP8266HTTPClient.h>
#include<ESP8266WiFi.h>
#include<ArduinoJson.h>

String location = "Ho Chi Minh City";
String API_key = "f6c58555d38e8a3513a53efdab272536";
float lon = 106.6667, lat = 10.75;
String dailyWeather[10];

#define WIFI_SSID "Ry and Ri"
#define WIFI_PASSWORD "Btduo1314"

void setup() {
  //Setup Serial port 115200
  Serial.begin(115200);

  //Connect to wifi
  WiFi.mode(WIFI_STA); //Set mode of MCU
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wifi ...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }

  //Print local IP
  Serial.println();
  Serial.print("Connected to IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  HTTPClient http;
  WiFiClientSecure client;
  client.setInsecure();

  String request = "https://api.openweathermap.org/data/2.5/weather?lat=10.75&lon=106.6667&appid=" + API_key;
  http.begin(client, request);
  int httpCode = http.GET();

  if (httpCode > 0) {
    String payload = http.getString();
    //Parse JSON Object
    JsonDocument root;
    DeserializationError error = deserializeJson(root, payload);

    //Catch error
    if (error) {
      //Print to Serial
      Serial.println(payload);
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      delay(2000);
      return;
    }

    //Get data from object
    float temp = (float)(root["main"]["temp"]) - 273.15; //Get tempfd
    int humidity = root["main"]["humidity"]; //Get humidity
    lon = (float)root["coord"]["lon"];
    lat = (float)root["coord"]["lat"]; 

    //Print to Serial
    Serial.print("Nhiet do la: ");
    Serial.println(temp);
    Serial.print("Do am la: ");
    Serial.println(humidity);
    Serial.println("--------------------------");
  }
  else {
    Serial.println(httpCode);
  }

  delay(2000);
}

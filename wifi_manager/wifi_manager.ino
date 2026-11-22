#include <Arduino.h>
#include <WiFiManager.h>

const int TRIGGER_PIN = 0; // Onboard BOOT button on ESP32
const char* AP_NAME = "BCA188-ESP32-1115";

void setup() {
  Serial.begin(115200);
  pinMode(TRIGGER_PIN, INPUT_PULLUP);

  WiFiManager wm;
  wm.setConfigPortalTimeout(180);

  bool res = wm.autoConnect(AP_NAME);

  if (!res) {
    Serial.println("Failed to connect or hit timeout.");
    delay(1000);
    ESP.restart();
  } else {
    Serial.println("\n----------------------------------------");
    Serial.println("STATUS: Connected to Wi-Fi!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    Serial.println("----------------------------------------");
  }
}

void loop() {
  if (digitalRead(TRIGGER_PIN) == LOW) {
    delay(3000);
    if (digitalRead(TRIGGER_PIN) == LOW) {
      Serial.println("BOOT button held for 3s. Resetting Wi-Fi settings...");
      WiFiManager wm;
      wm.resetSettings();
      delay(500);
      ESP.restart();
    }
  }
}

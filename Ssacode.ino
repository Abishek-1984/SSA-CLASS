#include "esp_camera.h"
#include "ESP32QRCodeReader.h"

ESP32QRCodeReader qr;

void setup() {
  Serial.begin(115200);
  
  // Initialize QR reader
  qr.setup();
  qr.begin();
}

void loop() {
  struct QRCodeData qrData;

  // Try to read QR code
  if (qr.receiveQrCode(&qrData, 100)) {
    
    if (qrData.valid) {
       String qrText = (const char *)qrData.payload;

      Serial.println(qrText);  // Send to ESP32 Dev
      delay(1500);
    }
  }
}
#include <BluetoothSerial.h>
BluetoothSerial SerialBT;
const int trig = 2;
const int echo = 4;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT"); // Nama perangkat Bluetooth
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  long duration, distance;
  // Mengirim sinyal ultrasonik
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); // Menerima waktu pantulan ultrasonik
  distance = duration * 0.034 / 2; // Menghitung jarak
  delay(1000); // Delay 1 detik sebelum membaca lagi
  SerialBT.println(distance);  
  Serial.println(distance);
}

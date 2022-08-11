void setup() {
  Serial.begin(9600); // 시리얼 통신 시작(속도), 1초에 9600개의 신호
  // Serial.println("Hello Arduino");
}

void loop() {
  char read_data;

  if(Serial.available())
  { 
    read_data = Serial.read();
    Serial.print(read_data);
  }
  delay(10);
}

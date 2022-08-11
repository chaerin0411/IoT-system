
//week03 - 디지털 입력(버튼) 스케치

int led1 = 7;
int led2 = 6;
int key1 = 13;
int key2 = 12;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(key1, INPUT);
  pinMode(key2, INPUT);
}

void loop() {
  if(digitalRead(key1) == HIGH) {
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    delay(500);
  }
  else
    digitalWrite(led1, LOW);
  
  if(digitalRead(key2) == HIGH) {
    digitalWrite(led2, HIGH);
    delay(100);
    digitalWrite(led2, LOW);
    delay(100);
  } 
  else
    digitalWrite(led2, LOW);

  delay(500);
}

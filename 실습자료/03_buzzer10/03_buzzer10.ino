int led1 = 7;
int led2 = 6;
int key1 = 13;
int key2 = 12;
int buzzer = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(key1, INPUT);
  pinMode(key1, INPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if( digitalRead(key1) == HIGH ){
    digitalWrite(led1, HIGH);
    digitalWrite(buzzer, HIGH); // Buzzer on
    delay(200);
    digitalWrite(buzzer, LOW); // Buzzer off
    delay(200);
  }
  else
    digitalWrite(led1, LOW);
  delay(100);

  if( digitalRead(key2) == HIGH ){
   digitalWrite(led2, HIGH);
    digitalWrite(buzzer, HIGH); // Buzzer on
    delay(200);
    digitalWrite(buzzer, LOW); // Buzzer off
    delay(200);
  }
  else
   digitalWrite(led2, LOW);
  delay(100);
}

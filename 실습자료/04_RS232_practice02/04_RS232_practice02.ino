int led1 = 8;
int led2 = 4;
int led3 = 6;
int led4 = 2;
int led1_status = LOW; // LED1 상태
int led2_status = LOW; // LED2 상태
int led3_status = LOW; // LED3 상태
int led4_status = LOW; // LED4 상태

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  Serial.begin(9600);
}

void loop() {
  char read_data;

  if(Serial.available())
  {
    read_data = Serial.read();
    if(read_data == '8' && led1_status == LOW)
    {
      digitalWrite(led1, HIGH);
      led1_status = HIGH;
      Serial.println("LED1 ON");
    }
    else if(read_data == '8' && led1_status == HIGH)
    {
      digitalWrite(led1, LOW);
      led1_status = LOW;
      Serial.println("LED1 OFF");
    }

    if(read_data == '4' && led2_status == LOW)
    {
      digitalWrite(led2, HIGH);
      led2_status = HIGH;
      Serial.println("LED2 ON");
    }
    else if(read_data == '4' && led2_status == HIGH)
    {
      digitalWrite(led2, LOW);
      led2_status = LOW;
      Serial.println("LED2 OFF");
    }

    if(read_data == '6' && led3_status == LOW)
    {
      digitalWrite(led3, HIGH);
      led3_status = HIGH;
      Serial.println("LED3 ON");
    }
    else if(read_data == '6' && led3_status == HIGH)
    {
      digitalWrite(led3, LOW);
      led3_status = LOW;
      Serial.println("LED3 OFF");
    }

    if(read_data == '2' && led4_status == LOW)
    {
      digitalWrite(led4, HIGH);
      led4_status = HIGH;
      Serial.println("LED4 ON");
    }
    else if(read_data == '2' && led4_status == HIGH)
    {
      digitalWrite(led4, LOW);
      led4_status = LOW;
      Serial.println("LED4 OFF");
    }

    if(read_data == ' ')
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      led1_status = LOW;
      led2_status = LOW;
      led3_status = LOW;
      led4_status = LOW;
      Serial.println("LED1 OFF");
      Serial.println("LED2 OFF");
      Serial.println("LED3 OFF");
      Serial.println("LED4 OFF");
    }
  }
  
  delay(10);
}

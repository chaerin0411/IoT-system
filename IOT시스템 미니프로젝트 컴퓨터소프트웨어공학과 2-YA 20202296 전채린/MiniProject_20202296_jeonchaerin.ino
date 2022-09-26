// IOT시스템 미니프로젝트 스케치 컴퓨터소프트웨어공학과 2-YA 20202296 전채린

#include <Wire.h> // i2c 통신을 위한 라이브러리
#include <Adafruit_MLX90614.h> // 비접촉식 온도측정센서 라이브러리
#include <LiquidCrystal_I2C.h> // lcd 1602 i2c 용 라이브러리
#define trigPin 13 
#define echoPin 12 
#define maximumRange 200 // 최대 측정 거리
#define minimumRange 0 // 최소 측정 거리

int ledy = 3; // 노랑 LED
int ledg = 4; // 녹색 LED
int ledr = 5; // 빨강 LED
int buzzer = 8; // 부저
int count = 0; // 출입 인원수
LiquidCrystal_I2C lcd(0x27, 16, 2);  
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() 
{
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    pinMode(ledy, OUTPUT);
    pinMode(ledg, OUTPUT);
    pinMode(ledr, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
    lcd.begin(); // lcd 시작
    lcd.backlight(); // 백라이트 켜기
    lcd.noCursor(); // 커서를 없앰
    lcd.noBlink(); // 커서를 깜박이지 않음
    mlx.begin(); // mlx 모듈을 읽기 시작
} 

long microsecondsToCentimeters(long microseconds)
{
    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
    // The ping travels out and back, so to find the distance of the
    // object we take half of the distance travelled.
    
    return microseconds / 29 / 2;
}

void loop() 
{ 
    long duration, cm;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW);
    // echoPin이 HIGH를 유지한 시간을 저장
    duration = pulseIn(echoPin, HIGH); 

    // HIGH였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산
    cm = microsecondsToCentimeters(duration);

    // 측정 범위를 벗어났을 때
    if (cm >= maximumRange || cm <= minimumRange)
    {
      Serial.println("out of range");
      lcd.clear();
      lcd.print("out of range"); 
    }
    
    // 측정 범위일 때
    else
    {
      Serial.print(cm, DEC);
      Serial.println("cm");
      
      // 사람이 지나갈 때
      if(cm <= 60)
      {
        count = count + 1; 
        Serial.print("count : ");
        Serial.println(count);
        lcd.clear();
        lcd.print("count : ");
        lcd.print(count);

        
        double strTemp; // 온도 측정
        strTemp = mlx.readObjectTempC(); 
        
        // 정상체온일 때
        if(strTemp >= 34.9 && strTemp <= 37.6) {
          Serial.print("Temperature : ");
          Serial.println(strTemp);
          Serial.println("normal temperature");
          Serial.println("초록 LED ON");
          lcd.clear();         
          lcd.print("Temperature");
          lcd.setCursor(4,1);
          lcd.print(strTemp);
          delay(500);
          lcd.clear(); 
          lcd.print("normal temperature");
          digitalWrite(ledg, HIGH); // 초록 LED ON
          delay(500);
          digitalWrite(ledg, LOW); // 초록 LED OFF
        }

        // 저체온일 때
        else if(strTemp < 34.9) {
          Serial.print("Temperature : ");
          Serial.println(strTemp); 
          Serial.println("low temperature");
          Serial.println("노랑 LED ON");
          lcd.clear();          
          lcd.print("Temperature");
          lcd.setCursor(4,1);
          lcd.print(strTemp); 
          delay(500);
          lcd.clear(); 
          lcd.print("low temperature");
          digitalWrite(ledy, HIGH); // 노랑 LED ON
          delay(500);
          digitalWrite(ledy, LOW); // 노랑 LED OFF
        }

        // 고체온일 때
        else if(strTemp > 37.6) { 
          Serial.print("Temperature : ");
          Serial.println(strTemp); 
          Serial.println("high temperature");           
          Serial.println("빨강 LED ON");
          Serial.println("buzzer ON");
          lcd.clear(); 
          lcd.print("Temperature");
          lcd.setCursor(4,1);
          lcd.print(strTemp); 
          delay(500);
          lcd.clear();
          lcd.print("high temperature");
          digitalWrite(ledr, HIGH); // 빨강 LED ON
          digitalWrite(buzzer, HIGH); // Buzzer ON
          delay(500);
          digitalWrite(ledr, LOW); // 빨강 LED OFF
          digitalWrite(buzzer, LOW); // Buzzer OFF
        }
      }
      delay(1000); // 1초 간격으로 측정
    }   
}

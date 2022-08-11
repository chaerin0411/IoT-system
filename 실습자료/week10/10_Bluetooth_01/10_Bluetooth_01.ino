#include <SoftwareSerial.h>

int bluetoothTx = 2;
int bluetoothRx = 3;
int LED = 9;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
    Serial.begin(9600); 
    delay(100);
    bluetooth.begin(9600);
    pinMode(LED, OUTPUT);
}

void loop()    {
    char cmd;
    if(bluetooth.available() )
    {
        cmd = (char)bluetooth.read();
        Serial.print("Command = ");
        Serial.println(cmd);

        if( cmd == '1' )
        {
            Serial.println("LED ON");
            digitalWrite(LED, HIGH);
        }
        if( cmd == '2' )
        {
            Serial.println("LED OFF");
            digitalWrite(LED, LOW);
        } 
    }
}

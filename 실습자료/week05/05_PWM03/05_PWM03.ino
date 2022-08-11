int speakerPin = 8;
int numTones = 6;
int tones[] {261, 294, 330, 349, 392, 440};
             // mid C D E F G A

void setup() {
}

void loop() {
  for(int i = 0; i < numTones; i++)
  {
    tone(speakerPin, tones[i]); 
    delay(500);
  }
  noTone(speakerPin);
  delay(1000);
}

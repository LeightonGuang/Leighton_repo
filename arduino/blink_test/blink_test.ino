//button will make an led flash 5 times 
int ledPin = 7;
int button = 2;

int blinkTime = 500;
int ButtonValue = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{
  ButtonValue = digitalRead(button);

  if(ButtonValue != 0)
  {
    blinkyBlinky(5, blinkTime);
  }
}

void blinkyBlinky(int repeats, int time)
{
  for (int i = 0; i < repeats; i++)
  {
    digitalWrite(ledPin, HIGH);
    delay(time);
    digitalWrite(ledPin, LOW);
    delay(time);
  }
}

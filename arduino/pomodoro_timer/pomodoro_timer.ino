//button will make an led flash 5 times 
const int button = 2;

const int redLed = 7;
const int greenLed = 8;

int blinkTime = 500;
int ButtonValue = 0;    

int pressLength = 0;    //record how long the button was held

int fastClick = 100;    //click to start
int hold = 3000;        //hold to reset timer

void setup()
{
  pinMode(button, INPUT_PULLUP);
  
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT); 

  //start serial communication for debugging
  Serial.begin(9600);
}

void loop()
{
  //for debugging
  while (digitalRead(button) == HIGH){
    if(pressLength % 1000 != 0 or pressLength == 0)
    {
      digitalWrite(redLed, LOW);
    }
    
    else if (pressLength % 1000 == 0)
    {
      digitalWrite(redLed, HIGH);
    }
    
  
    delay(100);
    pressLength = pressLength + 100;
    
    Serial.print("ms = ");
    Serial.println(pressLength);
  }
  
  if (pressLength >= hold)
  {
    resetFlash();
  }
  
  else if(pressLength >= fastClick)
  {
    flash(2, redLed);
  }

  pressLength = 0;
}

void flash(int repeats, int led)
{
  for (int i = 0; i < repeats; i++)
  {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }
}

void resetFlash()
{
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(redLed, HIGH);
    delay(50);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    delay(50);
    digitalWrite(greenLed, LOW);
  }

}

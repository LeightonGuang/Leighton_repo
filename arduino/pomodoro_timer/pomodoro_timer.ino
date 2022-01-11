//button will make an led flash 5 times
const int button = 2;

const int redLed = 7;
const int greenLed = 8;

int pressLength = 0;    //record how long the button was held

const int fastClick = 100;  //click to start
const int hold = 3000;        //hold to reset timer

const long workTime = 25 * 60 * 1000L;

bool work = true;
bool reset = false;

//setup
void setup()
{
  pinMode(button, INPUT_PULLUP);

  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  //start serial communication for debugging
  Serial.begin(9600);
}

//main loop--------------------------------------------------
void loop()
{
  digitalWrite(redLed, HIGH);
  buttonWait();
  if (work == true)
  {
    //25 minutes loop
    for (int i = 0; i < 5; i++)
    {
      flash(redLed);
      checkInput();

      if (pressLength >= 10)
      {
        buttonWait();
      }

      else if (pressLength >= 3000)
      {
        break;
      }
    }
    
    work = false;
    digitalWrite(greenLed, HIGH);
    buttonWait();
  }
  
  else if (work == false)   
  {
    //5 minutes loop
    for (int i = 0; i < 2; i++)
    {
      flash(greenLed);
      checkInput();
    }

    work = true;
  }
}
//-----------------------------------------------------------

//checks for what button combination is pressed
void checkInput()
{
  pressLength = 0;
  
  while (digitalRead(button) == HIGH)
  {
    if (pressLength % 1000 != 0 or pressLength == 0)
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
}

void flash(int led)
{
  Serial.println("flash led");
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
}

void resetFlash()
{
  Serial.println("reset");
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

void buttonWait()
{
  Serial.println("waiting for input");

  while (digitalRead(button) == LOW)
  {
    delay(10);
    Serial.println("pause");
    if (digitalRead(button) == HIGH)
    {
      Serial.println("unpause");
    }
  }
}

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
  if (work == true)   //work
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    buttonWait();       //press button to start work
    //25 minutes loop
    for (int i = 0; i < 5; i++)
    {
      flash(redLed);
      checkInput();
    }
    
    work = false;
  }
  
  else if (work == false)       //break
  {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    buttonWait();     //press button to start break
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
      digitalWrite(redLed, LOW);          //no flashing when it's not on the second
    }

    else if (pressLength % 1000 == 0)     //flashing every second when holding down the button
    {
      digitalWrite(redLed, HIGH);
    }
  
    delay(100);
    pressLength = pressLength + 100;

    Serial.print("ms = ");
    Serial.println(pressLength);
  }

  if (pressLength >= 3000)    //play reset flash when button is held for 3 seconds or more
  {
    resetFlash();
  }
}

void flash(int led)
{
  Serial.println("flash led");
  digitalWrite(led, LOW);
  delay(500);
  digitalWrite(led, HIGH);
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

void extra()
{
  if (pressLength >= 10)
      {
        buttonWait();
      }

      else if (pressLength >= 3000)
      {
       
      }
}

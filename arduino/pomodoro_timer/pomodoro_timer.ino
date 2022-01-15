//button will make an led flash 5 times
const byte button = 2;

const byte redLed = 7;
const byte greenLed = 8;

int pressLength = 0;    //record how long the button was held

const int fastClick = 100;  //click to start
const int hold = 3000;        //hold to reset timer

const long workTime = 25 * 60 * 1000L;

bool work = true;
bool processing = false;    //only run buttonWait when processing is true

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
    digitalWrite(redLed, HIGH);     //indicate its work mode
    digitalWrite(greenLed, LOW);    //clear any indication for break mode
    buttonWait();                   //press to start timer
    processing = true;              
    //25 minutes loop
    for (int i = 0; i < 5; i++)
    {
      checkHold();                  //check for any button input to stop or reset
      flash(redLed);                //led flashes every second
    }
    
    work = false;
    processing = false;
  }
  
  else if (work == false)       //break
  {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    buttonWait();     //press button to start break
    processing = true;
    //5 minutes loop
    for (int i = 0; i < 2; i++)
    {
      flash(greenLed);
      checkHold();
    }

    work = true;
    processing = false;
  }
}
//-----------------------------------------------------------

//checks for what button combination is pressed
void checkHold()
{
  pressLength = 0;
  
  while (digitalRead(button) == HIGH)
  {
    digitalWrite(greenLed, HIGH);   //to indicate button was pressed
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

  digitalWrite(greenLed, LOW);
  pauseLogic();
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
  Serial.println("click to unpause");
  while (digitalRead(button) == LOW)
  {
    delay(10);
    Serial.println("pause");
    if (digitalRead(button) == HIGH && pressLength >= 100)
    {
      Serial.println("unpause");
    }
  }
}

void pauseLogic()     //logic for what combination was held
{
  if (pressLength >= 3000)    //play reset flash when button is held for 3 seconds or more
  {
    resetFlash();
    asm volatile ("jmp 0");
  }
  
  else if (pressLength >= 100 && processing == true)
  {
    buttonWait();
  }
}

void extra()
{
  
}

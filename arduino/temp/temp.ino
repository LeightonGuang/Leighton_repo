const byte button = 2;

const byte redLed = 7;
const byte greenLed = 8;

const long workTime = 5 * 1000L;
const long breakTime = 2 * 1000L;

unsigned long timeCounter = 0;
const int timeInterval = 500;

unsigned long currentHoldTime = 0;
unsigned long previousTime = 0;
unsigned long previousHold = 0;

bool processing = false;
bool work = true;
bool activeHold = false;

int redState = LOW;
int greenState = LOW;

void setup() 
{
  pinMode(button, INPUT_PULLUP);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Pomodoro timer");
}

void loop() 
{
  keyPress();   //detect what kind of input is pressed
  
  if (work == true && processing == true)
  {
    unsigned long redCurrentTime = millis();     //this keeps getting bigger
  
    if (redCurrentTime - previousTime >= timeInterval)
    {
      previousTime = redCurrentTime;     //save the last currentTime to previousTime
      if (redState == LOW)
      {
        Serial.println("red on");
        redState = HIGH;
      }
  
      else if (redState == HIGH)
      {
        Serial.println("red off");
        redState = LOW;
        timeCounter++;
        Serial.print("sec: ");
        Serial.println(timeCounter);
      }
      digitalWrite(redLed, redState);
    }
  }

  else if (work == false && processing == true)
  {
    unsigned long greenCurrentTime = millis();     //this keeps getting bigger
  
    if (greenCurrentTime - previousTime >= timeInterval)
    {
      previousTime = greenCurrentTime;     //save the last currentTime to previousTime
      if (greenState == LOW)
      {
        Serial.println("green on");
        greenState = HIGH;
      }
  
      else if (greenState == HIGH)
      {
        Serial.println("green off");
        greenState = LOW;
        
      }
      digitalWrite(greenLed, greenState);
    }
  }

  if (work == true && timeCounter == 5)
  {
    work = false;
    processing = false;
    timeCounter = 0;
  }
}

void keyPress()
{
  while (digitalRead(button) == HIGH)
  {
    if (currentHoldTime % 1000 != 0 or currentHoldTime == 0)
    {
      digitalWrite(greenLed, LOW);          //no flashing when it's not on the second
    }

    else if (currentHoldTime % 1000 == 0)     //flashing every second when holding down the button
    {
      digitalWrite(greenLed, HIGH);
    }
    delay(100);
    currentHoldTime += 100;
  }

  if (digitalRead(button) == LOW && (currentHoldTime >= 3000))      //reset
  { 
    Serial.println("reset");
    Serial.println("processing: false");
    processing = false;
    previousHold = currentHoldTime;
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    resetFlash();
    currentHoldTime = 0;
    timeCounter = 0;
    work = true;
  }

  else if (digitalRead(button) == LOW && (currentHoldTime >= 100))      //click
  {
    if (processing == true)
    {
      Serial.println("processing: false");
      processing = false;
    }
    else if (processing == false)
    {
      Serial.println("processing: true");
      processing = true;
    }
    previousHold = currentHoldTime;
    digitalWrite(greenLed, LOW);
    currentHoldTime = 0;
  }
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

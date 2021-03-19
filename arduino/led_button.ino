const int buttonPin = 15;
const int LED = 10;

int buttonState = 0;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop(){
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
   digitalWrite(LED, HIGH);
   
  } else {
   digitalWrite(LED, LOW);
  }
}

int pwmSignPin = 0;
int ledBoardPin = 12;
int target = 0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(ledBoardPin, OUTPUT);
  digitalWrite(ledBoardPin, LOW);
  pinMode(pwmSignPin, OUTPUT);

  Serial.begin(115200);
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.printf("I am in the loop!\n");
  if (target <= 255)
  {
    target += 50;
  }
  else
  {
    target = 0;
  }
  constrain(target, 0, 255);
  analogWrite(pwmSignPin, target);

  digitalWrite(ledBoardPin, !(digitalRead(ledBoardPin)));
  delay(1000);
}

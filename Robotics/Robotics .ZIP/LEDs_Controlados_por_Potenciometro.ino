int pot = 0; 
int led = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int pin_buzzer = 5;

void setup()
{
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(pin_buzzer, OUTPUT);
  Serial.begin(9600); 
}

void loop()
{
  pot = analogRead(A0); 
  pot = map(pot, 0, 1023, 0, 100);
  if (pot <= 0 && pot <= 15)
  {
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
  }
 
  
     else if (pot >= 16 && pot <= 30)
    {
   digitalWrite (led, HIGH);
   digitalWrite (led2, HIGH);
   digitalWrite (led3, HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,HIGH);
    }
    else if (pot >= 31 && pot <= 45)
    {
   digitalWrite (led2, HIGH);
   digitalWrite (led, HIGH);
   digitalWrite (led3, LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
    }
   else if (pot >= 46 && pot <= 60)
   {
    digitalWrite (led3, HIGH);
    digitalWrite (led, HIGH);
    digitalWrite (led2, HIGH);
     digitalWrite(led4,LOW);
     digitalWrite(led5,LOW);
   }
    else if(pot >= 61 && pot <= 75)
    {
      digitalWrite(led,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,LOW);
    }
    else if(pot >= 76 && pot <= 100)
    {  
      digitalWrite(led,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,HIGH);
    }
      
  Serial.println(pot);
  delay(1) ;  
  } 

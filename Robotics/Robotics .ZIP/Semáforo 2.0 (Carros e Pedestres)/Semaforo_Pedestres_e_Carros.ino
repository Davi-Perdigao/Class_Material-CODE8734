 int chave = 2;
 int val = 0;
 int led1 = 8;
 int led2 = 9;
 int led3 = 10;
 int led4 = 11;
 int led5 = 12;

void setup(){
  Serial.begin(9600);
  pinMode(chave,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
}

void loop(){
  val = digitalRead(chave);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  if (val == HIGH){
    delay(4000);
    digitalWrite(led3,LOW);
    digitalWrite(led2,HIGH);
    delay(2000);
    digitalWrite(led2,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led1,HIGH);
    digitalWrite(led5,HIGH);
    delay(8000);
    digitalWrite(led5,LOW);
    digitalWrite(led4,HIGH);
    delay(400);
    digitalWrite(led4,LOW);
    delay(400);
    digitalWrite(led4,HIGH);
    delay(400);
    digitalWrite(led4,LOW);
    delay(400);
    digitalWrite(led4,HIGH);
    delay(200);
    digitalWrite(led1,LOW); 
  } else {
  }
}

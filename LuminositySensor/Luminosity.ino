unsigned long tempo;
double alcance;
int buzzer = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  pinMode(9,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop()
{ 
  digitalWrite(13,HIGH);
  delayMicroseconds(5);
  digitalWrite(13, LOW);
  
  double duracao = pulseIn(12, HIGH);
  alcance = duracao/58;
   Serial.println(duracao);
  delay(500);
  
  if(alcance > 200.00)
  {
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(5, LOW);
    noTone(buzzer);
  }
  
  else if(alcance > 100.00)
  {
    digitalWrite(9, LOW);
    delay(500);
    digitalWrite(5, HIGH);
    noTone(buzzer);
  }
  else if(alcance < 100.00)
  {
    digitalWrite(buzzer, HIGH);
  }
  
}

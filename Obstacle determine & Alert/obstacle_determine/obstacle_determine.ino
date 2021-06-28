int buzzer = 13;
int trigpin = A0;
int echopin = A1;
float distance;
float duration;

void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigpin,LOW);
  delay(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin,HIGH);
  distance = (duration*0.034)/2;
  Serial.println("The Distance is: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println("");
  delay(500);

  if(distance<30)
  {
    digitalWrite(buzzer,HIGH);
    Serial.println("Warning!! The obstacle is so close!");
  }
  else{
    digitalWrite(buzzer,LOW);
  }
}

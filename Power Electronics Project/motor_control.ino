int Q1=13;
int Q2=12;
int Q3=11;
int Q4=10;

void setup() {
  // put your setup code here, to run once:
  pinMode(Q1,OUTPUT);
  pinMode(Q2,OUTPUT);
  pinMode(Q3,OUTPUT);
  pinMode(Q4,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Q1,HIGH);
  digitalWrite(Q4,HIGH);
  digitalWrite(Q3,LOW);
  digitalWrite(Q2,LOW);
  delay(5000);
  digitalWrite(Q3,HIGH);
  digitalWrite(Q2,HIGH);
  digitalWrite(Q4,LOW);
  digitalWrite(Q1,LOW);
  delay(5000);
}

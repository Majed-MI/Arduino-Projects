int red = 11;
int green = 12;
int blue = 13;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  Serial.begin(9600);
}

void loop() {
   digitalWrite(red,HIGH);
   digitalWrite(green,LOW);
   digitalWrite(blue,LOW); 
   Serial.println("Light Mode: Red");
   delay(2000);
   digitalWrite(red,LOW);
   digitalWrite(green,HIGH);
   digitalWrite(blue,LOW); 
   Serial.println("Light Mode: Green");
   delay(2000);
   digitalWrite(red,LOW);
   digitalWrite(green,LOW);
   digitalWrite(blue,HIGH); 
   Serial.println("Light Mode: Blue");
   delay(2000);
             
}

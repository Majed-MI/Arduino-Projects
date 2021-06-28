int red = 11;
int i;

void setup() {
  pinMode(red, OUTPUT);
}
//LOW
void loop() {
   for(i=0;i<=255;i=i+5)
   {
    analogWrite(red,i);
    delay(60);
   }
   for(i=255;i>0;i=i-5)
   {
    analogWrite(red,i);
    delay(60);
   }
}

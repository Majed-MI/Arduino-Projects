int red = 11;
int green = 12;
int blue = 13;
char sms;

void setup(){
    Serial.begin(9600);
    pinMode(red,OUTPUT);
    pinMode(green,OUTPUT);
    pinMode(blue,OUTPUT);
}

void loop(){
    if(Serial.available()!=0)
    {
       sms = Serial.read();
    }
    if(sms == '1')
    {
       digitalWrite(red,HIGH)
    }
    if(sms == '2')
    {
       digitalWrite(red,LOW)
    }
    if(sms == '3')
    {
       digitalWrite(green,HIGH)
    }
    if(sms == '4')
    {
       digitalWrite(green,LOW)
    }
    if(sms == '5')
    {
       digitalWrite(blue,HIGH)
    }
    if(sms == '6')
    {
       digitalWrite(blue,LOW)
    }
}
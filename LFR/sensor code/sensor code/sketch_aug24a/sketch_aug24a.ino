int s1, s2, s3, s4, s5, s6;
int reading;
void setup() {
  Serial.begin(9600);

}

void loop() {
  sensor(); //ctrl+shift+n to create a new tab
  show();
  //  if(reading == 0b001100) go();
  //  if(reading == 0b111100) left(); // these are demo moves to give you a slight idea how we are going to follow line.
}

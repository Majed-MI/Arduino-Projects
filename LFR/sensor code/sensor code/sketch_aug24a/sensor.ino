void sensor() {
  s1 = analogRead(0); //storing analog values of each sensors
  s2 = analogRead(1);
  s3 = analogRead(2);
  s4 = analogRead(3);
  s5 = analogRead(4);
  s6 = analogRead(5);

//  if (s1 > 300) s1 = 1;  //digital converting code
//  else s1 = 0;
//  if (s2 > 300) s2 = 1;
//  else s2 = 0;
//  if (s3 > 300) s3 = 1;
//  else s3 = 0;
//  if (s4 > 300) s4 = 1;
//  else s4 = 0;
//  if (s5 > 300) s5 = 1;
//  else s5 = 0;
//  if (s6 > 300) s6 = 1;
//  else s6 = 0;

  reading = s1 * 1 + s2 * 2 + s3 * 4 + s4 * 8 + s5 * 16 + s6 * 32; //we are combining all the sensor values assuming they are giving binary output
}


void show() {
  Serial.print(s6);
  Serial.print(" ");
  Serial.print(s5);
  Serial.print(" ");
  Serial.print(s4);
  Serial.print(" ");
  Serial.print(s3);
  Serial.print(" ");
  Serial.print(s2);
  Serial.print(" ");
  Serial.print(s1);
  Serial.print(" ");
  Serial.print(reading);
  Serial.print(" ");
  Serial.println(reading, BIN); //this time we will see value of variable 'reading'....but in binary format
}

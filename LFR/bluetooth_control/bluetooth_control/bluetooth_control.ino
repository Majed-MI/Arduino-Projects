#define left_motor_forward 3
#define left_motor_backward 4
#define right_motor_forward 7
#define right_motor_backward 8
#define left_motor_speed 5
#define right_motor_speed 6
#define head_light 13
char x;
int spd = 250;
void setup() {
  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(left_motor_speed, OUTPUT);
  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_speed, OUTPUT);
  pinMode(head_light, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    x = Serial.read();
    Serial.println(x);
    if ( x == 'F') motor(spd, spd);
    else if ( x == 'L') motor(-spd, spd);
    else if ( x == 'R') motor(spd, -spd);
    else if ( x == 'G') motor(0, spd);
    else if ( x == 'I') motor(spd, 0);
    else if ( x == 'H') motor(0, -spd);
    else if ( x == 'J') motor(-spd, 0);
    else if ( x == 'B') motor(-spd,-spd);
    else if ( x == 'S') motor(0,0);
    else if ( x == 'U') digitalWrite(head_light, HIGH);
    else if ( x == 'u') digitalWrite(head_light, LOW);
    else if ( x == '0') spd = 0;
    else if ( x == '1') spd = 25;
    else if ( x == '2') spd = 50;
    else if ( x == '3') spd = 75;
    else if ( x == '4') spd = 100;
    else if ( x == '5') spd = 125;
    else if ( x == '6') spd = 150;
    else if ( x == '7') spd = 175;
    else if ( x == '8') spd = 200;
    else if ( x == '9') spd = 225;
    else if ( x == 'q') spd = 250;  
  }
}

#define left_motor_forward 4
#define left_motor_backward 3
#define right_motor_forward 8
#define right_motor_backward 7
#define left_motor_speed 5
#define right_motor_speed 6
#define head_light 13
#define spl 13 //left motor speed coeficient
#define spr 13 //right motor speed coeficient
char flag = 's';


int s[6]; //this is for storing analog value of each sensor
int thresould[] = {100,100,100,100,100,100}; //this is the mid value for each sensor. use this array if you want to adjust midoint of each sensor individually
int base[6] = {1, 2, 4, 8, 16, 32}; //this is for binary to decimal conversion
int sensor; //this is to store final value after binary conversion
int sum = 0; //this is to store the count of detected sensor

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
  //  bluetooth(); //uncomment this if you want to use it as a rc car. comment this if you want to folow the line
  line_follow(); // comment this if you want to test sensor value or want to use robot a rc car
//    show_the_value(); // only uncomment this if you need to test sensor value in serial monitor
//    motor(10 * spl, 10 * spr);  //only uncomment this when you need to test if robot is moving forward
}

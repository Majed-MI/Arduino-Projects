void line_follow() {
  while (1) { //infinite loop
    reading();
    if (sum == 0) {
      if (flag != 's') {
        motor(10 * spl, 10 * spr);
        delay(30); //time given to move robot forward for a certain time to adjust itself in 90 degree line to have a perfect turn
        if (flag == 'l') {
          motor(-6 * spl, 6 * spr);
          while (s[2] == 0 && s[3] == 0) reading(); //robot will continue turning untill any of two middle ir sensors find black line
        }
        else if (flag == 'r') {
          motor(6 * spl, -6 * spr);
          while (s[2] == 0 && s[3] == 0) reading();
        }
        flag = 's'; //when you are done turning robot, make the flag to its normal state so that robot wont turn on its own when it finds no line without detecting 90degree logic
      }
    }
    else if (sum == 1 || sum == 2) {  //only for straight line
      if (sensor == 0b001100) motor(10 * spl, 10 * spr);
      //right side portion
      else if (sensor == 0b000100) motor(9 * spl, 10 * spr);
      else if (sensor == 0b000110) motor(6 * spl, 10 * spr);
      else if (sensor == 0b000010) motor(3 * spl, 10 * spr);
      else if (sensor == 0b000011) motor(0 * spl, 10 * spr);
      else if (sensor == 0b000001) motor(-3 * spl, 10 * spr);
      //left side portion
      else if (sensor == 0b001000) motor(10 * spl, 9 * spr);
      else if (sensor == 0b011000) motor(10 * spl, 6 * spr);
      else if (sensor == 0b010000) motor(10 * spl, 3 * spr);
      else if (sensor == 0b110000) motor(10 * spl, 0 * spr);
      else if (sensor == 0b100000) motor(10 * spl, -3 * spr);
    }

    else if (sum == 3 || sum == 4 || sum == 5) { //only for sharp turn logic
      if (sensor == 0b111100 || sensor == 0b111000 || sensor == 0b111110) flag = 'r';
      else if (sensor == 0b001111 || sensor == 0b000111 || sensor == 0b011111) flag = 'l';
    }
  }
}

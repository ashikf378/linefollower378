int line_follow() { 
  

    reading();
    if (sum == 0) {
    
      if (flag != 's') {
        if (flag != 't') {//we already moved a little forward when sensor was on 'T' section...no need to move forward further!
          motor(120,120);
          delay(12); //time given to move robot forward for a certain amount of time to adjust itself in 90 degree line.
        }
        if (flag == 'l') {
          motor(120, -120);
          while (s[2] == 0 && s[3] == 0) reading();

        }
        else if (flag == 'r') {
          motor(-120, 120);

          while (s[2] == 0 && s[3] == 0) reading();
        }
        else if (flag == 't') {
          motor(120, -120); //make your choice if you want to go left or right in T section

        while (s[2] == 0 && s[3] == 0) reading();
        }
        flag = 's'; //when you are done turning robot, make the flag to its normal state so that robot wont turn on its own when it finds no line without detecting 90degree logic
      }
    }
    
    
     //only for straight line
    
    else if (sum == 1 || sum == 2) { 
    if (sensor == 0b001100) { error = 0;}
  else if (sensor == 0b000100) {  error = 1;}
  else if (sensor == 0b000110) {  error = 2;}
  else if (sensor == 0b000010) {  error = 3;}
  else if (sensor == 0b000011) {  error = 4;}
  else if (sensor == 0b000001) {  error = 5;}
  else if (sensor == 0b001000) {  error = -1;}
  else if (sensor == 0b011000) {  error = -2;}
  else if (sensor == 0b010000) { error = -3;}
  else if (sensor == 0b110000) {  error = -4;}
  else if (sensor == 0b100000) {  error = -5 ;}
 }
  else if ((sum == 3 || sum == 4 || sum == 5) && flag != 't') {
       if (sensor == 0b101100 || sensor == 0b100110 || sensor == 0b110100) flag = 'l';
      else if (sensor == 0b001101 || sensor == 0b011001 || sensor == 0b001011) flag = 'r';
      else if (sensor == 0b111100 || sensor == 0b111000 || sensor == 0b111110) flag = 'l';
      else if (sensor == 0b001111 || sensor == 0b000111 || sensor == 0b011111) flag = 'r';
   }

    else if (sum == 6) {
      delay(100);
      reading();
      if  (sum == 6) { //stop point detection
        motor(0, 0);
        while  (sum == 6) reading();
        delay(1000);
      }
      else if  (sum == 0) flag = 't';
      else flag = 's'; //if the robot detects straight line going a bit forward, no need to keep previous flag value. it should just keep moving forward
    }
  
  return error;

}

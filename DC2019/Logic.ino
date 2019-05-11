int effA;
int effB;
int callibration_pin = 13;
uint16_t ii = 0;

float bottom_left_x;
float bottom_left_y;
float bottom_right_x;
float bottom_right_y;
float top_left_x;
float top_left_y;
float top_right_x;
float top_right_y;

void process_command(char * c){
  Serial.println(c);
  if (c[0] == 'd'){
    /*Reverse commands of form "d r a/b"*/
    if (c[1] == 'r'){
      if(c[2] == 'a'){
        reverse_motor('a');
        Serial.println("reversing motor A");
      } else {
        reverse_motor('b');
        Serial.println("reversing motor B");
      }
    } 
    /*Motor effort commands of form "d motorAeff motorBeff"*/
    Serial.println((c+1));
    sscanf((c + 1), "%d %d", &effA, &effB);
    //memset(c, 0, sizeof(c));
    Serial.println(effA);
    Serial.println(effB);
    drive_motors(effA, effB);
  } else if (c[0] == 'b'){
    send_vive_info();
  }else if (c[0] == 'a'){
    digitalWrite(13, HIGH);
    Serial.println("suhhhhh");
    BT_write('q', ++ii); 
  } else if (c[0] == 'v'){
    Serial.println("Entering Vive Calibration Mode");
    Serial.println("Move to Bottom Left!");
    while(digitalRead(callibration_pin)){
      checkVive();
      bottom_left_x = (get_xpos1() + get_xpos2())/2;
      bottom_left_y = (get_ypos1() + get_ypos2())/2;
    } 
    Serial.println("Move to Bottom Right!");
    while(digitalRead(callibration_pin)){
      checkVive();
      bottom_right_x = (get_xpos1() + get_xpos2())/2;
      bottom_right_y = (get_ypos1() + get_ypos2())/2;
    } 
    Serial.println("Move to Top Right!");
    while(digitalRead(callibration_pin)){
      checkVive();
      top_right_x = (get_xpos1() + get_xpos2())/2;
      top_right_y = (get_ypos1() + get_ypos2())/2;
    }
    Serial.println("Move to Top Left!");
    while(digitalRead(callibration_pin)){
      checkVive();
      top_left_x = (get_xpos1() + get_xpos2())/2;
      top_left_y = (get_ypos1() + get_ypos2())/2;
    }
    Serial.println("Calibration complete!");
    BT_write_vive_calibrate(bottom_left_x, bottom_left_y, bottom_right_x, bottom_right_y, top_right_x, top_right_y, top_left_x, top_left_y);  
  }else {
    //digitalWrite(13, LOW);
  }
  return;
}
  

int effA;
int effB;
void process_command(char * c){
  Serial.println(read_char[0]);
  
  if (read_char[0] == 'd'){
    /*Reverse commands of form "d r a/b"*/
    if (read_char[1] == 'r'){
      if(read_char[2] == 'a'){
        reverse_motor('a');
        Serial.println("reversing motor A");
      } else {
        reverse_motor('b');
        Serial.println("reversing motor B");
      }
    }
    /*Motor effort commands of form "d motorAeff motorBeff"*/
    sscanf((read_char + 1), "%d %d", &effA, &effB);
    Serial.println(effA);
    Serial.println(effB);
    drive_motors(effA, effB);
    
  } else if (read_char[0] = 'a'){
    digitalWrite(13, HIGH);
    Serial.println("suhhhhh");
  } else {
    //digitalWrite(13, LOW);
  }
}


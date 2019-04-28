void process_command(char * c){
  Serial.println(read_char[0]);
  if (read_char[0] == 'd'){
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



void BT_setup(){
  SerialBT.begin("ScooshBT2"); //Bluetooth device name
  return;
}

void BT_write(char flag, uint16_t info){
  Serial.print(flag);
  Serial.print(' ');
  Serial.println(info);
  
  SerialBT.print(flag);
  SerialBT.print(' ');
  SerialBT.println(info);
  return;
}

void BT_write_vive(float xpos1, float ypos1, float xpos2, float ypos2){
  SerialBT.print('v');
  SerialBT.print(' ');
  SerialBT.print((int)(floor(xpos1* 100)));
  SerialBT.print(' ');
  SerialBT.print(((int)(floor(ypos1* 100))));
  SerialBT.print(' ');
  SerialBT.print(((int)(floor(xpos2* 100))));
  SerialBT.print(' ');
  SerialBT.println(((int)(floor(ypos2* 100))));
  return;
}

void BT_write_vive_calibrate(float bl_x, float bl_y, float br_x, float br_y, float tr_x, float tr_y, float tl_x, float tl_y ){
  SerialBT.print('c');
  SerialBT.print(' ');
  SerialBT.print(bl_x);
  SerialBT.print(' ');
  SerialBT.print(bl_y);
  SerialBT.print(' ');
  SerialBT.print(br_x);
  SerialBT.print(' ');
  SerialBT.print(br_y);
  SerialBT.print(' ');
  SerialBT.print(tr_x);
  SerialBT.print(' ');
  SerialBT.print(tr_y);
  SerialBT.print(' ');
  SerialBT.print(tl_x);
  SerialBT.print(' ');
  SerialBT.println(tl_y);
  return;
}
void BT_read(char * c){
  static int i = 0;
  while (SerialBT.available()){
    c[i] = SerialBT.read();
    Serial.println(c[i]);
    if (c[i++] == '\n'){
      Serial.print("Final I value: ");
      Serial.println(i);
      i = 0;

    }
  }
  Serial.print(c);
  
  //sscanf(c, "%d %d", effA, effB);
  
  return;
}


void BT_setup(){
  SerialBT.begin("ScooshBT"); //Bluetooth device name
  return;
}

void BT_write(int data){

}

void BT_read(char * c){
  int i = 0;
  while (SerialBT.available()){
    c[i++] = SerialBT.read();
    //Serial.print(c[i++]);
  }
  //Serial.print(c);
  //sscanf(c, "%d %d", effA, effB);
  
  return;
}




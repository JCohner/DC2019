#include "BluetoothSerial.h"
#include <stdio.h>

char read_char[50];
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
void setup() {
  Serial.begin(115200);
  BT_setup();
  drive_setup();
  
  
}

void loop() {
 if (SerialBT.available()){
  memset(read_char, ' ', sizeof(read_char)); 
  BT_read(read_char);
  process_command(read_char);
 }

 /*Once per loop send info back to PyGame*/
 //send_data(); 
}

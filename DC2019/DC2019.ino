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

int effA;
int effB;

void loop() {
 if (SerialBT.available()){
  memset(read_char, ' ', sizeof(read_char)); 
  BT_read(read_char);
  process_command(read_char);
  
 }
  

  
  /*
  
  Serial.print("motor A eff: ");r
  Serial.println(effA);
  Serial.print("motor B eff: ");
  Serial.println(effB);*/
  
  /*
  switch(read_char){
    case 'd':
      
      break;
    case 'x':
      
      break;
    case 'r':
      
      break;
    case 'c':
      
      break;  
  }
  */
  
}

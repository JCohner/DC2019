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

#include "BluetoothSerial.h"
#include <stdio.h>
#include <Wire.h>
#include <VL53L1X.h>
char read_char[50];


BluetoothSerial SerialBT;
VL53L1X laser_sensor_0;
VL53L1X laser_sensor_1;
void setup() {
  Serial.begin(115200);
  BT_setup();
  drive_setup();
  sensor_setup();
  
}

void loop() {
 if (SerialBT.available()){
  //Serial.println("got a read guy");
  memset(read_char, ' ', sizeof(read_char)); 
  BT_read(read_char);
  process_command(read_char);
  laser_sensor_0.writeReg(VL53L1X::SOFT_RESET, 0x00);
 }
 
 
 if (laser_sensor_0.dataReady()){
  Serial.println("data ready fam!");
  laser_distance_read();
  BT_write(get_laser_data_0());
  //BT_write(get_laser_data_1());
 } 
 
 //delay(20);
}

#include "BluetoothSerial.h"
#include <stdio.h>
#include <Wire.h>
#include <VL53L1X.h>
char read_char[50];
int count = 0;

BluetoothSerial SerialBT;
VL53L1X laser_sensor_0;

void setup() {
  Serial.begin(115200);
  BT_setup();
  drive_setup();
  //sensor_setup();
  vive_setup(); 
}

void loop() {
 if (SerialBT.available()){
  Serial.println("got a read guy");
  memset(read_char, 0, sizeof(read_char)); 
  BT_read(read_char);
  process_command(read_char);
 }
  
  delay(10);
 /*
 if (laser_sensor_0.dataReady()){ //never evaluates to true after BT_read attempt to bypass function
  counter = 0;
  Serial.println("reading range data");
  range_data = laser_sensor_0.ranging_data.range_mm;
  laser_distance_read();
  BT_write('l' , get_laser_data_0());
  //BT_write(get_laser_data_1());
 } */
 //delay(20);
}

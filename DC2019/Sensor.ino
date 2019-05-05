uint16_t laser_data_0;
uint16_t laser_data_1;
void sensor_setup(){
  //pinMode(xshut_laser_sensor_0, OUTPUT);
  //pinMode(xshut_laser_sensor_1, OUTPUT);
  
  Wire.begin(); //join i2c bus as master
  Wire.setClock(400000); // use 400 kHz I2C

  //digitalWrite(xshut_laser_sensor_0, LOW);
  //laser_sensor_1.setAddress(1);
  //digitalWrite(xshut_laser_sensor_0, HIGH);
  //digitalWrite(xshut_laser_sensor_1, LOW);
  //laser_sensor_0.setAddress(0);

  laser_sensor_0.setTimeout(0);
  //laser_sensor_1.setTimeout(0);
  if(!laser_sensor_0.init())
  {
    Serial.println("Failed to detect and initialize sensor0!");
    while(1);
  }
  //digitalWrite(xshut_laser_sensor_1, HIGH);
  /*
  if (!laser_sensor_1.init())
  {
    Serial.println("Failed to detect and initialize sensor1!");
    while(1);
  }*/
  laser_sensor_0.setDistanceMode(VL53L1X::Long);
  laser_sensor_0.setMeasurementTimingBudget(100000);
  //laser_sensor_1.setDistanceMode(VL53L1X::Long);
  //laser_sensor_1.setMeasurementTimingBudget(100000);

  laser_sensor_0.startContinuous(100);
  //laser_sensor_1.startContinuous(100);
  return;
}

void laser_distance_read(){
  uint16_t laser_dist_0 = 0;
  //uint16_t laser_dist_1 = 0;
  //Serial.println("called laser read!");
  laser_dist_0 = laser_sensor_0.read(); //isnt returning new data dcx
  if(laser_dist_0 != 0){
    laser_data_0= laser_dist_0;
    //Serial.println(laser_dist);
  }
  /*
  laser_dist_1 = laser_sensor_1.read(); //isnt returning new data dcx
  if(laser_dist_1 != 0){
    laser_data_1= laser_dist_1;
    //Serial.println(laser_dist);
  }*/


  return;
  /* LASER DEBUG
  Serial.print("range: ");
  Serial.print(laser_sensor_0.ranging_data.range_mm);
  Serial.print("\tstatus: ");
  Serial.print(VL53L1X::rangeStatusToString(laser_sensor_0.ranging_data.range_status));
  Serial.print("\tpeak signal: ");
  Serial.print(laser_sensor_0.ranging_data.peak_signal_count_rate_MCPS);
  Serial.print("\tambient: ");
  Serial.print(laser_sensor_0.ranging_data.ambient_count_rate_MCPS);
  */
}

uint16_t get_laser_data_0(){
  return laser_data_0;
}
/*
uint16_t get_laser_data_1(){
  return laser_data_1;
}*/

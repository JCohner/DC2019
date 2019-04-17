#include "BluetoothSerial.h"
#include <stdio.h>
#include <math.h>

BluetoothSerial SerialBT;

//Drive Pin Declaration & definition
int drive_motor_A_pwm_pin = A5;
int drive_motor_B_pwm_pin = A1;

int drive_motor_A_dir_pin = 14;
int drive_motor_B_dir_pin = 32;

const int PWMAchannel = 1;
const int PWMBchannel = 0; //is this a valid num
int count = 0;
int motorAeff = 0;
int motorBeff = 0;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32Josh"); //Bluetooth device name
  //Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);

  //Drive Pins
  ledcSetup(PWMAchannel,5000,8); // pwm channel, frequency, resolution in bits
  ledcAttachPin(drive_motor_A_pwm_pin,PWMAchannel); // pin, pwm channel
  ledcSetup(PWMBchannel,5000,8); // pwm channel, frequency, resolution in bits
  ledcAttachPin(drive_motor_B_pwm_pin,PWMBchannel); // pin, pwm channel

  pinMode(drive_motor_A_dir_pin, OUTPUT);
  pinMode(drive_motor_B_dir_pin, OUTPUT);
  digitalWrite(drive_motor_A_dir_pin, LOW);
  digitalWrite(drive_motor_B_dir_pin, LOW);
}

void loop() {
  ledcWrite(PWMAchannel,motorAeff);
  ledcWrite(PWMBchannel,motorBeff);

  
  char c = 0;
  int an = 0;
  int i;
  
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    //Serial.write(SerialBT.read());
    c = SerialBT.read();
    Serial.println(c);
    if(c == 'o'){
      digitalWrite(13,HIGH);
    }
    else if (c == 'p'){
      digitalWrite(13,LOW);
    }
    else if (c == 'a'){
      an = analogRead(A2);
      SerialBT.print("a ");
      SerialBT.println(an);
    }
    else if (c == 'x'){
      Serial.println("gotta - goodbye!");
      /*
      count = count + 1;
      for (i=0; i<100; i++){
        SerialBT.print("x ");
        SerialBT.print(i);
        SerialBT.print(" ");
        SerialBT.println(int(50*sin(2*3.14/50*i+count)));
      }*/
      
    }
    else if (c == 'c'){
      SerialBT.println("c 1");
      Serial.println("gotta c turning motor ON!");
      motorAeff = 255;
    } else if (c == 'd'){
      Serial.println("gotta c turning motor OFF!");
      motorAeff = 0;
    }
  }
  delay(20);
  
}

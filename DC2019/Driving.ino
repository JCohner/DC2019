//Drive Pin Declaration & definition
#include <math.h>
int drive_motor_A_pwm_pin = A5; //was a5
int drive_motor_B_pwm_pin = A1; //was a1, tried a0

int drive_motor_A_dir_pin = 14;
int drive_motor_B_dir_pin = 32;

float motorAeff = 0;
float motorBeff = 0;
int motorAdir = 0; // 0 = CW 1 = CCW
int motorBdir = 0; 

const int PWMAchannel = 4;
const int PWMBchannel = 5;
void drive_setup(){
  //Drive Pins
  ledcSetup(PWMAchannel,5000,8); // pwm channel, frequency, resolution in bits
  ledcAttachPin(drive_motor_A_pwm_pin,PWMAchannel); // pin, pwm channel
  ledcSetup(PWMBchannel,5000,8); // pwm channel, frequency, resolution in bits
  ledcAttachPin(drive_motor_B_pwm_pin,PWMBchannel); // pin, pwm channel
  
  pinMode(drive_motor_A_dir_pin, OUTPUT);
  pinMode(drive_motor_B_dir_pin, OUTPUT);
  digitalWrite(drive_motor_A_dir_pin, motorAdir);
  digitalWrite(drive_motor_B_dir_pin, motorBdir);
  ledcWrite(PWMAchannel,0); 
  ledcWrite(PWMBchannel,0);
}

void drive_motors(int VRx, int VRy){
  
  if (VRy > 127){
    motorAdir = 1;
    digitalWrite(drive_motor_A_dir_pin, motorAdir);
    motorBdir = 1;
    digitalWrite(drive_motor_B_dir_pin, motorBdir);
    
    motorBeff = VRy * (255.0 - VRx)/255.0;
    motorAeff = VRy * ((float)VRx/255.0);
    ledcWrite(PWMAchannel,(int)motorAeff); 
    ledcWrite(PWMBchannel,(int)motorBeff); 
  } else {
    motorAdir = 0;
    digitalWrite(drive_motor_A_dir_pin, motorAdir);
    motorBdir = 0;
    digitalWrite(drive_motor_B_dir_pin, motorBdir);
    motorBeff = abs(VRy - 127)* 2 * (255.0 - VRx)/255.0;
    motorAeff = abs(VRy - 127) * 2 *((float)VRx/255.0);
    ledcWrite(PWMAchannel,motorAeff); 
    ledcWrite(PWMBchannel,motorBeff); 
  }
  
  //Serial.println("hi josh, youre cool!");
  
  /*gonna see if this command is what breaks two way com*/
  

  return;
  
}

void reverse_motor(char motor){
  if (motor == 'a'){ 
    motorAdir = !motorAdir;
    digitalWrite(drive_motor_A_dir_pin, motorAdir); 
  } else {
    motorBdir = !motorBdir;
    digitalWrite(drive_motor_B_dir_pin, motorBdir); 
  }
}

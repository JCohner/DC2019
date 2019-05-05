
//Drive Pin Declaration & definition
int drive_motor_A_pwm_pin = A5;
int drive_motor_B_pwm_pin = A1;

int drive_motor_A_dir_pin = 14;
int drive_motor_B_dir_pin = 32;

int motorAeff = 0;
int motorBeff = 0;
int motorAdir = 0; // 0 = CW 1 = CCW
int motorBdir = 0; 

const int PWMAchannel = 1;
const int PWMBchannel = 0;

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
}

void drive_motors(int VRx, int VRy){
  /*
  if (VRy > 512){
    motorAdir = 0;
    motorBdir = 0;
  } else {
    motorAdir = 1;
    motorBdir = 1;
  }*/
  Serial.println("should only call once");
  motorAeff = VRx;
  motorBeff = VRy;
  ledcWrite(PWMAchannel,motorAeff);
  ledcWrite(PWMBchannel,motorBeff);
  
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

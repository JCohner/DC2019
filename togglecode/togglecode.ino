


int VRx = A1;
int VRy = A2;
int SW = 12;

int VRx_value;
int VRy_value;
int SW_value;

void setup() {
  Serial.begin(9600);
  pinMode(VRy,INPUT);
  pinMode(VRx,INPUT);
  pinMode(SW,INPUT);
  
  // put your setup code here, to run once:

}

void loop() {
  VRx_value = analogRead(VRx);
  VRy_value = analogRead(VRx);
  SW_value = analogRead(VRx);

  Serial.print("VRx: ");
  Serial.println(VRx_value);

  Serial.print("VRy: ");
  Serial.println(VRy_value);

  Serial.print("SW: ");
  Serial.println(SW_value);
  // put your main code here, to run repeatedly:

}

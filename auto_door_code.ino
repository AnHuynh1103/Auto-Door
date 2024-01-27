#define sensorPin A2

#define G_led 6
#define R_led 7

#define in1 9
#define in2 10

int set_timer=5;

int sensor = 0;
int seconds = 0;
int flag = 0;
long delay_Start;


void setup() {
  Serial.begin(9600);

  pinMode(sensorPin,INPUT);
  
  pinMode(R_led,OUTPUT);
  pinMode(G_led,OUTPUT);
  
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  
  delay(500);

  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);

}

void loop() {
  sensor = digitalRead(sensorPin);

if(sensor==1){
  Serial.println("Motion detected!");
  digitalWrite(R_led, HIGH);
  digitalWrite(G_led, HIGH);

if(flag==0){ 
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  delay(500);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
}

seconds=0;
flag=1;
delay_Start = millis();
}else{
  Serial.println("Motion stopped!");
  digitalWrite(G_led,LOW);
}

if((flag==1) && (millis() - delay_Start)>999){
  seconds = seconds+1;
  delay_Start = millis();
}


if(seconds>set_timer){
  digitalWrite(R_led,LOW);

  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  delay(500);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  flag=0;
  seconds=0;
}

delay(100);
}

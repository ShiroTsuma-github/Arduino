const int pin_used=5;
const int PWM_RESOLUTION=25;   //miliseconds for every wait in ConstantPwm

void flip(int pin)
{
  digitalWrite(pin,!digitalRead(pin));
}

void reset(int pin)
{
  digitalWrite(pin,LOW);
}

void pwm(int pin,int percent,int time)
{
  reset(pin);
  for(int i=0;i<100;i++)
  {
    flip(pin);
    delayMicroseconds(percent*10);
    flip(pin);
    delayMicroseconds(1000 - percent*10);
  }
}

// void ConstantPwm(int pin,int percent,int time)
// {
//   const int div=time/PWM_RESOLUTION;
//   for(int i=0;i<div;i++)
//   {
//     pwm(pin,percent);
//     delay(PWM_RESOLUTION);
//   }
// }
void RampUp(int pin,int time,int max_speed) //speed as percent 1-100
{
  reset(pin);
  const int time_step=(time/max_speed)/PWM_RESOLUTION;
  for(int i=0;i<max_speed;i++)
  {
    
    for(int j=0;j<time_step;j++)
    {
      pwm(pin,i);
      delay(PWM_RESOLUTION);
    }
    
  }
}
unsigned long strt;
unsigned long nd;
void setup() {
  pinMode(pin_used, OUTPUT);
  Serial.begin(115200);
  
}

// the loop function runs over and over again forever
void loop() {
 
  // RampUp(pin_used,10000,100);
  for (int i = 0; i < 100; i++)
  {
    strt=millis();
    pwm(pin_used,i);
    nd=millis() -strt;
    Serial.println(i);
    Serial.println(" took ");
    Serial.println(nd);
    Serial.println(" \n");
    delay(1000);
  }
  
 

  
  // Serial.print("Ramped UP");
  // ConstantPwm(pin_used,50,5000);
  // delay(5000);
  // delay(5000);
  // pwm(pin_used,50);
  // delay(5000);




}
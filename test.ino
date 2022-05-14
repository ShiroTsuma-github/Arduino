//                    DEKLARACJA ZMIENNYCH
const int pin_used=5;
char buffer[255];
int time_took[10];
unsigned long strt;
unsigned long nd;
// opóźnienie RampUp to 26ms na każde 1000ms
// użycie -(1*time/1000) pozwoliło zmniejszyć z 26 do 5/6 na 1000ms
//      GOOD ENOUGH


//Z NIEWIADOMEGO POWODU PRZY UŻYCIU PWM, NIE ROBI WIĘCEJ NIŻ 350MS. PRZY TIME<100 ROBI 20 RÓŻNICY, POWYŻEJ NIE PRZEKRACZA 350 ROBOTY 

//                    FUNKCJE WYKORZYSTYWANE
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
  for(int i=0;i<time;i++)
  {
    flip(pin);
    delayMicroseconds(percent*10);
    flip(pin);
    delayMicroseconds(1000 - percent*10);
  }
}
void RampUp(int pin,int time,int max_speed) //max_speed jako procent 1-100
{
  // int time=time-((float)time/1000)*26;
  reset(pin);
  const int time_step=(time/max_speed)-(1*time/1000);
  for(int i=0;i<max_speed;i++)
  {
   pwm(pin,i,time_step);
  }
}
float AverageOfArray (int * array, int len)
{
  long sum = 0L ;
  for (int i = 0 ; i < len ; i++)
    sum += array [i] ;
  return  ((float) sum) / len ;
}


void setup() {
  pinMode(pin_used, OUTPUT);
  Serial.begin(115200);
}
int time=100;
void loop() {
  // for (int i = 0; i < 10; i++)
  // {
  //   strt=millis();
  //   pwm(pin_used,time,20);
  //   nd=millis() -strt;
  //   time_took[i]=nd-time;
  //   Serial.println(nd);
  // }
  //   int avg=AverageOfArray(time_took,10);
  //   sprintf(buffer,"%d : %d\n",time,avg);
  //   Serial.print(buffer);
  //   time+=100;
  //   if(time==10000)
  //   {
  //     time=1000;
  //   }



}
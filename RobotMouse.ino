/*
* Code for my robot mouse - Ensure Mafalda's mouse moves every 4 min with a stepper motor
* Most of the code I stole from
* https://create.arduino.cc/projecthub/debanshudas23/getting-started-with-stepper-motor-28byj-48-3de8c9
*
* Manuel Varela 2022
*/

#define A 2
#define B 3
#define C 4
#define D 5
#define NUMBER_OF_STEPS_PER_REV 512
#define NR_REV 0.25
#define 30_SEC_WAIT 30000

void write(int a,int b,int c,int d)
{
  digitalWrite(A,a);
  digitalWrite(B,b);
  digitalWrite(C,c);
  digitalWrite(D,d);
}

void forwardStep()
{
  write(1,0,0,0);
  delay(1);
  write(1,1,0,0);
  delay(1);
  write(0,1,0,0);
  delay(1);
  write(0,1,1,0);
  delay(1);
  write(0,0,1,0);
  delay(1);
  write(0,0,1,1);
  delay(1);
  write(0,0,0,1);
  delay(1);
  write(1,0,0,1);
  delay(1);
}
void backwardStep()
{
  write(1,0,0,1);
  delay(1);
  write(0,0,0,1);
  delay(1);
  write(0,0,1,1);
  delay(1);
  write(0,0,1,0);
  delay(1);
  write(0,1,1,0);
  delay(1);
  write(0,1,0,0);
  delay(1);
  write(1,1,0,0);
  delay(1);
  write(1,0,0,0);
  delay(1);
}

void setup()
{
  // Set outs
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);

  // Make first revolution complete
  for(int i=0; i<NUMBER_OF_STEPS_PER_REV; i++)
  {
    forwardStep();
  }
  for(int i=0; i<NUMBER_OF_STEPS_PER_REV; i++)
  {
    backwardStep();
  }

  delay(30_SEC_WAIT);

}

void loop(){

  for(int i=0; i<NUMBER_OF_STEPS_PER_REV*NR_REV; i++)
  {
    forwardStep();
  }
  for(int i=0; i<NUMBER_OF_STEPS_PER_REV*NR_REV; i++)
  {
    backwardStep();
  }

  delay(30_SEC_WAIT);
  delay(30_SEC_WAIT);
  delay(30_SEC_WAIT);
  delay(30_SEC_WAIT);
}

#include <testlib.h>

Motor mymotor(12,13,15);
void setup() {
  
  // put your setup code here, to run once:
  mymotor.begin();
  mymotor.setspeed(100);
  
  mymotor.go(0, 10);
  
  mymotor.stop();
  
 
}

void loop() {
  
}

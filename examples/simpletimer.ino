include"atimer.h"
#include "mqttclientdefs.h"
#include"utils.h"
#include "nrf24net.h"
#include "mqttsnclient.h"



void foo(){
    cout << "Hello from foo\n";
}

class Bob{
public:
    void f(){
        cout << "Hi from bob f\n";
    }
    void g(){
        cout << "Hi from bob g point :-) \n";
    }
};

Bob b;
ATimer t(&foo);
ATimer t2(b,&Bob::f,false);
ATimer t3(b,&Bob::g,false);
#define COUNT 3
ATimer *timers[COUNT]={&t,&t2,&t3};

void setup() {
  Serial.begin(115200);
  Serial.println(F("Starting"));


  t.start(1000);
  t2.start(2000);
  t3.start(700);
}


int i;
void loop() {
  for(int i=0;i < COUNT;i++ )
      timers[i]->run();
  delay(10);
}

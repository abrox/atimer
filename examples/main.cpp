#ifndef ARDUINO

#include <iostream>
#include "atimer.h"
#include <unistd.h>

using namespace std;

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
void oneSec(){
    cout << "One sec.....\n";
}

int main()
{
    ATimer t(&foo);
    Bob b;
    ATimer t2(b,&Bob::f,false);
    ATimer t3(b,&Bob::g,false);
    ATimer t4(&oneSec,false);

    t.start(1000);
    t2.start(2000);
    t3.start(700);
    t4.start(1000);

    while(1){

       t.run();
       t2.run();
       t3.run();
       t4.run();

       usleep(10);
    }
    return 0;
}

#endif

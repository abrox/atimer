#ifndef ATIMER_H
#define ATIMER_H

#include"callback.h"

#ifdef ARDUINO
    #if ARDUINO >= 100
        #include "Arduino.h"
    #else
        #include "WProgram.h"
    #endif
#endif

class ATimer : public Callback
{
public:
    template<class C>
    ATimer(C& object, void (C::*method)(),bool singleShot=true):Callback(object,method){
        init(singleShot);
    }
    template<typename T>
    explicit ATimer(T function,bool singleShot=true):Callback(function){
        init(singleShot);
    }


    void start(unsigned long int time);
    void stop();
    void run();
    void setSingleShot(bool isSs);

private:
    void init(bool singleShot);
    bool _enabled;
    bool _singleShot;
    unsigned long _lastTime;
    unsigned long int _msInterval;

    bool tick();

};

#endif // ATIMER_H

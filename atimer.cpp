#include "atimer.h"
#ifdef LINUX
#include"lib/utils.h"
#endif
bool ATimer::tick(){
    if(!_enabled)
        return false;
    if(_lastTime > millis()*2)//millis restarted
        _lastTime = 0;
    if ((unsigned long int)(millis() - _lastTime) >= _msInterval) {
        _lastTime = millis();
        if(_singleShot)
            _enabled = false;
        return true;
    }
    return false;
}
void ATimer::start(unsigned long int time){
    _msInterval = time;
    _enabled = true;
    _lastTime = millis();

}

void ATimer::stop(){
    _enabled = false;
}

void ATimer::run(){
    if(tick())
       operator ()();
}

void ATimer::setSingleShot(bool isSs){
    _singleShot = isSs;
}

void ATimer::init(bool singleShot){
    _enabled = false;
    _singleShot =  singleShot;
}

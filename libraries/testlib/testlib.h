#pragma once
#include <Arduino.h>

class Motor {  
public:
 Motor(uint8_t en , uint8_t dir , uint8_t pul);
 void begin();
 void setspeed(int speed);
 void go(byte direc, int rps);
 void reset();
 void stop();

 int getrps();
private:
    uint8_t _en;
    uint8_t _dir;
    uint8_t _pul;

    byte _direc;
    int _rps;
    int _speed;
    int gr;
    bool _workState = true;
    
};
#pragma once
#include <Arduino.h>
// описание класса
class Motor {   // класс Color
public:
 Motor(char en = D6, char dir = D7, char pul = D8);
 void begin();
 void setspeed(byte speed);
 void go(byte direc, byte rps);
private:
    char _en;
    char _dir;
    char _pul;

    bool _direc;
    byte _rps;
    byte _speed;
    
};
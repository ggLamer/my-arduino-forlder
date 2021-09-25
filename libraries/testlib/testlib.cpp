#include <testlib.h> 


Motor::Motor(uint8_t en, uint8_t dir, uint8_t pul) {
    _en = en;
    _dir = dir;
    _pul = pul;
}
void Motor::begin(){
    Serial.begin(115200);
    pinMode(_en, OUTPUT);
    pinMode(_dir, OUTPUT);
    pinMode(_pul, OUTPUT);
    _workState = true;
}
void Motor::setspeed(int speed = 100){_speed = speed;}
void Motor::stop(){_workState = false;}
void Motor::go(byte direc, int rps ){
    _direc = direc;
    _rps = rps;

    digitalWrite( _en, 0 );
    delayMicroseconds(5); 
    digitalWrite( _dir, _direc ); 

    delayMicroseconds(5);
    for (int i = 0; i < _rps * 800; i++) { 
        if (!_workState){
            digitalWrite( _en, 1 );
            Serial.println("");
            Serial.println("STOP");
            break;
        }
        digitalWrite( _pul, 1 ); 
        delayMicroseconds(_speed); 
        digitalWrite( _pul, 0 ); 
        delayMicroseconds(_speed);
        gr++;
    }
}

void Motor::reset(){gr = 0;}
int Motor::getrps(){return gr / 800;}
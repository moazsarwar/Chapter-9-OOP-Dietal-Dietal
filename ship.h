#ifndef SHIP_H
#define SHIP_H
#include "angle.h"
class Ship{
private:
    static unsigned int countShip;
    unsigned int shipNumber;
    Angle latitude;
    Angle Longitude;
public:
    Ship(){
        this->shipNumber=++countShip;
    }
    static unsigned int getCountShip(){return countShip;}
    void setShip(){
        std::cout<<"Ships Longitude"<<std::endl;
        this->Longitude.getAngle();
        std::cout<<"Ships latitude"<<std::endl;
        this->latitude.getAngle();
    }
    void showDetails(){
        std::cout<<"Ships No. "<<this->shipNumber
        <<std::endl<<"Longitude :";
        this->Longitude.display();
        std::cout<<std::endl<<"Latitude  :";
        this->latitude.display();
        std::cout<<std::endl;
    }
};
unsigned int Ship::countShip=0;
#endif

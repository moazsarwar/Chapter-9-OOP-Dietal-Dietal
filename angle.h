#ifndef ANGLE_H
#define ANGLE_H
#include <iostream>
#include <stdexcept>
enum NEWS {NORTH,EAST,WEST,SOUTH};
class Angle{
private:
    unsigned int degree;
    double minutes;
    NEWS direction;
    bool isValid(const unsigned int& _deg, const double& _min, const NEWS& _dir){
        if(_dir==NEWS::EAST || _dir==NEWS::WEST){
            return (_deg<=180 && _deg >=0 && _min<60.0 && _min>=0) ? true : false;
        }
        else if(_dir==NEWS::NORTH || _dir==NEWS::SOUTH){
            return (_deg<=90 && _deg >=0 && _min<60.0 && _min>=0) ? true : false;
        }
        return false;
    }

    void setDirection(const char& _dummy, NEWS& _direction){
        switch(_dummy){
        case 'N': case 'n':
            _direction=NEWS::NORTH;
            break;
        case 'E': case 'e':
            _direction=NEWS::EAST;
            break;
        case 'W': case 'w':
            _direction=NEWS::WEST;
            break;
        case 'S': case 's':
            _direction=NEWS::SOUTH;
            break;
        }
    }
public:
    Angle(const unsigned int& _deg=0, const double& _min=0.0, const NEWS& _dir=NEWS::NORTH){
        setAngle(_deg,_min,_dir);
    }
    void setAngle(const unsigned int& _deg, const double& _min, const NEWS& _dir){
        if(isValid(_deg,_min,_dir)){
            this->degree=_deg;
            this->minutes=_min;
            this->direction=_dir;
        }
        else{
            setAngle(0,0.0,NEWS::NORTH);
            throw std::invalid_argument("Invalid Argument Provided...Intailizing With Default Value");
        }
    }
    void getAngle(){
        unsigned int deg;
        double min;
        char dummy;
        NEWS DIR;
        std::cout<<std::endl<<"Enter Degrees :";
        std::cin>>deg;
        std::cout<<std::endl<<"Enter Minutes :";
        std::cin>>min;
        std::cout<<std::endl<<"Enter Direction (NEWS) :";
        std::cin>>dummy;
        setDirection(dummy,DIR);
        try{
            this->setAngle(deg,min,DIR);
        }
        catch(std::invalid_argument &e){
            std::cout<<e.what();
        }
    }
    void display(){
        std::cout<<this->degree<<static_cast<char>(248)<<this->minutes<<"' ";
        switch(this->direction){
        case 0:std::cout<<"NORTH";break;
        case 1:std::cout<<"EAST";break;
        case 2:std::cout<<"WEST";break;
        case 3:std::cout<<"SOUTH";break;
        }
    }
    ~Angle(){std::cout<<std::endl<<"Destructor Called For Object";this->display();}
};
#endif

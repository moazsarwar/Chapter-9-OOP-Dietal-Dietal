#include <iostream>
#include "angle.h"
using namespace std;
int main(){
    Angle a1={12,12,NEWS::NORTH};
    Angle a2{12,11,NEWS::SOUTH};
    a2.display();
    a1.display();
    cin.get();
    return 0;
}

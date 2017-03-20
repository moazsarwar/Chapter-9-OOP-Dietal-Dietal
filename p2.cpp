/**
 * ( Complex Class) Create a class called Complex for performing arithmetic with complex numbers.
 *  Write a program to test your class.
 *  Use double variables to represent the private data of the class. Provide a constructor that enables
 *  an object of this class to be initialized when it’s declared. The constructor should contain default
 *  values in case no initializers are provided. Provide public member functions that perform the
 *  following tasks:
 *  
 *   a) Adding two Complex numbers: The real parts are added together and the imaginary parts are added
 *      together.
 *
 *   b) Subtracting two Complex numbers: The real part of the right operand is subtracted from the real
 *      part of the left operand, and the imaginary part of the right operand is subtracted from the
 *      imaginary part of the left operand.
 *
 *   c) Printing Complex numbers in the form (a, b) , where a is the real part and b is the imaginary part.
 */
#include <iostream>
#include <iomanip>
using namespace std;
class Complex{
private:
    double real;
    double imag;
public:
    Complex(const double& _r=0.0, const double& _i=0.0){
        setComplex(_r,_i);
    }
    void setComplex(const double& _r, const double& _i){
        this->real=_r;
        this->imag=_i;
    }
    void display()const{
        cout.precision(2);
        cout<<fixed<<this->real<<((this->imag>0.0) ? "+" : " ")<<this->imag<<" i"<<endl;
    }
    void addComplex(const Complex * const _cPtr){
        this->real+=_cPtr->real;
        this->imag+=_cPtr->imag;
    }
    void subComplex(const Complex * const _cPtr){
        this->real-=_cPtr->real;
        this->imag-=_cPtr->imag;
    }
    Complex operator + (const Complex& _c)const{
        return Complex(this->real+_c.real,this->imag+_c.imag);
    }
};
int main(){
    Complex c1(12.2,12),c2(13,14.2),c3;
    c3=c1+c2;
    c1.display();
    c2.display();
    c3.display();
    c1.addComplex(&c2);
    c1.display();
    cin.get();
    return 0;
}

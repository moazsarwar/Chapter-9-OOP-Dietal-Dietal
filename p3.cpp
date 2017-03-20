/**
 * ( Rational Class) Create a class called Rational for performing arithmetic with fractions.
 * Write a program to test your class.
 * Use integer variables to represent the private data of the class—the numerator and the denominator.
 * Provide a constructor that enables an object of this class to be initialized when it’s declared.
 * The constructor should contain default values in case no initializers are provided and should store
 * the fraction in reduced form. For example, the fraction     2/4 would be stored in the object as 1
 * in the numerator and 2 in the denominator .
 * Provide public member functions that perform each of the following tasks:
 *  a) Adding two Rational numbers. The result should be stored in reduced form.
 *  b) Subtracting two Rational numbers. The result should be stored in reduced form.
 *  c) Multiplying two Rational numbers. The result should be stored in reduced form.
 */
#include <iostream>
#include <iomanip>
using namespace std;
class Rational{
private:
    int numerator;
    int denominator;
    int gcd(const int& a, const int &b){
        if(a==0 || b==0){return 1;}
        int remainder=1,dividend=1,divisor=1;
        if(a>=b){
            dividend=a;
            divisor=b;
        }
        else if(a<b){
            dividend=b;
            divisor=a;
        }
        while(remainder){
            remainder=dividend%divisor;
            dividend=divisor;
            divisor=remainder;
        }
        return dividend;
    }
    void reduceRational(int & n, int& d){
        int temp=1;
        if(n!=0 && d!=0){temp=gcd(n,d);}
        n/=temp;
        d/=temp;
    }
public:
    Rational(const int& n=1, const int& d=1){
        setRational(n,d);
    }
    void setRational( int n,  int d){
        if(d){
            reduceRational(n,d);
            this->numerator=n;
            this->denominator=d;
        }
        else{
            this->numerator=1;
            this->denominator=1;
        }

    }
    void addRational(const Rational* rPtr){
        int hcf=this->denominator*rPtr->denominator;
        this->numerator=(hcf/this->denominator)*this->numerator + (hcf/rPtr->denominator)*rPtr->numerator;
        this->denominator=hcf;
        reduceRational(this->numerator,this->denominator);
    }
    void subtractRational(const Rational* rPtr){
        int hcf=this->denominator*rPtr->denominator;
        this->numerator=(hcf/this->denominator)*this->numerator - (hcf/rPtr->denominator)*rPtr->numerator;
        this->denominator=hcf;
        reduceRational(this->numerator,this->denominator);
    }
    void multiplyRational(const Rational* rPtr){
        this->denominator*=rPtr->denominator;
        this->numerator*=rPtr->numerator;
        reduceRational(this->numerator,this->denominator);
    }
    void display()const{
        cout<<endl<<this->numerator<<"/"<<this->denominator<<endl;
    }
};
int main(){
    Rational r1(124,12),r2(13,26);
    r1.display();
    r2.display();
    r2.multiplyRational(&r1);
    r2.display();
    r2.addRational(&r2);
    r2.display();
    r2.subtractRational(&r2);
    r2.display();
    cin.get();
    return 0;
}

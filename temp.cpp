#include <iostream>
using namespace std;

class fraction{
private:
    int numberator;
    int denominator;
public:
    fraction() {
        numberator=0;
        denominator=1;
    }
    fraction(int a,int b) {
        numberator=a;
        if(b==0) {
            std::cout<<"WRONG INPUT";
        }
        denominator=b;
    }
    ~fraction() {
        cout<<"done";
    }
    friend int gdc (int a,int b);
    friend fraction makeshorter (fraction a);
    friend fraction plusu (fraction a,fraction b);
    friend void display(fraction a);
};

int gcd (int a,int b) {
    if(a<b) {
        int temp=a;
        a=b;
        b=temp;
    }
    if(a%b==0) {
        return b;
    }
    return gcd(b,a%b);
}
fraction makeshorter (fraction c) {
    int g=gcd(c.numberator,c.denominator);
    c.numberator/=g;
    c.denominator/=g;
    return c;
}
fraction plusu (fraction a, fraction b) {
    fraction out;
    int g=gcd (a.denominator,b.denominator);
    out.numberator=a.numberator*(b.denominator/g)+b.numberator*(a.denominator/g);
    out.denominator=(a.denominator)*(b.denominator/g);
    return makeshorter(out);
}
void display (fraction c) {
    cout<< c.numberator<<" / " << c.denominator<<endl;
}


int main() {
    fraction firstNumber (3,4);
    fraction secondNUmber (1,2);
    fraction out = plusu(firstNumber,secondNUmber);
    display(out);
    return 0;
}

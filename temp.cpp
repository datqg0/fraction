#include <bits/stdc++.h>
using namespace std;

class fraction{
public:

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
    fraction (int a) {
        numberator=a;
        denominator=1;
    }
    ~fraction() {
        //cout<<"done";
    }
    friend int gdc (int a,int b);
    friend fraction makeshorter (fraction & a);
    friend fraction plusu (fraction & a,fraction & b);
    friend fraction subtractu (fraction & a,fraction & b);
    friend fraction divide (fraction &a,fraction &b);
    friend fraction multiple(fraction &a,fraction &b);
    friend fraction module (fraction&a,fraction&b);
    friend void tomixednumber (fraction &a);
    friend void display(fraction &a);
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
fraction makeshorter (fraction &c) {
    int g=gcd(c.numberator,c.denominator);
    c.numberator/=g;
    c.denominator/=g;
    return c;
}
fraction plusu (fraction &a, fraction &b) {
    fraction out;
    int g=gcd (a.denominator,b.denominator);
    out.numberator=a.numberator*(b.denominator/g)+b.numberator*(a.denominator/g);
    out.denominator=(a.denominator)*(b.denominator/g);
    return makeshorter(out);
}
fraction subtractu (fraction &a,fraction &b) {
    fraction out;
    int g=gcd (a.denominator,b.denominator);
    out.numberator=a.numberator*(b.denominator/g)-b.numberator*(a.denominator/g);
    out.denominator=(a.denominator)*(b.denominator/g);
    return makeshorter(out);
}
fraction multiple (fraction &a,fraction &b) {
    fraction out;
    int maxi=1;
    out.numberator=a.numberator*b.numberator;
    out.denominator=a.denominator*b.denominator;
    return makeshorter(out);
}
fraction divide (fraction &a,fraction &b) {
    if(b.numberator==0) {
        //cout<<"CAN'T DEVINE"<<endl;
        return a;
    }
    int temp=b.denominator;
    b.denominator=b.numberator;
    b.numberator=temp;
    fraction out= multiple(a,b);
    temp=b.denominator;
    b.denominator=b.numberator;
    b.numberator=temp;
    return out;
}
/*
fraction module (fraction& a,fraction& b) {
    fraction temp=devide (a,b);
    int nu=temp.numberator/temp.denominator;
    if(nu==0) {
        return a;
    }
    fraction thenu(nu);
    thenu=multiple(b,thenu);
    return subtractu(a, thenu);
}*/
/*
fraction exponent (fraction& a,fraction & b) {
}*/
void tomixednumber (fraction &a) {
    int numberpart;
    int numor;
    numberpart=a.numberator/a.denominator;
    numor=a.numberator%a.denominator;
    if(numberpart!=0) {
        cout<<numberpart;
    }
    cout<<" "<<numor<<"/"<<a.denominator;
}
void display (fraction &c) {
    if(c.denominator==1) {
        cout<<c.numberator<<endl;
    }
    else {
        cout << c.numberator << " / " << c.denominator << endl;
    }
}


int main() {
    fraction firstNumber (9,4);
    fraction secondNumber (1,2);
    fraction out = divide(firstNumber,secondNumber);
    display(out);
    tomixednumber(firstNumber);
    return 0;
}

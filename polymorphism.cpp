#include<iostream>
using namespace std;
class Complex{
int real;
int img;

public:

Complex()
{
    real=0;
    img=0;
}
Complex(int r,int m)
{
    real=r;
    img=m;
}
Complex operator +(Complex &obj)
{
    Complex temp;
    temp.real=real+obj.real;
    temp.img=img+obj.img;
    return temp;
}
void display()
{
    cout<<real<<" +"<<img<<"i"<<endl;
}
};

int main()
{
    Complex c1(6,6);
    Complex c2(3,4);
    Complex c3=c1+c2;
    c3.display();
    return 0;

}
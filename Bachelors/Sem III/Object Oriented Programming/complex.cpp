#include<iostream>
using namespace std;
class Complex
{
	int real,img;
	public:
		Complex();
		Complex(int,int);
		Complex add(Complex);
		void display()
		{
			cout<<real<<"+ ("<<img<<")"<<endl;
		}
}
Complex::Complex()
{
	real=img=0;
}
Complex::Complex(int real,int img)
{
	Complex::real=real;
	Complex::img=img;
}
Complex Complex::add(Complex c)
{
	Complex c1;
	c1.real=real+c.real;
	c1.img=img+c.img;
	return c1;
}
main()
{
	int r,i;
}

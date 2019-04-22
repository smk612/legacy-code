#include <iostream>
using namespace std;

class A
{
	int i;
	public:
	A():i(9){}
	void show(){cout<<i<<endl;}
};
class B
{
	int j;
	A ob;
	public:
	B():j(1){}
	void disp(){ob.show();ob.i++;ob.show();cout<<j<<endl;}
};
int main()
{
	B b;
	b.disp();
	return 0;
}

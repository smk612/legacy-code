#include <iostream>
using namespace std;

class A
{
	int x;
	public:
	A(){}
	A(int i){x=i;}
};
class B
{
	int y,z;
	public:
	B(){}
	B(int i,int j){y=i;z=j;}
	void add(A a){B b1;b1.z=a.x+y;cout<<b1.z;}
};
int main()
{
	A ob(5);
	B ob1(4,6);
	ob1.add(ob);
	return 0;
}

#include <iostream>
using namespace std;
class Boo
{
	int i;
	public:
	Boo()
	{
		i=0;
		cout<<"BOOL\n";
	}
	Boo(int x)
	{
		i=x;
		cout<<"BOO!\n";
	}
	Boo(Boo &o)
	{
		i=o.i;
		cout<<"BOO??\n";
	}
	void print()
	{
		delete this;
		cout<<"THIS\n";
	}
};

	int main()
	{
		Boo obj1(10);
		cout<<"line 1\n";
		Boo obj2(obj1);
		cout<<"line 2\n";
		Boo obj3=obj1;
		cout<<"line 3\n";
		Boo obj4;
		cout<<"line 4\n";
		obj4=obj3;
		cout<<"line 5\n";
		obj1.print();
		return 0;
	}

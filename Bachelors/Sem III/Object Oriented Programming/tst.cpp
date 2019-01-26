#include <iostream>
using namespace std;
class A
{
	int i;
	public:
		A();
		friend void show(A);
};
A::A():i(9)
{
}
void show(A a)
{
	cout<<a.i;
}
int main()
{
	A a;
	show(a);
	return 0;
}

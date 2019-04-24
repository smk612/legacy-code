#include <iostream>
using namespace std;

template<class T,class S>
void add(T a,S b)
{
	cout<<a+b<<endl;
}
int main()
{
	add(8.1,9);
	add(9,'A');
	return 0;
}

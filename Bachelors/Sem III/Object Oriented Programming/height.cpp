#include <iostream>
using namespace std;

class Height
{
	int feet,inch;
	
	public:
		
		Height();
		Height(int,int);
		Height add(Height);
		void display();
};
Height::Height()
{
	feet=inch=0;
}
Height::Height(int f,int i)
{
	
	feet=f+i/12;
	inch=i%12;
}
Height Height::add(Height h1)
{
	Height h;
	h.feet=h1.feet+feet+(h1.inch+inch)/12;
	h.inch=(h1.inch+inch)%12;
	return h;
}
void Height::display()
{
	cout<<"\t"<<feet<<" feet and "<<inch<<" inches"<<endl;
}
int main()
{
	int f,i;
	cout<<"\tEnter the first set of feet and inch.\n\tEnter Feet-";
	cin>>f;
	cout<<"\n\tEnter Inch-";
	cin>>i;
	Height h1(f,i);
	h1.display();
	cout<<"\tEnter the second set of feet and inch.\n\tEnter Feet-";
	cin>>f;
	cout<<"\n\tEnter Inch-";
	cin>>i;
	Height h2(f,i);
	h2.display();
	cout<<"\n\tThe Result is ";
	Height h3=h1.add(h2);
	h3.display();
	return 0;
}

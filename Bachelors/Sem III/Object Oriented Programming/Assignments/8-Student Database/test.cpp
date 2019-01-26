#include <iostream>
#include <fstream>
using namespace std;

class Student
{
	int roll;
	char name[50];
	char sub[50];
	int marks;
	public:
		friend void insert();
		friend void search();
};
void insert()
{
	Student a;
	ofstream out("database",ios::out|ios::app);
	if(!out)
	{
		cout<<"\n\tCannot open file\n";
		return;
	}
	cout<<"\n\tEnter Details::";
	cout<<"\n\tRoll:";
	cin>>a.roll;
	cin.ignore(1);//discards the '\n' character from the input stream
	cout<<"\tName:";
	cin.getline(a.name,50);//used to get both the name and surname
	cout<<"\tSubject:";
	cin>>a.sub;
	cout<<"\tMarks:";
	cin>>a.marks;
	out<<a.roll<<" "<<a.name<<"|"<<a.sub<<" "<<a.marks<<endl;
	out.close();
	return;
}
void search()
{
	Student a;
	int search,flag=0;
	char t[100];
	cout<<"\n\tEnter the roll which you want to search:";
	cin>>search;
	ifstream mystream("database",ios::in);
	ofstream tempstream("temp",ios::out);
	if(!mystream)
	{
		cout<<"\n\tCannot open file.\n";
		return;
	}
	while(!mystream.eof())
	{
		mystream>>a.roll;
		if(mystream.eof())
			break;
		if(search!=a.roll)
		{
			mystream.getline(t,100);
			tempstream<<a.roll<<t<<endl;
		}
		else
		{
			flag=1;
			char ch;
			int x;
			mystream.getline(a.name,50,'|');
			mystream>>a.sub;
			mystream>>a.marks;
			cout<<"\n\tThe contents are:\n"<<a.roll;
			cout<<"\n\tRoll:"<<a.roll;
			cout<<"\n\tName:"<<a.name;
			cout<<"\n\tSubject:"<<a.sub;
			cout<<"\n\tMarks:"<<a.marks;
			cout<<"\n\tDo you want to 1.Delete or 2.Update ::";
			cin>>x;
			switch(x)
			{
				case 1: break;
				case 2: cout<<"\n\tEnter updates::";
					cout<<"\n\tDo you want to change the Roll?(y/n):";
					cin>>ch;
					if(ch=='y')
					{
						cout<<"\n\tRoll:";
						cin>>a.roll;
					}
					cout<<"\tDo you want to change the Name?(y/n):";
					cin>>ch;
					if(ch=='y')
					{
						cin.ignore(1);//discards the '\n' character from the input stream
						cout<<"\tName:";
						cin.getline(a.name,50);//used to get both the name and surname
					}
					cout<<"\tDo you want to change the Subject?(y/n):";
					cin>>ch;
					if(ch=='y')
					{
						cout<<"\tSubject:";
						cin>>a.sub;
					}
					cout<<"\tDo you want to change the Marks?(y/n):";
					cin>>ch;
					if(ch=='y')
					{
						cout<<"\tMarks:";
						cin>>a.marks;
					}
					tempstream<<a.roll<<" "<<a.name<<"|"<<a.sub<<" "<<a.marks<<endl;
					break;
				default:cout<<"\n\tInvalid Choice.";
					break;		
			}
		}
	}
	if(flag==0)
	{
		cout<<"\n\tThe Record is not found.\n";
	}
	mystream.close();
	tempstream.close();
	remove("database");
	rename("temp","database");
	remove("temp");
	return;
}
void display()
{
	char ch;
	ifstream in("database",ios::in);
	if(!in)
	{
		cout<<"\n\tCannot open file.\n";
		return;
	}
	cout<<"\n\tThe File is::\n";
	while(in.get(ch))
		cout<<ch;
	in.close();
	return;
}
int main()
{
	int ch=1;
	while(ch!=0)
	{
		cout<<"\n\tMenu::\n\t1.Insert a new record\n\t2.Modify a record\n\t3.Display the contents of the file\n\t0.Exit\n\tEnter Choice::";
		cin>>ch;
		switch(ch)
		{
			case 1: insert();
				break;
			case 2: search();
				break;
			case 3:	display();
				break;
			case 0: cout<<"\tProgram Terminated.\n";
				break;
			default: cout<<"\n\tWrong Choice.\n";
		}
	}
	return 0;
}

/*Program to demonstrate optimal processor allocation
* Version 1.0
* Dated 11/08/2016
* Working for 2 processors
* Try using stdlib function qsort instead of bubblesort
* Try to think ways to make this generic for the number of processors
*/
#include <stdio.h>
//#define ARRSIZE (100)
int modbubblesort(int *a,int n);//Fucntion that sorts the array elements using Modified Bubble Sort
int displayip(int *a,int n);//Displays the input array
int binsearchrec(int *a,int lb,int ub,int item);// Recursive Function that searches for given item using binary search
int divprocessor(int *a,int n);
int main()
{
	int n,i;
	printf("\n\tEnter the number of elements::");
	scanf("%d",&n);
	int a[n];
	printf("\n\tEnter the elements::");
	for(i=0;i<n;)
	{
		scanf("%d",&a[i++]);
	}
	modbubblesort(a,n);
	printf("\n\tThe array after sorting is::\n");
	displayip(a,n);
	divprocessor(a,n);
	return 0;
}
int modbubblesort(int *a,int n)
{
	int i,j,flag,tmp;
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				flag=1;
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
		if(flag==0)//Indicates that all the elements are in their correct position and that no swapping has been done
			return 1;
	}
	return 0;
}
int displayip(int *a,int n)
{
	int i;
	for(i=0;i<n;printf("\t%d",a[i++]));
	return 0;
}
int binsearchrec(int *a,int lb,int ub,int item)
{
	if(lb>ub)
                return ub;
        else
        {
        	int mid=(lb+ub)/2;
        	if(item==a[mid])
        		return mid;
        	else if(item<a[mid])
        		return binsearchrec(a,lb,mid-1,item);
        	else
        		return binsearchrec(a,mid+1,ub,item);
        }
}
int divprocessor(int *a,int n)
{
	int lb=0,ub=n-1,i,sum=0,last_del=0,totp1=0,totp2=0,index,k_p1=0,k_p2=0,sel,tmp,max;
	double temp,indexret,tempp,tempn;
	int p1[n],p2[n];
	for(i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	while(ub>=0)
	{
		printf("\n\t|sum=%d",sum);
		max=a[ub];
		printf("\t|max=%d",max);
		temp=sum;
		while(temp>max)
		{
			temp=temp/2;
		}
		printf("\t|temp=%.2lf",temp);
		index=binsearchrec(a,0,ub,(int)temp);
		printf("\t|index=%d",index);
		indexret=a[index];
		printf("\t|indexret=%.2lf",indexret);
		if(indexret==temp)
		{
			sel=index;
		}
		else
		{
			tempp=temp-indexret;
			tempn=a[index+1]-temp;
			printf("\t|tempp=%.2lf,tempn=%.2lf",tempp,tempn);
			if(tempp<tempn)
			{
				sel=index;
			}
			else
			{
				sel=index+1;
			}
		}
		printf("\t|sel=%d",sel);
		//Allocation to freer processor
		if(totp1<=totp2)
		{
			p1[k_p1]=a[sel];
			k_p1++;
			totp1=totp1+a[sel];
		}
		else
		{
			p2[k_p2]=a[sel];
			k_p2++;
			totp2=totp2+a[sel];
		}
		last_del=a[sel];
		printf("\t|ldel=%d",last_del);
		sum=sum-last_del;
		//Shifting
		a[sel]=0;
		for(i=sel;i<ub;i++)
		{
			tmp=a[i];
			a[i]=a[i+1];
			a[i+1]=tmp;
		}
		ub=ub-1;
	}
	printf("\n\tP1 is:");
	displayip(p1,k_p1);
	printf("\n\tP2 is:");
	displayip(p2,k_p2);
	printf("\n\tTotP1=%d,TotP2=%d,Difference=%d\n",totp1,totp2,(totp1>totp2)?(totp1-totp2):(totp2-totp1));
	return 0;
}

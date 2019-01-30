package func;
public class userS
{
	int top,max;
	int stk[];
	public userS(int n)
	{
		top = -1;
		stk = new int[n];
		max=n;
	}
	public void push(int x)
	{
		if(top+1==max)
			System.out.println("\tOverflow");
		else
			stk[++top]=x;
	}
	public int pop()
	{
		int x=-1;
		if(top==-1)
			System.out.println("\tUnderflow");
		else
		{	
			x = stk[top];
			top--;
		}
		return(x);
	}
}
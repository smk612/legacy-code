package driver;
import java.io.*;
import func.*;
public class userStack
{
	public static void main(String args[])throws IOException
	{
		int ch,n,x;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("\tEnter array size:");
		n = Integer.parseInt(br.readLine());
		userS obj=new userS(n);
		do
		{
			System.out.print("\tMenu::\n\t1.Push\n\t2.Pop\n\t3.Exit\n\tYour Choice::");
			ch = Integer.parseInt(br.readLine());
			switch(ch)
			{
				case 1: System.out.print("\tEnter the item to be pushed:");
					n=Integer.parseInt(br.readLine());;
					obj.push(n);
					break;
				case 2: x=obj.pop();
					if(x!=-1)
						System.out.println("\tThe item popped is " + x);
					break;
				case 3: System.out.println("\tProgram Terminated.");
					break;	
				default:System.out.println("\tInvalid Choice.");
			}
		}
		while(ch!=3);
	}
}
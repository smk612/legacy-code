class xThread extends Thread //implements Runnable
{
	String str;
	Thread t;
	xThread(String s)
	{
		super(s);
		str = s;
		//t = new Thread(this,str);
		//t.start();
		start();
	}
	public void run()
	{
		try
		{
			for(int i=10;i>=1;i--)
			{
				System.out.println(str+i);
				Thread.sleep(500);			
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
public class MyThread 
{
	public static void main(String[] args) 
	{
		xThread ob1 = new xThread("one");
		
		//Thread t = Thread.currentThread();
		try
		{
			for(int i=10;i>=1;i--)
			{
				System.out.println("Parent thread "+i);
				//ob1.t.join();
				ob1.join();
				Thread.sleep(100);			
			}
			xThread ob2 = new xThread("two");
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
	}
}

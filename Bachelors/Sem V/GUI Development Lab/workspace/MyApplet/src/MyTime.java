//Combines Thread with Applet
import java.awt.*;
import java.applet.*;
import java.util.*;
/*NOT OF USE
 * <applet code ="MyApplet" height="1000" width="1000">
 * </applet>
*/
public class MyTime extends Applet implements Runnable
{
	Thread t,t1;
	public void init()
	{
		
	}
	public void start()
	{
		t = new Thread(this);
		t.start();
	}
	public void run()
	{
		t1 = Thread.currentThread();
		while(t1==t)
		{
			repaint();//runs the paint function again and again
			try
			{
				t1.sleep(1000);
			}
			catch(Exception e)
			{}
		}
	}
	public void paint(Graphics g)
	{
		//Snippet to display system time on screen. As we are using thread, it is getting updated automatically
		Calendar c = new GregorianCalendar();
		String hh = String.valueOf(c.get(Calendar.HOUR_OF_DAY));//calendar theke hour ta niche
		String mm = String.valueOf(c.get(Calendar.MINUTE));
		String ss = String.valueOf(c.get(Calendar.SECOND));
		int s=Integer.parseInt(ss);
		int m=Integer.parseInt(mm);
		String zs="",zm="";
		if(s<10)
			zs="0";
		if(m<10)
			zm="0";
		g.drawString(hh+":"+zm+mm+":"+zs+ss, 20, 20);//Thread korechi bole upgrade korche barbar
	}
	public void destroy()
	{
		
	}
}

import java.awt.*;
import java.applet.*;
import java.awt.event.*;
import java.util.*;
/*NOT OF USE
 * <applet code ="MyApplet" height="1000" width="1000">
 * </applet>
*/
public class TextBoxTime extends Applet implements ActionListener,Runnable
{
	TextArea txt;
	Thread t;
	Button source;
	Image backGround;
	public void init()
	{
		txt = new TextArea(10,30);
		txt.setEditable(false);//cannot edit the textarea
		add(txt,"center");
		Button time = new Button("Time");
		Button date = new Button("Date");
		time.addActionListener(this);
		date.addActionListener(this);
		add(time);	add(date);
		backGround = getImage(getCodeBase(),"test.jpg");
	}
	public void run()
	{
		while(t.isAlive())
		{
			txt.setText(" ");
			Calendar c = new GregorianCalendar();
			String hh = String.valueOf(c.get(Calendar.HOUR_OF_DAY));//The hour is taken in the 24 hour format
			String mm = String.valueOf(c.get(Calendar.MINUTE));
			String ss = String.valueOf(c.get(Calendar.SECOND));
			String dd = String.valueOf(c.get(Calendar.DATE));
			String month[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
			int s=Integer.parseInt(ss);
			int m=Integer.parseInt(mm);
			String zs="",zm="";
			if(s<10)
				zs="0";
			if(m<10)
				zm="0";
			try
			{
				if(source.getLabel() == "Time")
				{
					txt.append(hh+":"+zm+mm+":"+zs+ss);
					Thread.sleep(1000);
				}
				else if(source.getLabel() == "Date")
				{
					txt.append("The date is: "+dd+"-"+month[c.get(Calendar.MONTH)]+"-"+String.valueOf(c.get(Calendar.YEAR)));
					Thread.sleep(5000);
				}
			}
			catch(Exception e)
			{}
		}
	}
	@Override
	public void actionPerformed(ActionEvent e)
	{
		source = (Button)e.getSource();//tells us which button is being clicked
		if(source.getLabel() == "Time")
		{
			t=new Thread(this);
			t.start();
		}
		else if(source.getLabel() == "Date")
		{
			t=new Thread(this);
			t.start();
		}
	}
	public void paint(Graphics g)
	{
		g.drawImage(backGround, 0, 0,(int)getBounds().getWidth(),(int)getBounds().getHeight(), this);
	}
}

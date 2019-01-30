import java.awt.*;
import java.applet.*;
/*NOT OF USE
 * <applet code ="MyApplet" height="1000" width="1000">
 * </applet>
*/
public class Nand extends Applet
{
	public void init()
	{
		
	}
	public void start()
	{
		
	}
	public void paint(Graphics g)
	{
		int x=0,y=0;//starting coordinates
		g.drawArc(x, y, 50, 50, 270, 180);//the arc
		g.drawLine(x+25, y, x+25, y+50);//vertical line
		g.drawOval(x+50, y+22, 5, 5);//not bubble
		g.drawLine(x+55, y+25, x+80, y+25);//output line
		//g.drawString("C", 610, 274);
		g.drawLine(x+25, y+10, x, y+10);//input line A
		//g.drawString("A", 400, 224);
		g.drawLine(x+25, y+40, x, y+40);//input line B
		//g.drawString("B", 400, 324);
	}
	public void destroy()
	{
		
	}
}
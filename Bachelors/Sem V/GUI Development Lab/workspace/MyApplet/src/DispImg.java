import java.awt.*;
import java.applet.*;
import java.net.*;
public class DispImg extends Applet
{
	private Image img;
	private AppletContext c;
	public void init()
	{
		c=this.getAppletContext();
		String url=this.getParameter("img");
		if(url==null)
		{
			url="test.png";
		}
		try
		{
			URL u = new URL(this.getDocumentBase(),url);
			img = c.getImage(u);
		}
		catch(Exception e)
		{
			c.showStatus("Couldn't Find Image");
		}
	}
	public void paint(Graphics g)
	{
		g.drawImage(img, 0, 0, 600, 400, null);
	}
}

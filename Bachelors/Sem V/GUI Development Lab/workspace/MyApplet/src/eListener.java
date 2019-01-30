import java.awt.*;
import java.applet.*;
import java.awt.event.*;
/*NOT OF USE
 * <applet code ="MyApplet" height="1000" width="1000">
 * </applet>
*/
public class eListener extends Applet implements ActionListener
{
	TextArea txt;
	String Add,Sub;
	int i=10,j=20,sum=0,sub=0;
	public void init()
	{
		txt = new TextArea(10,20);
		txt.setEditable(false);//cannot edit the textarea
		add(txt,"center");
		Button b = new Button("Add");
		Button c = new Button("Substract");
		b.addActionListener(this);
		c.addActionListener(this);
		add(b);
		add(c);
	}
	@Override
	public void actionPerformed(ActionEvent e)
	{
		txt.setText("");
		txt.append("i = "+i+"\tj = "+j+"\n");
		Button source = (Button)e.getSource();//tells us which button is being clicked
		if(source.getLabel() == "Add")
		{
			sum = i+j;
			txt.append("Sum = "+sum+"\n");
		}
		else if(source.getLabel() == "Substract")
		{
			sub = Math.abs(i-j);
			txt.append("Difference = "+sub+"\n");
		}
		//else is not mandatory
	}
}

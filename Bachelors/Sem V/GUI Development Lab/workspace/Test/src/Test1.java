
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

import org.jdesktop.swingx.JXDatePicker;

import java.text.SimpleDateFormat;
import java.util.*;
import java.sql.*;


public class Test1 extends JFrame //implements ActionListener
{
	Connection c;
	ResultSet r;
	JComboBox<String> jcb;
	JTextField nameText,rollText;
	JButton b1,b2,b3;
	JXDatePicker j;
	JPanel p;
	Test1()
	{
		setVisible(true);
		setTitle("Registration Form");
		setSize(700,700);
				
		GridBagLayout gbag = new GridBagLayout();
		GridBagConstraints gbc =new GridBagConstraints();
		setLayout(gbag);
		JLabel heading = new JLabel("Registration Form in GUI Format");
		JLabel nameLab = new JLabel("Name:");
		JLabel rollLab = new JLabel("Roll:");
		JLabel courseLab = new JLabel("Course:");
		JLabel dobLab = new JLabel("Date of Birth:");
		
		nameText = new JTextField(10);
		rollText = new JTextField(10);
					
		try
		{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			c=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe","system","oracle");
			Statement st=c.createStatement();
			String str="select course from course";
			r=st.executeQuery(str);
			jcb=new JComboBox<String>();
			while(r.next())
			{
				String id=r.getString(1);
				jcb.addItem(id);
			}
			st.close();
			r.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		
		j = new JXDatePicker();
		p = new JPanel();
		j.setDate(new GregorianCalendar().getTime());
		j.setFormats(new SimpleDateFormat("dd-MM-yyyy"));
		p.add(j);
		
		b1=new JButton("Submit");
		b2=new JButton("Clear");
		b3=new JButton("Display");
		
		gbc.weighty=1.0;
		gbc.gridwidth=GridBagConstraints.REMAINDER;
		gbc.anchor=GridBagConstraints.NORTH;
		gbag.setConstraints(heading, gbc);
		
		gbc.anchor=GridBagConstraints.EAST;
		
		gbc.gridwidth=GridBagConstraints.RELATIVE;
		gbag.setConstraints(nameLab, gbc);
		gbc.gridwidth=GridBagConstraints.REMAINDER;
		gbag.setConstraints(nameText, gbc);
		
		gbc.gridwidth=GridBagConstraints.RELATIVE;
		gbag.setConstraints(rollLab, gbc);
		gbc.gridwidth=GridBagConstraints.REMAINDER;
		gbag.setConstraints(rollText, gbc);
		
		gbc.gridwidth=GridBagConstraints.RELATIVE;
		gbag.setConstraints(courseLab, gbc);
		gbc.gridwidth=GridBagConstraints.REMAINDER;
		gbag.setConstraints(jcb, gbc);
		
		gbc.gridwidth=GridBagConstraints.RELATIVE;
		gbag.setConstraints(dobLab, gbc);
		gbc.gridwidth=GridBagConstraints.REMAINDER;
		gbag.setConstraints(p, gbc);
				
		gbc.anchor=GridBagConstraints.CENTER;
		gbc.gridx=0;
		gbag.setConstraints(b1, gbc);
		gbc.gridx=1;
		gbag.setConstraints(b2, gbc);
		gbc.gridx=2;
		gbag.setConstraints(b3, gbc);
		
		add(heading);
		add(nameLab);
		add(nameText);
		add(rollLab);
		add(rollText);
		add(courseLab);
		add(jcb);
		add(dobLab);
		add(p);
		add(b1);
		add(b2);
		add(b3);
		
	}
	public static void main(String[] args)
	{
		new Test1();
	}

}

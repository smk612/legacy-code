import java.awt.*;

import javax.swing.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;
import java.util.Vector;

@SuppressWarnings("serial")
public class Regform extends JFrame implements ActionListener 
{
	JLabel l1,l2,l3,l4,l5;
	JTextField t1;
	JButton b1,b2;
	JPasswordField p1,p2;
	JComboBox c1;
	
	Connection c;
	ResultSet r,r1;
	Font f = new Font("Serif",Font.BOLD,20);
	Regform()
	{
		setVisible(true);
		setSize(700,700);
		setLayout(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Registration Form");
		
		
		l1 = new JLabel("Registration Form in GUI Format");
		l1.setForeground(Color.LIGHT_GRAY);
		l1.setFont(f);
		
		l2 = new JLabel("Name: ");
		l3 = new JLabel("Create Password: ");
		l4 = new JLabel("Confirm Password: ");
		l5 = new JLabel("Country: ");
		
		t1 = new JTextField();
		p1 = new JPasswordField();
		p2 = new JPasswordField();
		b1 = new JButton("Submit");
		b2 = new JButton("Reset");
		
		b1.addActionListener(this);
		b2.addActionListener(this);
		
		l1.setBounds(100, 30, 400, 30);
		l2.setBounds(80, 70, 200, 30);
		l3.setBounds(80, 110, 200, 30);
		l4.setBounds(80, 150, 200, 30);
		l5.setBounds(80, 190, 200, 30);
		t1.setBounds(300, 70, 200, 30);
		p1.setBounds(300, 110, 200, 30);
		p2.setBounds(300, 150, 200, 30);
		b1.setBounds(200, 350, 100, 30);
		b2.setBounds(320, 350, 100, 30);

		add(l1);
		add(l2);
		add(t1);
		add(l3);
		add(p1);
		add(l4);
		add(p2);
		add(l5);
		add(b1);
		add(b2);
		
		try
		{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			c = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "system", "oracle");
			Statement st = c.createStatement();
			String str = "select country from reg";
			r = st.executeQuery(str);
			Vector v = new Vector();
			while(r.next())
			{
				String id = r.getString(1);
				v.add(id);
			}
			c1 = new JComboBox(v);
			c1.setBounds(300, 190, 200, 30);
			st.close();
			r.close();
			add(c1);
		}
		catch(Exception E)
		{
			
		}
	}

	public static void main(String[] args) 
	{
		new Regform();
	}

	@Override
	public void actionPerformed(ActionEvent e) 
	{
		if(e.getSource() == b1)
		{
			String s1 = t1.getText();
			char[] s2 = p1.getPassword();
			char[] s3 = p2.getPassword();
			String s4 = new String(s2);
			String s5 = new String(s3);
			String s6 = c1.getToolTipText();
			if(s4.equals(s5))
			{
				try
				{
					Class.forName("oracle.jdbc.driver.OracleDriver");
					Connection c = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "system", "oracle");
					//PreparedStatement p = c.prepareStatement(sql);
					Statement st = c.createStatement();
					String str = "Insert into reg values('"+ s1 +"','" + s4 +"', '" + s6 +"')";
					st.executeUpdate(str);
					JOptionPane.showMessageDialog(b1, "Inserted Successfully");
					t1.setText("");
					p1.setText("");
					p2.setText("");
				}
				catch(Exception E) {}
			}
			else
			{
				JOptionPane.showMessageDialog(b1, "Password Doesn't Match...! Please try again...");
				p1.setText("");
				p2.setText("");
				c1.setToolTipText("");
			}
		}
		else
		{
			t1.setText("");
			p1.setText("");
			p2.setText("");
			c1.setToolTipText("");
		}
	}

}


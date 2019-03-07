import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;
import java.util.*;
import java.util.Date;
import java.util.Vector;
import java.util.Calendar;
import org.jdesktop.swingx.JXDatePicker;
import java.text.SimpleDateFormat;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class Assign extends JFrame implements  ActionListener{

	JLabel l1,l2,l3,l4,l5;
	JTextField tf1,tf2,tf3;
	JButton b1,b2,b3;
	JComboBox c1;
	JXDatePicker j;
	JPanel p;		
	
	ResultSet r,r1;
	Connection c;
	String[] col={"Name","Roll no","Course","Date of Birth"};
	Font f=new Font("Serif",Font.BOLD,20);
	Assign()
	{
		 j=new JXDatePicker();
		 p=new JPanel();	
		j.setDate(new GregorianCalendar().getTime());
		j.setFormats(new SimpleDateFormat("dd-MM-yyyy"));
		 p.add(j);
		 add(p);
		 
		 
		setVisible(true);
		setSize(700,700);
		setLayout(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Registration Form");
		/*-----------LABELS--------------*/
		l1=new JLabel("Registration Form in GUI format");
		l1.setForeground(Color.orange);
		l1.setFont(f);
		l2=new JLabel("Name:");
		l3=new JLabel("Roll:");
		l5=new JLabel("Date Of Birth:");
		l4=new JLabel("Course:");
		
		tf1=new JTextField();
		tf2=new JTextField();
		tf3=new JTextField();
		
		b1=new JButton("Submit");
		b2=new JButton("Clear");
		b3=new JButton("Display");
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		
		l1.setBounds(100, 30, 400, 30);
		l2.setBounds(80, 70, 200, 30);
		l3.setBounds(80, 110, 200, 30);
		l4.setBounds(80, 150, 200, 30);
		l5.setBounds(80, 190, 200, 30);
		tf1.setBounds(300, 70, 200, 30);
		tf2.setBounds(300, 110, 200, 30);
		b1.setBounds(50, 350, 100, 30);
		b2.setBounds(170, 350, 100, 30);
		b3.setBounds(290, 350, 100, 30);
		p.setBounds(300, 190, 250, 30);
		add(l1);
		add(l2);
		add(tf1);
		add(l3);
		add(tf2);
		add(l4);
		add(tf3);
		add(l5);
		add(b1);
		add(b2);
		add(b3);
		
try{
	Class.forName("oracle.jdbc.driver.OracleDriver");
	c=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "system","oracle" );
		Statement st=c.createStatement();
		String str="select course from course";
		r=st.executeQuery(str);
		Vector v=new Vector();
		while(r.next())
		{
			String id=r.getString(1);
			v.add(id);
		}
		c1=new JComboBox(v);
		c1.setBounds(300, 150, 200, 30);
		add(c1);
		st.close();
		r.close();
	}
	catch(Exception e)
	{
		System.out.println(e);
	}
}
public static void main(String[] args) {
	new Assign();
}
@Override
public void actionPerformed(ActionEvent e) {
	if(e.getSource()==b1)
	{
		String s1=(tf1.getText()).trim();
		String s2=(tf2.getText()).trim();
		String s3;
		SimpleDateFormat f=new SimpleDateFormat("dd/MM/yyyy");
		Date d= j.getDate();
		s3=f.format(d);
		String s6=c1.getSelectedItem().toString();
		
		if((s1.equals("")==false)&&(s2.equals("")==false))
		{
			try{
				int xy=Integer.parseInt(s2);
				Statement st=c.createStatement();
				String str="Insert into student(name,roll,dob,course) values ('"+s1+"',"+xy+",to_date('"+s3+"','dd/mm/yyyy'),'"+s6+"')";
				st.executeUpdate(str);
				JOptionPane.showMessageDialog(b1,"inserted successfully");
				tf1.setText(" ");
				tf2.setText(" ");
				tf3.setText(" ");
			}
			catch(Exception ec)
			{
				JOptionPane.showMessageDialog(b1,ec);
			}
		}
		else
		{
			JOptionPane.showMessageDialog(b1,"Some Fields are empty");
		}
	}
	else if(e.getSource()==b3)
	{
		JFrame f=new JFrame("Database Search Result");
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setLayout(new BorderLayout());
		DefaultTableModel m=new DefaultTableModel();
		m.setColumnIdentifiers(col);
		JTable t=new JTable();
		t.setModel(m);
		t.setAutoResizeMode(JTable.AUTO_RESIZE_ALL_COLUMNS);
		t.setFillsViewportHeight(true);
		JScrollPane s=new JScrollPane(t);
		s.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		s.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
		String aa,bb,cc,dd;
		dd=bb=aa=cc="";
		try{
			Statement st=c.createStatement();
			String str="select name,roll,course,dob from student";
			r1=st.executeQuery(str);
			int flag=0;
			while(r1.next())
			{
				aa=r1.getString("name");
				bb=r1.getString("roll");
				cc=r1.getString("course");
				dd=r1.getString("dob");
				m.addRow(new Object[] {aa,bb,cc,dd});
				flag=1;
			}
			if(flag==0)
			{
				JOptionPane.showMessageDialog(b3,"no record found","Error",JOptionPane.ERROR_MESSAGE);
			}
				f.add(s);
				f.setVisible(true);
				f.setSize(400,300);
				st.close();
				r1.close();
			}
			catch(Exception ec)
			{
				
			}
		}
		else
		{
			tf1.setText(" ");
			tf3.setText(" ");
			tf2.setText(" ");
		}
	}

}

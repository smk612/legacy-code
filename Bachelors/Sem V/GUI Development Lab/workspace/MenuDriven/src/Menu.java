import java.awt.BorderLayout;
import java.awt.Desktop;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class Menu extends JFrame implements ActionListener
{
	JMenuItem f1,f2,f3,f4;
	private void createMenuBar()
	{
		JMenuBar m = new JMenuBar();
		ImageIcon inew = new ImageIcon("new.png");//default path is the workspace directory
		ImageIcon iopen = new ImageIcon("open.png");
		ImageIcon isave = new ImageIcon("save.png");
		ImageIcon iclose = new ImageIcon("close.png");
		JMenu f = new JMenu("File");//File ta hoche main menu,chobigulo submenu hobe
		JMenu i = new JMenu("Import");
		JMenuItem i1 = new JMenuItem("Import Bookmarks");//side menu toiri kore
		JMenuItem i2 = new JMenuItem("Import Mail");
		i.add(i1);//import er submenu dekhabe
		i.add(i2);
		f1 = new JMenuItem("New",inew);
		f2 = new JMenuItem("Open",iopen);
		f3 = new JMenuItem("Save",isave);
		f4 = new JMenuItem("Close",iclose);
		f4.setToolTipText("Click to Exit");
		//f4.addActionListener((ActionEvent e)->{System.exit(0)});//JDK8 e support korbe
		f2.addActionListener(this);
		f4.addActionListener(this);
		f.add(f1);
		f.add(f2);
		f.add(f3);
		f.add(i);
		f.add(f4);
		m.add(f);
		setJMenuBar(m);
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==f4)
			System.exit(0);
		else if(e.getSource()==f2)
		{
			final JFileChooser fc = new JFileChooser();
			fc.showOpenDialog(this);
			File selFile = fc.getSelectedFile();
			try {
				String contents = new Scanner(selFile).useDelimiter("\\Z").next();
				System.out.println(contents);
				
			} catch (FileNotFoundException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			/*if(Desktop.isDesktopSupported())
			{
				try 
				{
					Desktop.getDesktop().open(selFile);
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}*/
		}
			
	}
	private void initUI()
	{
		createMenuBar();
		setTitle("My Menu");
		setSize(300,200);//width and height
		setLocationRelativeTo(null);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	Menu()
	{
		initUI();
	}
	public static void main(String[] args) 
	{
		/*EventQueue.invokeLater(()->{
			Menu obj = new Menu();
			
		});//JDK8 */
		Menu obj = new Menu();
		obj.setVisible(true);
	}

}

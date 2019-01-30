package Shape;
import java.io.*;

public class Shapes 
{
	public static void main(String[] args)throws IOException
	{
		int ch;
		double l,b;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter 1 for Rectangle, 2 for Square: ");
		ch=Integer.parseInt(br.readLine());
		if(ch==1)
		{
			System.out.print("Enter length: ");
			l=Double.parseDouble(br.readLine());
			System.out.print("Enter breadth: ");
			b=Double.parseDouble(br.readLine());
			Rectangle r=new Rectangle(l,b);
			System.out.println("The area is: " + r.area());
			System.out.println("The perimeter is: " + r.perimeter());
		}
		else
		{
			System.out.print("Enter side: ");
			l=Double.parseDouble(br.readLine());
			Square s=new Square(l);
			System.out.println("The area is: " + s.area());
			System.out.println("The perimeter is: " + s.perimeter());
		}
	}

}

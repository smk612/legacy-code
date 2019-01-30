package Shape;
public class Square extends Rectangle
{
	double side;
	Square(double a) 
	{
		super(a,a);
		side=a;
	}
	public double area()
	{
		return (side*side);
	}
	public double perimeter()
	{
		return (4*side);
	}
}
package Shape;
interface Geometry
{
	double area();
	double perimeter();
}

public class Rectangle implements Geometry
{
	double length,breadth;
 	Rectangle(double l, double b)
 	{
 		length=l;
	 	breadth=b;
 	}
 	public double area()
 	{
 		return (length*breadth);
 	}
 	public double perimeter()
 	{
 		return (2*(length+breadth));
 	}
}

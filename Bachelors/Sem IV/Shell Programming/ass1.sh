#Shell Program to find the roots of a Quadratic Eqn.
echo A Quadratic Equation is of the form ax^2+bx+c=0
read -p "Enter the variable a::" a
read -p "Enter the variable b::" b
read -p "Enter the variable c::" c
z=`expr "scale=3;$b * $b - 4 * $a * $c"|bc`
if [ $z -gt 0 ]
	then 
	d=`expr "scale=3;sqrt($z)"|bc`
	x=`expr "scale=2;(-$b + $d)/( 2 * $a)"|bc`
	y=`expr "scale=2;(-$b - $d)/( 2 * $a)"|bc`
	echo "The roots are::" $x $y
	else
	echo "The roots are Imaginary."
fi

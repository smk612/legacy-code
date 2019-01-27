#Shell Program to calculate a to the power b
a=$1
b=$2
echo "We are going to calculate" $a "to the power" $b
pow()
{
	x=1 #we can access and edit a and b here
	while [ $b -gt 0 ]
	do
		x=`expr $x \* $a`
		b=`expr $b - 1`
	done
	#nothing is being returned
}
pow
echo "The answer is::" $x #x can also be accessed (and edited) here

echo Hello
read -p "Enter the number 1::" a
echo "The input is" $a
read -p "Enter the number 2::" b
echo "The input is" $b
c=`expr $a + $b`
echo "The output is" $c
d=100
echo "The output is" $d
e=`expr $a \* $b`
echo "The output is" $e
f=`echo "scale=2;$a/2"|bc`
echo $f
if [ $d -gt $e ]
	then 
	echo OMG
	else
	echo OMFG
fi
pwd
cd ..
pwd
ls

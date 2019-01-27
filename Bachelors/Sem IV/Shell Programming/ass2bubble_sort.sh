#Shell Program to perform Bubble Sort
read -p "Enter the number of elements::" n
i=0
echo Enter the elements
while [ $i -lt $n ]
do	
	read a[$i]
	i=`expr $i + 1`
done
flag=1
m=`expr $n - 1`
while [ $flag -eq 1 ]
do
	flag=0
	i=0
	while [ $i -lt $m ]
	do
		j=`expr $i + 1`
		if [ ${a[$i]} -gt ${a[$j]} ]
		then
			temp=${a[$i]}
			a[$i]=${a[$j]}
			a[$j]=$temp
			flag=1
		fi
		i=`expr $i + 1`
	done
done
echo The sorted array is::
i=0
while [ $i -lt $n ]
do	
	echo ${a[$i]}
	i=`expr $i + 1`
done

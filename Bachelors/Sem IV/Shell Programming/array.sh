read -p "Enter array size::" n
i=0
echo Enter the array elements
while [ $i -lt $n ]
do	
	read a[$i]
	i=`expr $i + 1`
done
echo Printing
i=0
while [ $i -lt $n ]
do	
	echo ${a[$i]}
	(( i++ ))
done

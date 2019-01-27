read -p "Enter the Lower Bound::" a
read -p "Enter the Upper Bound::" b
i=$a
echo The Prime Numbers are::
while [ $i -le $b ]
do
	j=2
	while [ $j -lt $i ]
	do
		m=`expr $i % $j`
		if [ $m -eq 0 ]
		then
			break
		fi
		j=`expr $j + 1`
	done
	if [ $j -eq $i ]
	then
		echo $i
	fi
	i=`expr $i + 1`
done


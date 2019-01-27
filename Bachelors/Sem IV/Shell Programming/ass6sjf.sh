#Shell Program to perform Shortest Job First Scheduling
read -p "Enter the no. of processes::" n
i=0
while [ $i -lt $n ]
do	
	echo -n "Enter the burst time for the process" `expr $i + 1` ":"
	read b[$i]
	a[$i]=`expr $i + 1`
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
		if [ ${b[$i]} -gt ${b[$j]} ]
		then
			temp=${b[$i]}
			b[$i]=${b[$j]}
			b[$j]=$temp
			temp=${a[$i]}
			a[$i]=${a[$j]}
			a[$j]=$temp
			flag=1
		fi
		i=`expr $i + 1`
	done
done
echo "PROCESS | BURST TIME | WAITING TIME | TURNAROUND TIME"
i=0
w=0
t=0
sw=0
st=0
while [ $i -lt $n ]
do	
	t=`expr $t + ${b[$i]}`
	st=`expr $st + $t`
	sw=`expr $sw + $w`
	echo -e "P"${a[$i]}"\t\t"${b[$i]}"\t\t"$w"\t\t"$t
	w=`expr $w + ${b[$i]}`
	i=`expr $i + 1`
done
echo "The average waiting time:" `expr "scale=2;$sw / $n"|bc` "ms"
echo "The average turnaround time:" `expr "scale=2;$st / $n"|bc` "ms"

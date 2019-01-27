#Shell Program to perform Round Robin Scheduling
read -p "Enter the no. of processes:" n
i=0
tot=0
while [ $i -lt $n ]
do	
	echo -n "Enter the burst time for the process" `expr $i + 1` ":"
	read b[$i]
	tl[$i]=${b[$i]}
	wt[$i]=0
	i=`expr $i + 1`
done
read -p "Enter the time slice:" ts 
flag=1
while [ $flag -eq 1 ]
do	
	flag=0
	i=0
	while [ $i -lt $n ]
	do	
		if [ ${tl[$i]} -gt $ts ]
		then
			x=$ts			
		else
			x=${tl[$i]}
		fi
		if [ $x -ne 0 ]
		then
			flag=1
			tl[$i]=`expr ${tl[$i]} - $x`
			j=0
			while [ $j -lt $n ]
			do
				if [ $j -ne $i -a ${tl[$j]} -ne 0 ]
				then
					wt[$j]=`expr ${wt[$j]} + $x`
				fi
				j=`expr $j + 1`
			done
		fi
		i=`expr $i + 1`
	done
done
echo "PROCESS | BURST TIME | WAITING TIME | TURNAROUND TIME"
i=0
sw=0
st=0
while [ $i -lt $n ]
do	
	echo -e "P"`expr $i + 1`"\t\t"${b[$i]}"\t\t"${wt[$i]}"\t\t"`expr ${b[$i]} + ${wt[$i]}`
	sw=`expr $sw + ${wt[$i]}`
	st=`expr $st + ${wt[$i]} + ${b[$i]}`
	i=`expr $i + 1`
done
echo "The average waiting time:" `expr "scale=2;$sw / $n"|bc` "ms"
echo "The average turnaround time:" `expr "scale=2;$st / $n"|bc` "ms"

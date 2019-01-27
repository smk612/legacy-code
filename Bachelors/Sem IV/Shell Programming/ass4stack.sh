#Shell Program to implement Stack Operations
read -p "Enter max size of stack::" m
top=-1
push()
{
	if [ $top -ne `expr $m - 1` ]
	then
		top=`expr $top + 1`
		stack[$top]=$1
	else
		echo "The Stack is Full."
	fi
}
pop()
{
	if [ $top -ne -1 ]
	then
		echo "The element deleted is::" ${stack[$top]}
		top=`expr $top - 1`
	else
		echo "The Stack is Empty."
	fi
}
disp()
{
	echo "The Stack is now"
	if [ $top -eq -1 ]
	then
		echo "empty."
	else
		i=0
		while [ $i -le $top ]
		do
			echo ${stack[$i]}
			i=`expr $i + 1`			
		done
	fi
}
ch=1
while [ $ch -ne 3 ]
do
	read -p "Menu::1.Push 2.Pop 3.Exit.Enter your Choice::" ch
	case $ch in
		1) read -p "Enter the number::" n
		 	push $n
			;;
		2) pop
			;;	
		3) echo "Program terminated."
	esac
	disp
done

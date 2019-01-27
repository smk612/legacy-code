first_fx()
{
	echo "Fx w/o parameter and return"
}
second_fx()
{
	echo "Fx with Parameter::" $1 $2
	return 42
}
first_fx
second_fx RKMV Belur
ret_val=$?
echo $ret_val

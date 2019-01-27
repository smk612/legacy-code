#Shell Program to delete an empty file
read -p "Enter the filename(with extension)::" filename
if [ ! -e "$filename" ]
then
	echo "File Doesn't Exist."
else
	charcount=`cat $filename |wc -w`
	if [ $charcount -eq 0 ]
	then
		rm -f $filename
		echo "File has being removed."
	else
		echo "File is not empty."
	fi
fi

#!student username

echo "Enter the classfile name"
read file1
echo "Enter student username"
read name
if [ -f $file1 ]
then 
	if grep -x -q $name $file1 ;
		then 
			echo "username already exist"
		else
			 echo $name >> $file1	
			echo "name added to list"
		fi	
	else
		echo "Enter correct classlist"
	fi	
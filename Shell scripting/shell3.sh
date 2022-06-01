#! check if two strings are equal

if [ $# != 2 ]
	then
		echo Enter two strings!!
else
	test $1 = $2 && echo The strings $1 and $2 are equal || echo Strings  $1 and $2 are not equal
fi
#! Check file or directory

echo "Enter the file/Directory name"
read fname
if [ -d $fname ]
then
    echo $fname exists and is a directory
elif [ -f $fname ]
then 
    echo $fname exists and is a file
else
    echo "Not a file or directory"
fi
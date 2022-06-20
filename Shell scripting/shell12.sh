echo "Currently logged user"
who
echo "Logname:"
users
echo "Current Shell:"
echo $SHELL
echo "Home Directory:"
echo $HOME
echo "Operating System type:"
uname -o
echo "Path Settings:"
echo $PATH
echo "Current working directory:"
pwd
echo "currently logged number of users:"
users | wc -w
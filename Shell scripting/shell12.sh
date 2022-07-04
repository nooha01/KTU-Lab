echo "Currently logged user"
who
echo -e "\nLogname:"
users
echo -e "\nCurrent Shell:"
echo $SHELL
echo -e "\nHome Directory:"
echo $HOME
echo -e "\nOperating System type:"
uname -o
echo -e "\nPath Settings:"
echo $PATH
echo -e "\nCurrent working directory:"
pwd
echo -e "\nCurrently logged number of users:"
users | wc -w
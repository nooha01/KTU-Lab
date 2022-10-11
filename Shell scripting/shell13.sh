#!Display details

echo "OS version, release number and kernel version"
echo `cat /etc/os-release`
echo -e "\nAll available shells"
echo `cat /etc/shells`
echo -e "\nmouse settings"
echo `xinput --list`
echo -e "\nComputer CPU information"
echo `cat /proc/cpuinfo`
echo -e "\nmemory information"
echo `cat MemTotal /proc/meminfo`
echo -e "\nhard disk information"
echo `lshw -c disk`
echo -e "\nfile system"
echo `mount | column -t`

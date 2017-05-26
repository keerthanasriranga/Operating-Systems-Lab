stty -echo
echo "Enter passwd"
read pwd1
echo "Reenter passwd"
read pwd2
if [ $pwd1 = $pwd2 ]
then
	echo "Terminal Locked"
	while true
	do
	echo "Enter password"
	read pwd3
	if [ $pwd3 = $pwd2 ]
	then
		echo "Terinal Unlocked"
		stty echo
		exit
	else
		echo "Wrong password"
		
	fi
	done
else
	echo "Wrong password"
	stty echo
fi

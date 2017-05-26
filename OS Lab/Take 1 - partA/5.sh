stty -echo
echo "Enter password"
read pass1
echo "Reenter password"
read pass2
#dont't forget $ for the variables here in if statement
if [ $pass1 = $pass2 ]
	then
	echo "Terminal locked"
	while true
	do
		echo "Enter password"
		read pass3
		#dont't forget $ for the variables here in if statement
		if [ $pass3 = $pass2 ]
			then
			echo "Terminal unlocked"
			stty echo
			exit
		else
			echo "Wrong password"
		fi
	done
else 
	echo "Passwords don't match"
	stty echo
fi
		

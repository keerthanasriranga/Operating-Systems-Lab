if [ $# -eq 0 ]
then
	echo "Invalid arg"
	exit
else
	for login in $*
	do
		if grep $login /etc/passwd >/dev/null
		then
			echo "Login login:$login"
			dir=`grep $login /etc/passwd | cut -d ":" -f 6`
			echo "Home directory : $dir"
		fi
	done
fi

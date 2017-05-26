if [ $# -eq 0 ]
	then
	echo "Invalid arguments"
else
	for login in $*
	do 
		#no ` ` here and there's space after login
		if grep $login /etc/passwd >/dev/null
		then
			echo "Login login : $login"
			#space after login and after cut and after : tooand f
			dir=`grep $login /etc/passwd | cut -d ":" -f 6`
			echo "Home directory : $dir"
		else
			echo "Invalid login"
		fi
	done
fi

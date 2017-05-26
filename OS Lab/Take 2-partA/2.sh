if [ $# -gt 2 ] || [ $# -lt 2 ]
then
	echo "Invalid args"
	exit
else
	f1=`ls -l $1|cut -c2-10`
	f2=`ls -l $2|cut -c2-10`
	if [ $f1 = $f2 ] 
	then
		echo "permissions are equal"
		echo " permissions : $f1"
	else
		echo "Permissions are unequal"
		echo "$1 : $f1"
		echo "$2 : $f2"
	fi
fi


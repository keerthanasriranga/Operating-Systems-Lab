if [ $# -lt 2 ] || [ $# -gt 2 ]
	then
	echo "Not valid"
	exit
else
	f1=`ls -l $1|cut -c2-10`
	f2=`ls -l $2|cut -c2-10`
	if [ $f1 = $f2 ]
		then
		echo "File permissions are equal"
		echo "Permission: $f1"
	else
		echo "File permissions are unequal"
		echo "Permission of $1: $f1"
		echo "Permission of $2: $f2"
	fi
fi

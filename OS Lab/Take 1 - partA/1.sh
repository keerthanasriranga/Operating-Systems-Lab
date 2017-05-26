if [ $# -eq 0 ]
then 
	echo "Invalid"
else
	while [ $# -gt 0 ]
	do
		rev="$1 $rev"
		shift
	done
echo "$rev"
fi

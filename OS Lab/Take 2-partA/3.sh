echo "Enter dir"
read dir1
if [ ! -d $dir1 ]
then
	echo "Invalid dir"
	exit
else
	large=0
	for file1 in `find $dir1 type -f`
	do
		size1=`stat -c %s $file1`
		echo "size of $file1 is $size1"
		if [ $size1 -gt $large ]
		then
			large=$size1
			lar_file=$file1
		fi
	done
fi
echo "Largest file : $lar_file size : $large "

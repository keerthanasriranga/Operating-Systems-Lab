echo "Enter the directory name"
read dir1
#don't forget gap btw ! and -d
if [ ! -d $dir1 ]
	then
	echo "not a valid directory"
	exit
else
large=0
for file1 in `find $dir1 -type f`
	do
	#it's $file1
	size1=`stat -c %s $file1`
	echo "Size of $file1 is $size1"
	if [ $size1 -gt $large ]
		then
		large=$size1
		lar_file=$file1
	fi
done
fi
echo "Largest file is $lar_file and size is $large"

read a b c
lar=$a
if [ $b -gt $a ] && [ $b -gt $c ]
then
	lar=$b
fi
if [ $c -gt $a ] && [ $c -gt $b ]
then
	lar=$c
fi
echo "$lar"

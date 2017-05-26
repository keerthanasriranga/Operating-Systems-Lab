read a b c
lar=$c
if [ $a -gt $b ] && [ $a  -gt $c ]
	then
	lar=$a
fi
if [ $b -gt $c ] && [ $b -gt $a ]
	then
	lar=$b
fi
echo $lar

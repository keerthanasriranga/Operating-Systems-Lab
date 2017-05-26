echo "Enter string"
read string
len=${#string}
for (( p=$len-1; p >= 0 ; p-- ))
	do
	string1="$string1${string:$p:1}"
	done
echo "$string1"

#execute as bash 6b.sh

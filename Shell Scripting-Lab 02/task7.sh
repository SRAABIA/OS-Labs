factorial(){
fact=1
read -p "Enter Any Integer: " n
if [ $n -lt 0 ]; then
	echo "Enter a positive number only."
else
	for i in $(seq 1 $n)
	do
	(( fact=fact*i ))
	done
	echo "Factorial of $n is "$fact
fi
}
factorial

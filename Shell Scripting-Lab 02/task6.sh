fib(){
n1=0
n2=1
next=0
echo 
read -p "Enter a limit for fibonnaci sequence: " n
echo
echo -n $n1
echo -n '  ' $n2
(( next=$n1+$n2 ))
while [ $next -le $n ]
do
echo -n '  '  $next
n1=$n2
n2=$next	
(( next=$n1+$n2 ))
done
echo 
echo
}

fib

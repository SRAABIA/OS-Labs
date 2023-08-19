read -p "Enter any positive number " n
	s=2
	flag=0
	while [ $s  -le $(($n/2)) ]
	do
	if [ $(($n%$s)) -eq 0 ];
	then 
		flag=1
	fi
		((s++)) 
	done
	if [ $flag -eq 1 ];
	then 
		echo $n" NOT PRIME"
	else 
		echo $n" IS PRIME"
	fi

		

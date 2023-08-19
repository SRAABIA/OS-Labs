read -p "Enter num1: " n1
read -p "Enter num2: " n2
read -p "Enter num3: " n3
read -p "Enter num4: " n4
read -p "Enter num5: " n5
echo -e
if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ] && [ $n1 -gt $n4 ] && [ $n1 -gt $n5 ]; then
echo "Max is: " $n1
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ] && [ $n2 -gt $n4 ] && [ $n2 -gt $n5 ]; then
echo "Max is: " $n2
elif [ $n3 -gt $n1 ] && [ $n3 -gt $n2 ] && [ $n3 -gt $n4 ] && [ $n3 -gt $n5 ]; then
echo "Max is: " $n3
elif [ $n4 -gt $n1 ] && [ $n4 -gt $n2 ] && [ $n4 -gt $n3 ] && [ $n4 -gt $n5 ]; then
echo "Max is: " $n4
elif [ $n5 -gt $n1 ] && [ $n5 -gt $n2 ] && [ $n5 -gt $n3 ] && [ $n5 -gt $n4 ]; then
echo "Max is: " $n5
fi
echo -e
if [ $n1 -lt $n2 ] && [ $n1 -lt $n3 ] && [ $n1 -lt $n4 ] && [ $n1 -lt $n5 ]; then
echo "Max is: " $n1
elif [ $n2 -lt $n1 ] && [ $n2 -lt $n3 ] && [ $n2 -lt $n4 ] && [ $n2 -lt $n5 ]; then
echo "Max is: " $n2
elif [ $n3 -lt $n1 ] && [ $n3 -lt $n2 ] && [ $n3 -lt $n4 ] && [ $n3 -lt $n5 ]; then
echo "Max is: " $n3
elif [ $n4 -lt $n1 ] && [ $n4 -lt $n2 ] && [ $n4 -lt $n3 ] && [ $n4 -lt $n5 ]; then
echo "Max is: " $n4
elif [ $n5 -lt $n1 ] && [ $n5 -lt $n2 ] && [ $n5 -lt $n3 ] && [ $n5 -lt $n4 ]; then
echo "Max is: " $n5
fi
echo -e


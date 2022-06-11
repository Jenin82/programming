x=2
while [ $x -ne 5 ] 
do
	echo Select a choice
	echo 1. Add
	echo 2. Subtract
	echo 3. Multiply
	echo 4. Divide
	echo 5. Exit
	read x
	case $x in
		1) echo Enter the two numbers
		read a
		read b
		echo Sum is : $((a+b))
		;;
		2) echo Enter the two numbers
		read a
		read b
		count=$((a-b))
		echo Remainder is : $count
		;;
		3) echo Enter the two numbers
		read a
		read b
		count=$((a*b))
		echo Product is : $count
		;;
		4) echo Enter the two numbers
		read a
		read b
		count=$((a/b))
		echo Quotient is : $count
		;;
		5) echo End of program
		;;
	esac
done
x=2
while [ $x -ne 5 ]
do
	echo Enter your choice 
	echo 1. Addition
	echo 2. Subtraction
	echo 3. Multiplication
	echo 4. Division
	echo 5. Exit
	read x
	case $x in
		1) echo echo Enter 2 numbers
		read a
		read b
		echo sum is : $((a+b))
		;;
		2) echo echo Enter 2 numbers
		read a
		read b
		echo Remainder is : $((a-b))
		;;
		3) echo echo Enter 2 numbers
		read a
		read b
		echo Quotient is : $((a*b))
		;;
		4) echo echo Enter 2 numbers
		read a
		read b
		echo Product is : $((a/b))
		;;
	esac
done
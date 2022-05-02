echo Enter the limit.
read a
x=0
y=1
echo $x
echo $y
for (( i=0; i<a; i++ ))
do
	z=$((x+y))
	echo $z
	x=$y
	y=$z
done

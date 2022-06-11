echo Enter the limit.
read a
x=0
y=1
i=2
echo $x
echo $y
while [ $i -lt $a ]
do
	z=$((x+y))
	echo $z
	x=$y
	y=$z
	i=$((i+1))
done
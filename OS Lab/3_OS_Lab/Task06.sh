read -p "Enter the number till which you want to create Fibonacci series " num
a=0
b=1
c=0
if [[ $num = 1 ]]
then echo $a
exit
elif [[ $num = 2 ]]
then 
	echo $a 
	echo $b
exit
fi
 echo $a 
 echo $b
for((i=0;i<num-2;((i++)) ))
do
	c=$(($a+$b))
	echo $c
	a=$b
	b=$c	
done

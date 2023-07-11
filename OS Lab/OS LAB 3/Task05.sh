echo "Enter 5 numbers below "
read -a array
echo ${array[0]} ${array[1]} ${array[2]} ${array[3]} ${array[4]}	
min=99999 max=-1
for ((i=0;$i<5;((i++))))
do
	if [[ $max < ${array[$i]} ]]
	then
		max=${array[$i]}
	fi
	
	if [[ ${array[$i]} < $min ]]
	then 
		min=${array[$i]}
	fi
done
echo "The value of min is $min and the value of max is $max."

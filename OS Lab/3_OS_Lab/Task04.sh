read -p "Enter the number you want to check if it is prime or not " num
for (( i=2 ; i<=num/2 ; i++))
do
	if [[ $((num%i)) == 0 ]]
	then
		echo "$num is not a prime number."
		exit
	fi
done
echo "The number is a prime number."

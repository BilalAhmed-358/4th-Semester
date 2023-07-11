read -p "Enter the number you want to calculate factorial of " fac
if [[ $fac = 0 ]]
then
echo "1"
exit
fi
num=1
for((i=1;i<fac+1;((i++))))
do
num=$(( $num*$i ))
	
done
echo "The factorial of $fac is $num."

read -p "Enter the number " n
new=1
while [[ $n > 1 ]]
do 
  (( new=$new*$n ))
   ((n--))
done
echo "factorial of the number is : $new "

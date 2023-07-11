read -p "Enter the number : " num
count=0
(( decr=--num ))
count1=2
while [[ $decr > -1 ]]
do
    (( divi=$num%$count1 ))
 if [[ $divi = 0 ]] ; then 
    ((count++))
 fi
  ((count1++))
   ((decr--))
done
if [[ $count > 1 ]]; then
   echo "Number is prime"
else 
   echo "Number is not prime"
fi     

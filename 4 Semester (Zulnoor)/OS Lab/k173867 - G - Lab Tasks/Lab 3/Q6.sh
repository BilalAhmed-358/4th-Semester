read -p "Enter the number of terms " n
t1=0
t2=1
t3=0
echo "$t1 "
echo "$t2 "
((n=$n-2))
while [[ $n > 0 ]] 
do 
  ((t3=$t1+$t2))
   t1=$t2
   t2=$t3
  echo "$t3 "
   ((n--))
done 

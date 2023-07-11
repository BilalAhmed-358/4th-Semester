echo "Enter 5 numbers : " 
read num1 
read num2 
read num3
read num4 
read num5
max=$num1
mini=$num1
if [[ $max < $num2 ]]; then
     max=$num2
fi
if [[ $max < $num3 ]]; then
     max=$num3
fi
if [[ $max < $num4 ]]; then
     max=$num4
fi
if [[ $max < $num85 ]]; then
     max=$num5
fi 
echo "Maximum number is : $max "

if [[ $mini > $num2 ]]; then
     mini=$num2
fi
if [[ $mini > $num3 ]]; then
     mini=$num3
fi
if [[ $mini > $num4 ]]; then
     mini=$num4
fi
if [[ $mini > $num85 ]]; then
     max=$num5
fi 
echo "Minimum number is : $mini "

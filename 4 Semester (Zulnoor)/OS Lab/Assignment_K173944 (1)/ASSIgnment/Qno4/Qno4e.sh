


echo "Enter the string"
read str

if [  "$(echo "$str" | rev)" != "$str" ]; then
echo "The string is  not a palindrome"
else
echo "The string is a palindroe"
fi
 	


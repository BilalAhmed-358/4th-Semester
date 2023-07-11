

for i in {1..1000}
do
add=0
((temp=$i))

while [[ $temp -gt 0 ]]
do
digit=$((temp%10))
mul=$((digit * digit * digit))
add=$((add+mul))
temp=$((temp/10))
done
if [[ $add -eq $i ]] ;then
echo $i
fi
done



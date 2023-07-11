
sudo apt install rename
read -p "Enter path of file1 : " path_file1
read -p "Enter path of file2 : " path_file2

if [[ -r $path_file1 ]]; then
echo "File1 has Read Permission"
else
echo "Error : file1 has not read permission "
exit 1
fi
if [[ -f $path_file2 ]]; then

echo "File2 exists "
else
echo "File2 does not exist "
exit 1
echo "Do you want to overwrite the content : "
read -p " Press y for yes or Press n for no : " input
fi

if [[ $input -eq 'y' ]]; then
cat $path_file1 > $path_file2
elif [[ $input -eq 'n' ]]; then
echo "Content of file1 has not copied ."
fi






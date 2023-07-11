

# Before executing this  script  you have to open the security pannel from google account and then turn on less secure app access

sudo apt install curl
read -p "Email : " email
read -p "Password : " Pasword
echo
curl -u $email:$Pasword --silent "https://mail.google.com/mail/feed/atom" |  grep -oPm1 "(?<=<title>)[^<]+" | sed '1d'


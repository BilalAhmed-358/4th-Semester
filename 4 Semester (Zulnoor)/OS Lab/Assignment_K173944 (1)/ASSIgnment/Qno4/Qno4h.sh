#!/bin/bash
#sudo -s
input_path=$1
if [[ $2 -eq 0  ]];then
n=10
else
n=$2
fi
cd $path
du -sk * | sort -rn | head -$number


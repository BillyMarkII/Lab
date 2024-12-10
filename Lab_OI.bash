#!/bin/bash 
dobavlenie() {
echo "Enter date"
read date
echo "Enter category" 
read category
echo "Enter sum" 
read sum
echo "Enter description" 
read descr
echo "$date $category $sum $descr" >> "$filename" 
}
prosmotr() {
if [[ -f "$filename" ]]; then
echo "Zapisi o rashodah"
cat "$filename"
else 
echo "Zapisei net"
fi
}
if [[ $# -ne 1 ]]; then
echo "File = $0"
exit 1
fi
filename="$1"
while true; do
echo "Choose an action"
echo "1 - add, 2 - view"
read -p "Vvedite nomer" vibor
case $vibor in
1) dobavlenie ;;
2) prosmotr;exit 0;;
esac
done

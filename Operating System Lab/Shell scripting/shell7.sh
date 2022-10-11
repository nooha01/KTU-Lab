#!lower to upper case of vowels - to be completed

echo Enter file
read f1

echo Enter new file
read f2

`cat < $f1 | tr '[:upper:]' '[:lower:]' | cat > $f2`
echo Vowels of $f1 are converted to uppercase and the result is stored in $f2

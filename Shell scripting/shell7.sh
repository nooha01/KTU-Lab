#!lower to upper case of vowels - to be completed

echo Enter file
read file1
echo Enter new file
read file2
`cat < $file1 | tr 'aeiou' 'AEIOU' | cat > $f2`
echo Vowels of $file1 are converted to uppercase and the result is stored in $f2


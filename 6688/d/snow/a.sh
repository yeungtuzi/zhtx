for i in *.c
do
echo $i
sed "s/\"\/d\/snow\//__DIR__\"/" $i > tmp$$
mv tmp$$ $i
done


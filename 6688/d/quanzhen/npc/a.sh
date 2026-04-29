mkdir change.$$
for i in *.c
do
echo $i
mv $i change.$$/$i
cat change.$$/$i | sed  "s/daoxue-xinfa/taoism/g" > $i
done

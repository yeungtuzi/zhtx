mkdir change.$$
for i in *.c
do
echo $i
mv $i change.$$/$i
cat change.$$/$i | sed "s/mahayana/buddhism/g" > $i
done

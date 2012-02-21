#!bash
rm test.obj
i=0;
for f in img/*.png; do
convert -sigmoidal-contrast 90x100 $f ./laser.svg;
./a.out $i >>test.obj;
i=`expr $i + 1`;
echo $i;
done;

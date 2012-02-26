#!bash
rm test.obj
#rm caldata
touch test.obj
#erzeuge erst svg's
#for f in img/*.png; do
#convert -sigmoidal-contrast 90x100 $f $f.svg;
#done;

#alle svg's in svg ordner
#cp ./img/*.svg ./svg/
i=0;

#calc pointcloud
for f in ../v1/svg/*.svg; do
#cp $f ./laser.svg;
./a.out $f $i  >>test.obj;
i=`expr $i + 10`;
echo $i;
done;

#rm ./laser.svg

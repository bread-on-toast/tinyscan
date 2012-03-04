#!bash
g++ main.cpp scan.cpp -lX11 -lpthread -o tinyscan
rm test.obj
touch test.obj
i=0;
for f in ./vimg/*; do
./tinyscan $f $i  >>test.obj;
i=`expr $i + 1`;
echo $i;
done;

#meshlab test.obj

mkdir shelldir
mkdir cdir
mkdir jpgdir

for f in *.sh
do
    mv $f shelldir
done

for f in *.c
do
    mv $f cdir
done

for f in *.JPEG
do
    mv $f jpgdir
done
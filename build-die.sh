qmake-qt4 -r BenPad.pro
make
./BenPad &
pid=$!
echo "build: Launching application"
for i in {15..0}
do
    sleep 1
    echo "build: Killing application in $i seconds"

done

kill $pid

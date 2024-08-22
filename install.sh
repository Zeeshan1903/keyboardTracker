sudo apt-get update
#file for installint the libevdev-dev 
sudo apt-get install libevdev-dev
sudo apt-get install pkg-config

#this will check whether the package willl have the libevdev-dev install with what configurations
pkg-config --cflags --libs libevdev

chmod 777 run.sh

#g++ -o keyboard keyboard.cpp -I/usr/include/libevdev-1.0 -L/usr/lib/x86_64-linux-gnu -levdev

echo "Now whatever output u are getting like "-I/usr/include/libevdev-1.0""
echo "Then replace the libedev-1.0 in the run.sh file if output is diff from the mention above"

echo "Now type command ./run.sh in the terminal "
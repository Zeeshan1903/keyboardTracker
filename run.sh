
filename=$1
g++ -o ${filename} ${filename}.cpp -I/usr/include/libevdev-1.0 -L/usr/lib/x86_64-linux-gnu -levdev

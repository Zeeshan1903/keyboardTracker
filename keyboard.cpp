#include <iostream>
#include <libevdev/libevdev.h>
#include <fstream>
#include <bits/stdc++.h>

//These are the functions which are used specially by the posix system
#include <fcntl.h>    // For open()
#include <unistd.h>   // For close()

#include <cstring>    // For strerror()
#include <cerrno>     // For errno
using namespace std;
 

/*

Here we are using the fcntl lib for reading and writing to the file because it provides the direct or low level file handling 
whereas the fstream provides the high level of abstraction

It has open, read, write method

1)Open method
int file = open(path,mode)
Mode : O_RONLY,O_WONLY,ORDWR

2)char store[size];
ssize_t bytesread = read(<from where to read>, void *buf, size);
        whereaas the buf = where to stroe the value 
        ssize_t is the datatype which stores value  as well as teh error tyeo
        it is of type int
*/


int main(){
    struct libevdev *dev;
    //Here the open is a funciton which will return the integer which 
    //is the file descriptor which is standard in linux used to show if a file is open or not 
    int fd = open("/dev/input/event4",O_RDONLY);
    if(fd < 0){
        cout << "Error opening the file "<<endl;
        return 0;
    }

    //making this dev for storing the file ouptut

    //Intializing an pointer dev which will then point towards the device which we will set using the initializing func 
    //of libevdev_new_from_fd this on the basis fo the fd here file generate a new instance of the libevdec which is dev 
    //which is pointer whihc will point towards the device which we are getting input from 
    // struct libevdev *dev = nullptr;
    // ssize_t readbyte = read(file,&dev);

    //this will stroe the errro if any comes in the file and will check whether the dev is avail
   int err = libevdev_new_from_fd(fd, &dev);

    //input_event is an standart lib which contain all fun like type,code 
    //which we are using the ev.type() and so on 
    struct input_event ev;
    
    while(true){

        //again rc is a file descriptor value and in generaol all the funof libecdev lib returns a file descripto
        //here the rc ev will contain all the input which we will take from teh device dev and themode will be READ only noremal 
int rc = libevdev_next_event(dev,LIBEVDEV_READ_FLAG_NORMAL,&ev);

        if(rc == LIBEVDEV_READ_STATUS_SUCCESS){
            // cout << ev << endl;
            // cout << " Event type : "<<ev.type<<libevdev_event_type_get_name(ev.type)<<" code: "<<ev.code<<libevdev_event_code_get_name(ev.type,ev.code)<<" value :"<<ev.value << "\n"<<ev<<endl;
            cout <<"We have an event! "<<ev.type<<"," <<libevdev_event_type_get_name(ev.type)<<","<<ev.code<<","<< libevdev_event_code_get_name(ev.type, ev.code)<<ev.value<<endl;
        
        }   
        
        //checkingif no event is available 
        else if(rc == -EAGAIN){
            continue;
        }
        else{
            cerr << "Error reading the event "<<endl;
            break;
        }

    }

    //free both the file descriptor and the dev pointer to the device and close the file 
    libevdev_free(dev);
    close(fd);

    return 0;
}
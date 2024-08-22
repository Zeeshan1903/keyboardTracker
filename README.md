#Keyboard Tracker
##Description:
Here we are using the libevdev lib which is like a wrapper lib for the evdev which provides the high level of abstraction for using the evdev susbsytem funciotn which are available.

## Installation
1. Clone the repository: `git clone https://github.com/Zeeshan1903/`
2. Navigate to the project directory: `cd repo`


### Pseudocode
//make an dev pointer, it will point to the device whcih will give input from the liibevdev
struct libevdev *dev ;


//These are the file descriptor in linux everytime u open a system u get the file descriptor value which is integer
//help us to check whether we get the error or the right input  
int fd;

int rc;
//opening the file at the path : path and then dev will point towards that device
fd = open("path",mode);

//intializing the dev pointer which will point towards it 
rc = libevdev_new_from_dev(fd,&dev);

//input_events is a class which contain various fn like the type,code,value for the inputs we get 
//This inshort provides us the function to map or get the value from the complex input we get from the kernel 
struct input_events ev;

rc = libevdev_next_event(dev,LIBEVDEV_READ_FLAG_NORMAL,&ev);

//ev will contain all the inputs here that is it means read the input from the next input we get from teh device dev and in a normal way and store it ev 


```bash
libevdev_event_type_get_name(ev.type)
#provides the type of the event

#provides the name of the event
libevdev_get_name(dev);



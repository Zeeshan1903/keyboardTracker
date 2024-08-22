## Keyboard Tracker
### Description:
Here we are using the libevdev lib which is like a wrapper lib for the evdev which provides the high level of abstraction for using the evdev susbsytem funciotn which are available.

## Installation
1. Clone the repository: `git clone https://github.com/Zeeshan1903/`
2. Navigate to the project directory: `cd repo`


### Pseudocode
## Example C++ Code for Handling Input Events

This example demonstrates how to handle input events using the `libevdev` library in C++. The code opens a device, initializes it, and reads input events.

```cpp
#include <libevdev/libevdev.h>
#include <fcntl.h>
#include <unistd.h>

// Pointer to the device that will receive input from libevdev
struct libevdev *dev;

// File descriptor for the device
int fd;

// Return code from various functions
int rc;

// Open the device file at the specified path
fd = open("path", O_RDONLY);

// Initialize the libevdev device pointer
rc = libevdev_new_from_fd(fd, &dev);

// Structure to hold input events
struct input_event ev;

// Get the next event from the device and store it in 'ev'
rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);

// 'ev' now contains the input event information


## Bash Commands for libevdev

Here are some example commands you might use with the `libevdev` library:

```bash
# Get the name of the event type
libevdev_event_type_get_name(ev.type)

# Get the name of the device
libevdev_get_name(dev);




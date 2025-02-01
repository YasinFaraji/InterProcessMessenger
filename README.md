# Inter Process Messenger

## Description
This project demonstrates inter-process communication (IPC) using shared memory and mutex synchronization in modern C++ on Linux.

- `Initiator`: Starts the process, writes an initial integer value (1) to shared memory, and continuously increments it by 1.
- `Receiver`: Reads the value from shared memory, increments it by 1, and sends it back to the initiator.

The process continues until the value reaches 10, after which both processes terminate.

## Requirements  
- Linux (Ubuntu 22.04 recommended)
- CMake 3.10+
- GCC (supporting C++17)
- pthread library
- spdlog for logging

### Installation of spdlog:

```git clone https://github.com/gabime/spdlog.git
cd spdlog
mkdir build && cd build
cmake ..
sudo make install
```

## Build Instructions

   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

## Run Instructions
Start the processes in separate terminals or as background jobs:
```bash
./ipc initiator &
./ipc receiver &
```
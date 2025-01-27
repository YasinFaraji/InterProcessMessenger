# Inter Process Messenger

## Description
This project demonstrates inter-thread communication using `std::condition_variable` in modern C++ with a focus on clean code and solid architecture. The application consists of two threads: an initiator thread that sends data to a receiver thread, and a receiver thread that processes the data received from the initiator.

## Architecture
- **Logger**: Handles logging messages to both the console and a log file (`log.txt`). It uses the `spdlog` library.
- **ThreadCoordinator**: Coordinates the execution of the `Initiator` and `Receiver` threads.
- **Initiator**: A thread responsible for sending data (incremented integers) to the receiver thread.
- **Receiver**: A thread that processes the data received from the initiator, performing operations on it.

The threads are synchronized using a `std::condition_variable` to ensure that the receiver only processes data when it has been sent by the initiator.

## Files Overview
- `common.hpp`: Defines the `Logger` class for logging.
- `initiator.hpp`: Contains the `Initiator` class responsible for sending data to the receiver.
- `receiver.hpp`: Contains the `Receiver` class responsible for processing the data.
- `thread_coordinator.hpp`: Contains the `ThreadCoordinator` class that manages the initiator and receiver threads.
- `main.cpp`: The entry point of the application where the `ThreadCoordinator` is instantiated and the threads are started.
- `.clang-format`: This configuration file is used by the `clang-format` tool to automatically format the C++ code according to a specified coding style.

### About `.clang-format`

The `.clang-format` file contains configuration settings for the `clang-format` tool, which is used to automatically format your C++ source code according to the defined coding style. The configuration file specifies rules for indentation, line breaks, spacing, and other formatting aspects of the code. By using `.clang-format`, you ensure consistent code formatting across the entire project.

## Build Instructions
1. Ensure you have `cmake` installed (minimum version 3.10).
2. Make sure the `spdlog` library is installed on your system.
3. Create a build directory and navigate into it:
   ```bash
   mkdir build && cd build
   ```
3. Run cmake to configure the project:
   ```bash
   cmake ..
   ```
4. Build the executable:
   ```bash
   make
   ```

## Run Instructions
Run the compiled program:
```bash
./condition_variable_ipc
```

## Notes
- The project uses modern C++ (C++17) and adheres to clean code principles.  
- The logging output is handled by the spdlog library and includes both console and file logging.  
- The logs include timestamps and log levels, making it easier to trace the flow of execution.  

## Dependencies  
- `spdlog`: A fast C++ logging library used for logging messages to the console and file.

### Installation of spdlog:

```git clone https://github.com/gabime/spdlog.git
cd spdlog
mkdir build && cd build
cmake ..
sudo make install
```


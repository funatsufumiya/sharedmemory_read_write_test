#include <libsharedmemory/libsharedmemory.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

int main() {
    lsm::SharedMemoryReadStream reader {"jsonPipe", 65535, true};

    while (true) {
        std::string dataString = reader.readString();
        std::cout << "Read: " << dataString << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
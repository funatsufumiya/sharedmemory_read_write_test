#include <libsharedmemory/libsharedmemory.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

int main() {
    std::string dataToTransfer = "{ foo: 'coolest IPC ever! 🧑‍💻' }";
    lsm::SharedMemoryWriteStream writer {"jsonPipe", 65535, true};

    int counter = 0;
    while (true) {
        std::string message = dataToTransfer + " #" + std::to_string(counter++);
        writer.write(message);
        std::cout << "Written: " << message << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
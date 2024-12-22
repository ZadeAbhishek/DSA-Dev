#include <iostream>
#include <thread>
#include <vector>

int sharedCounter = 0;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        sharedCounter++; // No lock here
    }
}

int main() {
    const int numThreads = 10;
    std::vector<std::thread> threads;

    // Start multiple threads
    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(std::thread(increment));
    }

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Final Counter Value: " << sharedCounter << std::endl;
    return 0;
}
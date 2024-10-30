#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>
// ##mutex
class TrafficLight {
private:
    int greenDirection; // 1 for North-South, 2 for East-West
    std::mutex mtx; // to aviod deadlock

public:
    TrafficLight() : greenDirection(1) {}

    void carArrived(
        int carId,                // ID of the car
        int roadId,               // ID of the road the car travels on. 1 (North-South) or 2 (East-West)
        int direction,            // Direction of the car: 0=North, 1=East, 2=South, 3=West
        std::function<void()> turnGreen, // Function to turn light green on the current road
        std::function<void()> crossCar   // Function to let the car cross the intersection
    ) {
        std::unique_lock<std::mutex> lock(mtx);
        
        // Check if the current green light matches the road ID
        if (greenDirection != roadId) {
            turnGreen();
            greenDirection = roadId;
        }
        
        // Let the car cross the intersection
        crossCar();
    }
};

// Helper functions to simulate turning the light green and car crossing actions
void turnGreen() {
    std::cout << "Traffic light turned green." << std::endl;
}

void crossCar(int carId, int direction) {
    std::cout << "Car " << carId << " from direction " << direction << " is crossing." << std::endl;
}

// Driver function to simulate the arrival of cars
void simulateTraffic(TrafficLight &trafficLight) {
    // List of cars arriving in the format (carId, roadId, direction)
    std::vector<std::tuple<int, int, int>> cars = {
        {1, 1, 0},  // Car 1 arriving on North-South road, direction North
        {2, 2, 1},  // Car 2 arriving on East-West road, direction East
        {3, 1, 2},  // Car 3 arriving on North-South road, direction South
        {4, 2, 3},  // Car 4 arriving on East-West road, direction West
    };

    // Create a thread for each car to simulate arrival
    std::vector<std::thread> threads;
    for (const auto &car : cars) {
        int carId = std::get<0>(car);
        int roadId = std::get<1>(car);
        int direction = std::get<2>(car);

        threads.emplace_back([&, carId, roadId, direction]() {
            trafficLight.carArrived(carId, roadId, direction,
                turnGreen, 
                [=]() { crossCar(carId, direction); }
            );
        });
    }

    // Wait for all threads to finish
    for (auto &t : threads) {
        t.join();
    }
}

int main() {
    TrafficLight trafficLight;
    simulateTraffic(trafficLight);
    return 0;
}
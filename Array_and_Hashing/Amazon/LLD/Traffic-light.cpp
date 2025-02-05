#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

// Using std namespace for brevity.
using namespace std;
using namespace std::chrono;

// Enumeration for traffic signals.
enum class Signal { RED, YELLOW, GREEN };

// TrafficLight class: controls the signal and notifies observers.
class TrafficLight {
public:
    string id;
    Signal currentSignal;
    int redDuration;    // in milliseconds
    int yellowDuration; // in milliseconds
    int greenDuration;  // in milliseconds

    TrafficLight(const string &id, int red, int yellow, int green)
        : id(id), redDuration(red), yellowDuration(yellow), greenDuration(green),
          currentSignal(Signal::RED) {}

    void changeSignal(Signal newSignal) {
        currentSignal = newSignal;
        notifyObservers();
    }

private:
    void notifyObservers() {
        cout << "Traffic light " << id << " changed to ";
        switch (currentSignal) {
            case Signal::RED:
                cout << "RED";
                break;
            case Signal::YELLOW:
                cout << "YELLOW";
                break;
            case Signal::GREEN:
                cout << "GREEN";
                break;
        }
        cout << endl;
    }
};

// Road class: represents a road that has a TrafficLight.
class Road {
private:
    string id;
    string name;
    shared_ptr<TrafficLight> trafficLight;
public:
    Road(const string &id, const string &name)
        : id(id), name(name) {}

    string getId() const { return id; }
    string getName() const { return name; }

    void setTrafficLight(shared_ptr<TrafficLight> tl) {
        trafficLight = tl;
    }

    shared_ptr<TrafficLight> getTrafficLight() const {
        return trafficLight;
    }
};

// TrafficController class (Singleton): manages roads and traffic control.
class TrafficController {
private:
    unordered_map<string, shared_ptr<Road>> roads;
    static shared_ptr<TrafficController> instance;
    static mutex instanceMutex;

    // Private constructor
    TrafficController() {}

public:
    static shared_ptr<TrafficController> getInstance() {
        lock_guard<mutex> lock(instanceMutex);
        if (!instance) {
            instance = make_shared<TrafficController>();
        }
        return instance;
    }

    void addRoad(shared_ptr<Road> road) {
        roads[road->getId()] = road;
    }

    void removeRoad(const string &roadId) {
        roads.erase(roadId);
    }

    // Starts a thread for each road's traffic light to cycle signals.
    void startTrafficControl() {
        // For each road, start a thread to cycle its traffic light.
        for (auto &pair : roads) {
            auto road = pair.second;
            auto tl = road->getTrafficLight();
            thread([tl]() {
                while (true) {
                    try {
                        this_thread::sleep_for(milliseconds(tl->redDuration));
                        tl->changeSignal(Signal::GREEN);
                        this_thread::sleep_for(milliseconds(tl->greenDuration));
                        tl->changeSignal(Signal::YELLOW);
                        this_thread::sleep_for(milliseconds(tl->yellowDuration));
                        tl->changeSignal(Signal::RED);
                    } catch (const exception &ex) {
                        cout << ex.what() << endl;
                    }
                }
            }).detach(); // Detach each thread to run independently.
        }
    }

    // Handle emergency by setting the signal to GREEN on a specific road.
    void handleEmergency(const string &roadId) {
        if (roads.find(roadId) != roads.end()) {
            auto tl = roads[roadId]->getTrafficLight();
            tl->changeSignal(Signal::GREEN);
            // Emergency handling logic can be added here.
            cout << "Emergency handled on road " << roadId << endl;
        }
    }
};

// Initialize static members.
shared_ptr<TrafficController> TrafficController::instance = nullptr;
mutex TrafficController::instanceMutex;

// Main demo function
int main() {
    auto controller = TrafficController::getInstance();

    // Create roads.
    auto road1 = make_shared<Road>("R1", "Main Street");
    auto road2 = make_shared<Road>("R2", "Broadway");
    auto road3 = make_shared<Road>("R3", "Park Avenue");
    auto road4 = make_shared<Road>("R4", "Elm Street");

    // Create traffic lights.
    auto tl1 = make_shared<TrafficLight>("TL1", 6000, 3000, 9000);
    auto tl2 = make_shared<TrafficLight>("TL2", 6000, 3000, 9000);
    auto tl3 = make_shared<TrafficLight>("TL3", 6000, 3000, 9000);
    auto tl4 = make_shared<TrafficLight>("TL4", 6000, 3000, 9000);

    // Assign traffic lights to roads.
    road1->setTrafficLight(tl1);
    road2->setTrafficLight(tl2);
    road3->setTrafficLight(tl3);
    road4->setTrafficLight(tl4);

    // Add roads to the traffic controller.
    controller->addRoad(road1);
    controller->addRoad(road2);
    controller->addRoad(road3);
    controller->addRoad(road4);

    // Start the traffic control system.
    controller->startTrafficControl();

    // Wait for 10 seconds, then simulate an emergency on road "R2".
    this_thread::sleep_for(seconds(10));
    controller->handleEmergency("R2");

    // Prevent main from exiting immediately.
    while (true) {
        this_thread::sleep_for(seconds(1));
    }

    return 0;
}
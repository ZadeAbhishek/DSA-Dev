#include <queue>

class HitCounter {
private:
    std::queue<int> hits; // Queue to store timestamps of hits

public:
    /** Initialize your data structure here. */
    HitCounter() {}

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        hits.push(timestamp); // Add the hit to the queue
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        // Remove outdated hits (timestamps older than 300 seconds)
        while (!hits.empty() && hits.front() <= timestamp - 300) {
            hits.pop();
        }
        return hits.size(); // The size of the queue is the number of valid hits
    }
};

/**
 * Example usage:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
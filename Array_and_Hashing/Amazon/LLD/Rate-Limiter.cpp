#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;
using namespace std::chrono;

class RateLimiter {
public:
    RateLimiter(int maxTokens, int refillRatePerSec)
        : maxTokens(maxTokens), tokens(maxTokens), refillRatePerSec(refillRatePerSec) {
        lastRefillTime = steady_clock::now();
    }
    
    // Try to consume a token. Returns true if allowed, false otherwise.
    bool allowRequest() {
        std::lock_guard<std::mutex> lock(mu);
        refillTokens();
        if (tokens > 0) {
            --tokens;
            return true;
        }
        return false;
    }
    
private:
    int maxTokens;                // Maximum capacity of tokens
    int tokens;                   // Current tokens available
    int refillRatePerSec;         // Tokens refilled per second
    steady_clock::time_point lastRefillTime;
    std::mutex mu;
    
    // Refill tokens based on elapsed time
    void refillTokens() {
        auto now = steady_clock::now();
        auto duration = duration_cast<seconds>(now - lastRefillTime).count();
        if (duration > 0) {
            int tokensToAdd = duration * refillRatePerSec;
            tokens = min(maxTokens, tokens + tokensToAdd);
            lastRefillTime = now;
        }
    }
};

int main() {
    // Allow 5 requests per second, bucket capacity of 5 tokens.
    RateLimiter limiter(5, 5);
    
    // Simulate 10 rapid requests.
    for (int i = 1; i <= 10; ++i) {
        if (limiter.allowRequest()) {
            cout << "Request " << i << " allowed." << endl;
        } else {
            cout << "Request " << i << " denied." << endl;
        }
        // Small delay to simulate request time (adjust as needed)
        std::this_thread::sleep_for(milliseconds(100));
    }
    
    return 0;
}
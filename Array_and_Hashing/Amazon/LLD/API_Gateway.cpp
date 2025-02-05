#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>
using namespace std;

// A simple Request class to hold basic request details.
class Request {
public:
    std::string path;   // e.g., "/service1"
    std::string apiKey; // For simplicity, we'll not validate it here

    Request(const std::string& p, const std::string& key)
        : path(p), apiKey(key) {}
};

// A simple Response class to hold response details.
class Response {
public:
    int statusCode;
    std::string body;

    Response(int code, const std::string& b)
        : statusCode(code), body(b) {}
};

// A simple Router that maps request paths to service names.
class Router {
private:
    std::unordered_map<std::string, std::string> routeTable;

public:
    Router() {
        // Define some sample routes.
        routeTable["/service1"] = "Service1";
        routeTable["/service2"] = "Service2";
    }

    // Returns the service name for the given request path.
    std::string getService(const Request& req) {
        if (routeTable.find(req.path) != routeTable.end()) {
            return routeTable[req.path];
        } else {
            throw std::runtime_error("No route found for the path: " + req.path);
        }
    }
};

// The API Gateway integrates the router and handles incoming requests.
class APIGateway {
private:
    Router router;

public:
    // Processes the incoming request and returns a response.
    Response handleRequest(const Request& req) {
        try {
            std::string service = router.getService(req);
            // In a real-world scenario, the gateway would forward the request.
            std::string message = "Request routed to " + service;
            return Response(200, message);
        } catch (const std::runtime_error &e) {
            return Response(404, e.what());
        }
    }
};

int main() {
    APIGateway gateway;

    // Create a few sample requests.
    Request req1("/service1", "dummy_key");
    Request req2("/unknown", "dummy_key");

    // Handle the requests and print responses.
    Response res1 = gateway.handleRequest(req1);
    cout << "Status: " << res1.statusCode << ", Response: " << res1.body << endl;

    Response res2 = gateway.handleRequest(req2);
    cout << "Status: " << res2.statusCode << ", Response: " << res2.body << endl;

    return 0;
}
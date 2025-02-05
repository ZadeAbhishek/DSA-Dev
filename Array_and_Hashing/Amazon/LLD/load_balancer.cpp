#include <iostream>
#include <vector>
#include <string>

// A very simple Server structure.
struct Server {
    std::string ip;
    int port;
    
    Server(const std::string &ipAddr, int portNum)
        : ip(ipAddr), port(portNum) {}
};

// A basic load balancer that uses Round Robin.
class LoadBalancer {
private:
    std::vector<Server> servers;
    int currentIndex = 0;
    
public:
    // Add a server to the pool.
    void addServer(const Server &server) {
        servers.push_back(server);
    }
    
    // Select a server using a simple round robin algorithm.
    Server getServer() {
        if (servers.empty()) {
            throw std::runtime_error("No servers available!");
        }
        // Select the server at the current index and then update the index.
        Server server = servers[currentIndex % servers.size()];
        currentIndex++;
        return server;
    }
};

int main() {
    LoadBalancer lb;
    
    // Adding some servers.
    lb.addServer(Server("192.168.1.1", 8080));
    lb.addServer(Server("192.168.1.2", 8080));
    lb.addServer(Server("192.168.1.3", 8080));
    
    // Simulate forwarding requests.
    for (int i = 0; i < 5; ++i) {
        try {
            Server server = lb.getServer();
            std::cout << "Request " << i + 1 << " handled by: " 
                      << server.ip << ":" << server.port << std::endl;
        } catch (const std::exception &ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }
    
    return 0;
}
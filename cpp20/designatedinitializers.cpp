#include <string>
#include <iostream>

struct Config {
    std::string host = "localhost";
    int port = 8080;
    bool use_ssl = false;
};
std::ostream& operator<<(std::ostream& os, const Config& config) {
    os << "Host: " << config.host << ", Port: " << config.port
       << ", Use SSL: " << (config.use_ssl ? "true" : "false");
    return os;
}
int main() {
    Config config;
    std::cout << config << std::endl;

    // Modify the config
    config.host = "example.com";
    config.port = 443;
    config.use_ssl = true;

    std::cout << "Updated Config: " << config << std::endl;
    // Demonstrate the default values
    Config defaultConfig{.host = "default.com", .port = 80, .use_ssl = false};
    std::cout << "Default Config: " << defaultConfig << std::endl;  

    return 0;
}

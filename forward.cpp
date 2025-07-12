#include <memory>
#include <iostream>
#include <utility>  // For std::forward

class Resource {
private:
    // Resource management logic can be added here
    // For example, a pointer to some resource that needs to be managed
    // This could be a file handle, network connection, etc.
    // For simplicity, we will just print messages to indicate resource acquisition and release.    
    std::unique_ptr<int[]> data_;
    size_t size_;
public:
    Resource() : data_(std::make_unique<int[]>(100)), size_(100) {
        std::cout << "Resource acquired\n";
    }
    explicit Resource(size_t size) : data_(std::make_unique<int[]>(size)), size_(size) {
        std::cout << "Resource acquired with size: " << size << "\n";
    }
    template<typename... Args>
    Resource(size_t size, Args&&... args) : data_(std::make_unique<int[]>(size)), size_(size) {
        std::cout << "Resource acquired with size: " << size << "\n";
        int index = 0;
        ( (data_[index++] = std::forward<Args>(args)), ... );  // Initialize data with provided arguments
        std::cout << "Resource initialized with provided arguments\n";  
    }
    ~Resource() { std::cout << "Resource released\n"; }
    Resource(const Resource&) = delete;  // Disable copy constructor
    Resource& operator=(const Resource&) = delete;  // Disable copy assignment
    Resource(Resource&&) noexcept { std::cout << "Resource moved\n"; }  // Move constructor
    Resource& operator=(Resource&&) noexcept {
        std::cout << "Resource move assigned\n";
        return *this;
    }
};

int main() {
    Resource res1;  // Default constructor
    Resource res2(200);  // Constructor with size parameter

    // Move res1 to res3
    Resource res3(std::move(res1));

    // Move res2 to res4
    Resource res4(std::move(res2));

    // Uncommenting the following lines will cause compilation errors due to deleted copy operations
    // Resource res5 = res3;  // Copy constructor (not allowed)
    // Resource res6 = std::move(res4);  // Copy assignment (not allowed)

    return 0;
}
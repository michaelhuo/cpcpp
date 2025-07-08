#include <iostream>

class Widget {
public:
    explicit Widget(int value) : value_(value) {}   // Constructor with an integer parameter
    auto operator<=>(const Widget& other) const = default;  // Default spaceship operator
    Widget() = default;  // Default constructor
    Widget(const Widget&) = delete;  // non-Copy constructor
    Widget(Widget&&) = default;  // Move constructor
    Widget& operator=(const Widget&) = delete;  // non-Copy assignment
    Widget& operator=(Widget&&) = default;  // Move assignment
    ~Widget() = default;  // Destructor
private:
    int value_{0};  // Default value for the integer member
};
int main() {
    Widget w1(10);  // Create a Widget with value 10
    Widget w2(20);  // Create another Widget with value 20

    if (w1 < w2) {
        std::cout << "w1 is less than w2" << std::endl;
    } else {
        std::cout << "w1 is not less than w2" << std::endl;
    }
    Widget w3 = std::move(w1);  // Move w1 to w3
    // Widget w4 = w2;  // Copy w2 to w4 (not allowed, will not compile due to deleted copy constructor)
    return 0;
}
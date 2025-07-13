#include <concepts>
#include <iostream>
template<typename TT>
concept Integral = std::integral<TT>;
template<Integral TTT>
class MyIntegralClass {
    TTT value_;
public:
    MyIntegralClass(TTT value) : value_(value) {}
    TTT getValue() const {
        return value_;
    }
    void setValue(TTT value) {
        value_ = value;
    }
    auto operator<=>(const MyIntegralClass& other) const = default;  // Default spaceship operator
    MyIntegralClass(const MyIntegralClass&) = default;  // Copy constructor
    MyIntegralClass(MyIntegralClass&&) = default;  // Move constructor
    MyIntegralClass& operator=(const MyIntegralClass&) = default;  // Copy assignment
    MyIntegralClass& operator=(MyIntegralClass&&) = default;  // Move assignment
    ~MyIntegralClass() = default;  // Destructor
};
template<std::integral T>
class Counter {
    T count_{0};  // Default value for the counter
public:
    Counter() = default;  // Default constructor
    Counter(T count) : count_(count) {}  // Constructor with an integral parameter
    auto operator<=>(const Counter& other) const = default;  // Default spaceship operator
    Counter(const Counter&) = default;  // Copy constructor
    Counter(Counter&&) = default;  // Move constructor
    Counter& operator=(const Counter&) = default;  // Copy assignment
    Counter& operator=(Counter&&) = default;  // Move assignment
    ~Counter() = default;  // Destructor   
    constexpr void increment() {
        ++count_;
    }
    constexpr T get() const {
        return count_; 
    }
};

int main() {
    Counter<int> c1;  // Default counter
    Counter<int> c2(10);  // Counter with initial value
    c1.increment();
    std::cout << "Counter 1: " << c1.get() << std::endl;  // Should print 1
    std::cout << "Counter 2: " << c2.get() << std::endl;  // Should print 10
    return 0;
}
// This code defines a Counter class template that works with integral types, providing basic operations like incrementing the count and retrieving its value. The class uses the spaceship operator for comparison, allowing it to be used in contexts where ordering is required. The main function demonstrates the usage of the Counter class with different integral types.
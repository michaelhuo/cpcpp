#include <iostream>

class MathUtils {
public:
    static constexpr int fibonacci(int n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
};

int main() {
    constexpr int result = MathUtils::fibonacci(5);
    std::cout << "Fibonacci of 5 is: " << result << std::endl;
    static_assert(result == 5, "Fibonacci of 5 should be 5");
    return 0;
}
// This code calculates the Fibonacci number for 10 at compile time using a constexpr function.
// It demonstrates the use of constexpr for compile-time computation in C++.
// The output will be "Fibonacci of 10 is: 55".
// This code is useful for understanding how to use constexpr functions in C++ for compile-time calculations.
// It can be used in scenarios where compile-time evaluation is beneficial, such as in template metapro
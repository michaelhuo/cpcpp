#include <concepts>
#include <vector>
#include <iostream>
template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;
template <Numeric T>
class Statistics {
private:
    std::vector<T> data_;
public:
    void add(T value) {
        data_.push_back(value);
    }
    T getSum() const {
        T sum = 0;
        for (const auto& value : data_) {
            sum += value;
        }
        return sum;
    }
    T getAverage() const {
        if (data_.empty()) return 0;
        return getSum() / static_cast<T>(data_.size());
    }
};

int main(void) {
    Statistics<int> stats;
    stats.add(5);
    stats.add(10);
    stats.add(15);
    std::cout << "Sum: " << stats.getSum() << std::endl;
    std::cout << "Average: " << stats.getAverage() << std::endl;
    return 0;
}
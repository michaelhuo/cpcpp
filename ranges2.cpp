#include <iostream>
#include <ranges>
#include <vector>

class DataProcessor {
    std::vector<int> data_;
public:
    DataProcessor(const std::vector<int>& data) : data_(std::move(data)) {}
    DataProcessor(std::vector<int>&& data) : data_(std::move(data)) {}
    auto get_even_values() const {
        return data_ | std::views::filter([](int x) { return x % 2 == 0; });
    }

    void process() {
        // Example processing: square each element
        for (auto& elem : data_) {
            elem *= elem;
        }
    }

    void print() const {
        for (const auto& elem : data_) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    DataProcessor processor(numbers);

    // Get even values
    auto even_values = processor.get_even_values();
    std::cout << "Even values: ";
    for (const auto& value : even_values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Process the data
    processor.process();
    std::cout << "Processed data: ";
    processor.print();

    return 0;
}

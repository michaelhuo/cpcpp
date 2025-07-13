#include <vector>
#include <stdexcept>
#include <iostream>

class Container {
    std::vector<int> data_;
public:
    Container(std::initializer_list<int> init) : data_(init) {}
    int& operator[](size_t index) {
        if (index >= data_.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }
    const int& operator[](size_t index) const {
        if (index >= data_.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }
    size_t size() const {
        return data_.size();
    }
    bool empty() const {
        return data_.empty();
    }
};

int main() {
    Container c = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    try {
        std::cout << c[10] << std::endl; // This will throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
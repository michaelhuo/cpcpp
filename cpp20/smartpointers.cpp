#include <memory>
#include <optional>
#include <string>
#include <iostream>


class ResourceManager {
public:
    void load() {
        data_ = std::make_unique<Data>();
    }

    std::optional<int> getValue() const {
        return data_ ? std::optional<int>(data_->value) : std::nullopt;
    }

private:
    struct Data {
        int value = 42;
    };
    std::unique_ptr<Data> data_;
};

int main() {
    ResourceManager resourceManager;
    resourceManager.load();

    if (auto value = resourceManager.getValue()) {
        std::cout << "Value: " << *value << std::endl;
    } else {
        std::cout << "No value available." << std::endl;
    }

    return 0;
}
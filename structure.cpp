#pragma once
#include <string>

class MyClass {
private:
    std::string name_;
    int value_{0}; // Default initializer

public:
    // Constructors
    MyClass() = default;
    explicit MyClass(const std::string& name, int value) : name_{name}, value_{value} {}

    // Interface methods
    const std::string& name() const noexcept { return name_; }
    void set_name(std::string_view name) { name_ = name; } // Use string_view
    int value() const noexcept { return value_; }
    void set_value(int value) noexcept { value_ = value; }

    // Comparison (C++20)
    auto operator<=>(const MyClass& other) const = default;
};
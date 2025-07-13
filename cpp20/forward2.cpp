#include <memory>
#include <string>
#include <utility>

class Widget {
    std::string name_;
    int value_;
public:
    Widget(std::string name, int value) : name_(std::move(name)), value_(value) {}
    void print() const {
        std::cout << "Widget Name: " << name_ << ", Value: " << value_ << std::endl;
    }
};

template<typename T, typename... Args>
std::unique_ptr<T> make_widget(Args&&... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}

int main() {
    std::string name = "ExampleWidget";
    int value = 42;
    //Lvalue arguments
    auto w1  = make_widget<Widget>(name, value); //copies name, value
    //Rvalue arguments
    auto w2 = make_widget<Widget>(std::string("temp"), 42); //moves string, copies int
    //Perfect forwarding
    auto widget = make_widget<Widget>("ExampleWidget", 42);
    //std::move is not needed here, as make_widget already handles it
    //widget is a unique_ptr<Widget>
    //mixed arguments
    auto widget2 = make_widget<Widget>(std::move(name), value); //moves name, copies value
    return 0;
}

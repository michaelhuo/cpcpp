#include <iostream>
#include <string>
int main(void) {
    std::string str;
    std::cout << "Enter your name: ";
    std::getline(std::cin, str);
    
    if (str.empty()) {
        std::cout << "You entered an empty name." << std::endl;
    } else {
        std::cout << "Hello, " << str << "!" << std::endl;
    }
    
    return 0;
}
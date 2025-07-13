#include <iostream>

enum class Color {
    Red,
    Green,
    Blue
};
enum class Status {
    Active,
    Inactive,
    Suspended
};
using UserName = std::string;   
using UserID = int;

class Session {
public:
    Session(UserName user, UserID id, Status status)
        : user_name_(user), user_id_(id), status_(status) {}

    void printSessionInfo() const {
        std::cout << "User Name: " << user_name_ << "\n"
                  << "User ID: " << user_id_ << "\n"
                  << "Status: " << static_cast<int>(status_) << std::endl;
    }

private:
    UserName user_name_;
    UserID user_id_;
    Status status_;
};

int main() {
    Session session("Alice", 12345, Status::Active);
    session.printSessionInfo();

    // Example of using enum class
    Color color = Color::Red;
    if (color == Color::Red) {
        std::cout << "The color is Red." << std::endl;
    }

    return 0;
}
// This code demonstrates the use of enum classes and type aliases in C++.
// It defines a Session class that uses UserName and UserID as type aliases for std::string and int, respectively.
// The Status enum class is used to represent the status of a user session.
// The main function creates a Session object and prints its information, along with an example of using the Color enum class.  
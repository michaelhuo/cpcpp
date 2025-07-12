#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


class Person {
public:
    Person(std::string name, int age) : name_(std::move(name)), age_(age) {}
    auto operator<=>(const Person& other) const = default;
    auto getName() const { return name_; }
    auto getAge() const { return age_; }
private:
    std::string name_;
    int age_;
};
int main() {
    Person p1("Alice", 30);
    Person p2("Bob", 25);
    Person p3("Charlie", 30);
    if (p1 < p2) {
        std::cout << p1.getName() << " is younger than " << p2.getName() << std::endl;
    } else {
        std::cout << p1.getName() << " is not younger than " << p2.getName() << std::endl;
    }
    std::vector<Person> people = {p1, p2, p3};
    std::sort(people.begin(), people.end());
    return 0;
} 
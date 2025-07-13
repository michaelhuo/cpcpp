#include <vector>
#include <ranges>
#include <string>
#include <string_view>
#include <algorithm>
#include <cmath>
#include <string>      // Required for std::string
#include <charconv>    // Required for std::from_chars
#include <cctype>      // Required for isspace
#include <iostream>

class MyData {
private:
    std::vector<int> data_ = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
public:
    auto begin() { return data_.begin(); }
    auto end() { return data_.end(); }
    auto cbegin() const { return data_.cbegin(); }
    auto cend() const { return data_.cend(); }
};

int main() {
    MyData myData;

    // Using range-based for loop
    for (const auto& value : myData) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Using std::ranges::for_each
    std::ranges::for_each(myData, [](int value) {
        std::cout << value << " ";
    });
    std::cout << std::endl;
    for (const auto& value : myData) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    for(int i : myData | std::views::filter([](int i) { return i % 2 == 0; })
            | std::views::transform([](int i) { return i * 2; })) {
        std::cout << i << " ";
    }
    std::vector<int> vec = {5,2,8,1,9,3};
    std::ranges::sort(vec);
    for (const auto& value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    std::vector<int> scores = {98, 87, 100, 92, 77};

    // Process only the first 3 scores
    for (int score : scores | std::views::take(3)) {
        std::cout << score << ' '; // Prints 98 87 100
    }
    std::cout << std::endl;
    std::vector<std::string> users = {"first.admin", "guest", "user1", "user2"};

    // Iterate over all non-special users
    for (const auto& user : users | std::views::drop(2)) {
        std::cout << user << ' '; // Prints user1 user2
    }
    std::cout << std::endl;
        std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto results = data
                 | std::views::filter([](int n) { return n % 2 != 0; }) // {1, 3, 5, 7, 9}
                 | std::views::take(3)                                 // {1, 3, 5}
                 | std::views::transform([](int n) { return n * n; })  // {1, 9, 25}
                 | std::views::reverse;                                // {25, 9, 1}

    for (int val : results) {
        std::cout << val << ' '; // Prints 25 9 1
    }
    std::cout << std::endl;
       
    std::string_view data_str = "  10, 20 , 30, invalid, 40 ";

    // This lambda will be applied to each subrange created by split.
    auto to_int = [](auto subrange) -> int {
        // Construct a string_view from the subrange to use string_view's methods.
        std::string_view sv(subrange.begin(), subrange.end());

        // Trim whitespace from the view
        auto first = sv.find_first_not_of(" \t\n\r");
        if (first == std::string_view::npos) return 0; // The subrange was empty or all whitespace.
        auto last = sv.find_last_not_of(" \t\n\r");
        sv = sv.substr(first, (last - first + 1));

        // Convert the trimmed view to an integer
        int result = 0;
        auto conv_res = std::from_chars(sv.data(), sv.data() + sv.size(), result);
        
        // Return result only if the conversion was successful and consumed the whole string.
        if (conv_res.ec == std::errc() && conv_res.ptr == sv.data() + sv.size()) {
            return result;
        }
        return 0; // Return 0 for invalid parts like "invalid"
    };

    // The pipeline is now simpler and correct.
    auto values = data_str
                | std::views::split(',')
                | std::views::transform(to_int);

    int sum = 0;
    for (int val : values) {
        sum += val;
    }

    std::cout << "Sum: " << sum << std::endl; // Prints Sum: 100
}
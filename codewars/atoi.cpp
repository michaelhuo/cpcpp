#include <string>
#include <iostream>

int string_to_number(const std::string& s) {
  //your code here
  const char MINUS_CHAR = '-';
  const char ZERO_CHAR = '0';
  auto ret = 0;
  if (s.empty() || s.size() == 1 && s[0] == MINUS_CHAR) {
    return ret;
  }
  auto sign = 1;
  auto iter = s.begin();
  if (static_cast<char>(*iter) == MINUS_CHAR) {
    sign = -1;
    iter ++;
  }
  
  while (iter != s.end() && std::isdigit(*iter) && ret < INT_MAX) {
    ret = ret * 10 + static_cast<int>(*iter - ZERO_CHAR);
    iter ++;
  }
  ret *= sign;
  return ret;
}

int main() {
  std::string input;
  std::cout << "Enter a string to convert to number: ";
  std::getline(std::cin, input);
  int result = string_to_number(input);
  std::cout << "Converted number: " << result << std::endl;
  return 0;
}
// This code defines a function `string_to_number` that converts a string to an integer.
// It handles negative numbers and checks for valid digits. The main function prompts the user for input
// and displays the converted number. The function returns 0 for empty strings or strings with only a minus sign.
// It uses `std::isdigit` to check if characters are digits and performs the
/* Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

Answer: 443839
*/

#include <iostream>
#include <string>
#include <cmath>

size_t checkNum(size_t number) {
    if(number == 0 || number == 1)
        return 0;
    std::string a = std::to_string(number);
    size_t total = 0;
    for(auto& i : a) {
        total += std::pow((i-48),5);
    }
    if(number == total)
        return number;
    else
        return 0;
}

int main() {
    size_t total = 0;
    for(int i = 0; i < 500000; i++) {
        total += checkNum(i);
    }
    std::cout << total;
}
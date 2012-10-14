/* A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.

Find the largest palindrome made from the product of two 3-digit numbers.

Answer: 906609
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool isPalindrome(std::string str) {
    std::string copy = str;
    std::reverse(copy.begin(),copy.end());
    return copy == str;
}

int main() {
    std::vector<size_t> v = {0};
    for(size_t i = 100; i <= 999; i++) {
        for(size_t k = 100; k <= 999; k++) {
            if(isPalindrome(std::to_string(i*k)) && ((i*k) > v.back()))
                v.push_back(i*k);
        }
    }
    std::cout << v.back();
}
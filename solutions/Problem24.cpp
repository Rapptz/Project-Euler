/*
What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

Answer: 2783915460

Can you believe this function is literally built in? I'm impressed.
*/

#include <algorithm>
#include <string>
#include <iostream>

int main() {
    std::string str = "0123456789";
    for(size_t i = 1; i < 1000000; ++i) {
        std::next_permutation(str.begin(),str.end());
    }
    std::cout << str;
}
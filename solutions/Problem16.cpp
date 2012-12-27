/* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

This one is pretty funny, it was pretty easy to do in Python. 

Answer: 1366

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

int main() {
    const int expo = 1000;
    const int digits = static_cast<int>((expo+(std::log(10.0)/std::log(2)))/(std::log(10.0)/std::log(2)));

    std::vector<int> n(digits);
    n[0] = 1;
    for(size_t i = 0; i < expo; ++i) {
        int carry = 0;
        for(size_t j = 0; j < digits; ++j) {
            int value = 2 * n[j] + carry;
            if(value > 9) {
                carry = 1;
                value -= 10;
            }
            else {
                carry = 0;
            }
            n[j] = value % 10;
        }
    }
    int result = std::accumulate(n.begin(),n.end(),0);
    std::cout << result;
}
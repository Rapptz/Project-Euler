/* 
Find the sum of the digits in the number 100!

Answer: 648

Note: This uses a BigInteger library I made.

*/

#include "gears/BigInteger.hpp"

int main() {
    std::string fact100 = gears::fact(100).toString();
    size_t total = 0;
    for(auto& i : fact100)
        total += (i - '0');
    std::cout << total;
}


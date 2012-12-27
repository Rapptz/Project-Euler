/*
What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

Answer: 669171001

*/

#include <iostream>
#include <cmath>

int main() {
    size_t total = 1;
    for(size_t n = 3; n <= 1001; n+=2) {
        total += 4 * (n * n) - (6 * n) + 6;
    }
    std::cout << total;
}
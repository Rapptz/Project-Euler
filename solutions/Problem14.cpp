/* The following iterative sequence is defined for the set of positive integers:

n  n/2 (n is even)
n  3n + 1 (n is odd)

Which starting number, under one million, produces the longest chain?

Answer: 837799
*/

#include <iostream>

int main() {
    size_t result, counter, n, lcount = 0;
    for(size_t i = 2; i < 1000000; ++i, counter = 0) {
        for(n = i; n != 1; ++counter) {
            if(n % 2 == 0) {
                n /= 2;
            }
            else {
                n = 3*n + 1;
            }
            if(counter > lcount) {
                result = i;
                lcount = counter;
            }
        }
    }
    std::cout << result;
}


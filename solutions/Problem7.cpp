/* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10,001st prime number?

Answer: 104743
*/


#include <iostream>
#include <random>
#include <cmath>
#include <ctime>

size_t modularPow(size_t base, size_t exponent, size_t modulus) {
    size_t result = 1;
    while(exponent) {
        if((exponent&1) == 1) {
            result = base*result % modulus;
        }
        exponent >>= 1;
        base = base*base % modulus;
    }
    return result;
}
bool isPrime(size_t number, int accuracy = 5) {
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
    if((number == 2) || (number == 3))
        return true;
    if((number <= 1) || !(number&1))
        return false;
    size_t sc = 0;
    for(size_t n = number-1; !(n&1); ++sc, n >>= 1);

    size_t dc = (number-1) / (1<<sc);
    for(int i = 0; i < accuracy; ++i) {
        std::uniform_int_distribution<> dis(2,number-2);
        size_t ac = dis(gen);
        size_t xc = modularPow(ac,dc,number);

        if((xc == 1) || (xc == number-1))
            continue;
        for(unsigned int k = 1; k <= sc-1; ++k) {
            xc = modularPow(xc,2,number);
            if(xc == 1)
                return false;
            if(xc == number-1)
                goto LOOP;
        }
    return false;
    LOOP:
        continue;
    }
return true;
}

int main() {
    size_t total = 0;
    for(int i = 0; i < 140000; i++) {
        if(isPrime(i))
            ++total;
        if(total == 10001) {
            std::cout << i << "\n";
            break;
        }
    }
}
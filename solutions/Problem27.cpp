/* 
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.

Answer: -59231

*/

#include <iostream>
#include <cmath>

bool isPrime(size_t n) {
    if(n == 1)
        return false;
    else if(n < 4.0)
        return true;
    else if(n % 2 == 0)
        return false;
    else if(n < 9)
        return true;
    else if (n % 3 == 0)
        return false;
    else {
        size_t r = std::floor(std::sqrt(static_cast<double>(n)));
        size_t f = 5;
        while (f <= r) {
            if (n % f == 0) {
                return false;
                 }
            if (n % (f+2) == 0) {
                return false;
                }
            f = f+6;
        }
    return true;
    }
}

size_t countPrimes(size_t a, size_t b) {
    size_t total = 0, n = 0;
    while(true) {
        size_t k = n * (n + a) + b;
        if(!isPrime(k))
            break;
        ++n;
        ++total;
    }
    return total;
}

int main() {
    int e, d, c = 0;
    for(int a = -999; a <= 999; ++a) {
        for(int b = -999; b <= 999; ++b) {
            int k = countPrimes(a,b);
            if(k > c) {
                c = k;
                e = a;
                d = b;
            }
        }
    }
    std::cout << e*d;
}

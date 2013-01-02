/*
For a prime p let S(p) = Sum((p-k)!) mod(p) for 1 <= k <= 5.

For example, if p=7,
(7-1)! + (7-2)! + (7-3)! + (7-4)! + (7-5)! = 6! + 5! + 4! + 3! + 2! = 720+120+24+6+2 = 872.
As 872 mod(7) = 4, S(7) = 4.

It can be verified that Sum(S(p)) = 480 for 5 <= p < 100.

Find S(p) for 5 <= p < 10^8.

Answer: 139602943319822
*/

#include <iostream>
#include <cmath>
#include <vector>

using ullong = unsigned long long;
 
template <typename T>
std::vector<T> generatePrimes(unsigned limit) {
    std::vector<T> primes;
    if (limit > 1) {
        primes.push_back(2);
        std::vector<bool> sieve((limit + 1) / 2);
        for (ullong i = 1, n = 3; i < sieve.size(); ++i, n += 2) {
            if (!sieve[i]) {
                primes.push_back(n);
                for (ullong j = n * n / 2; j < sieve.size(); j += n) {
                    sieve[j] = true;
                }
            }
        }
    }
    return primes;
}
ullong S(ullong n) {
    ullong k = 3*n % 8;
    return (k*n - 3)/8;
}

int main() {
    std::vector<unsigned> primes = generatePrimes<unsigned>(100000000);
    ullong total = 0;
    for(auto& i : primes)
        total += S(i);
    std::cout << total - 1;
}

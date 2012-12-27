/* The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

Answer: 6857
*/

#include <iostream>

unsigned long long largestPrimeFactor(unsigned long long number) {
    for(unsigned long long i = 2; i <= 100000; i++) {
        while(number % i == 0) {
            number /= i;
            if(number == 1 || number == i)
                return i;
        }
    }
    return 0;
}

int main() {
    std::cout << largestPrimeFactor(600851475143);
}
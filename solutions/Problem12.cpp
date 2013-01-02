/*
What is the value of the first triangle number to have over five hundred divisors?

Answer: 76576500

*/

#include <iostream>

using ullong = unsigned long long;

inline ullong triangle(ullong n) {
    return n*(n+1)/2;
}

ullong counter(ullong n) {
    ullong result = 0;
    for(ullong i = 1; i*i <= n; ++i) {
        if(n % i == 0) {
            result += 2;
            if(n / i == i)
                --result;
        }
    }
    return result;
}

ullong factors(ullong n) {
    ullong k = 0;
    for(ullong i = 1; k <= n; ++i) {
        if(i % 2 == 0)
            k = counter(i/2)*counter(i+1);
        else
            k = counter(i) * counter((i+1)/2);
        if(k > 500) {
            return i;
        }
    }
    return 0;
}

int main() {
    ullong i = factors(500);
    std::cout << triangle(i) << '\n';
}
/* 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.

Answer: 40730
*/

#include <iostream>
#include <array>

using ullong = unsigned long long;
ullong getSum(ullong n) {
    std::array<int,10> factorials = {{1,1,2,6,24,120,720,5040,40320,362880}};
    ullong result = 0;
    while(n > 0) {
        result += factorials[n % 10];
        n /= 10;
    }
    return result;
}

int main() {
    ullong answer = 0;
    for(ullong i = 3; i < 2177282; ++i) {
        if(i == getSum(i))
            answer += i;
    }
    std::cout << answer;
}
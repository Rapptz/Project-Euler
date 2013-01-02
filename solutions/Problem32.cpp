/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39  186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

#include <iostream>
#include <set>
#include <string>
#include <algorithm>

int main() {
    std::string pan = "123456789";
    std::set<long long> v;
    unsigned long long answer = 0;
    for(size_t i = 1; i < 100; ++i) {
        std::string str;
        size_t copy = i;
        while(str.length() < 10) {
            size_t r = i*copy;
            str = std::to_string(i) + std::to_string(copy) + std::to_string(r);
            std::sort(str.begin(),str.end());
            if(str.compare(pan) == 0)
                v.insert(r);

            ++copy;
        }
    }
    for(auto& i : v)
        answer += i;

    std::cout << answer;
}
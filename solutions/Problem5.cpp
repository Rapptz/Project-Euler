/* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

Note: I originally did this problem by hand. 
Answer: 232792560
*/

#include <iostream>

int main() {
    size_t a = 10;
    size_t b = 11;
    while(b < 20) {
        if((a % b) == 0)
            b++;
        else {
            a++;
            b = 11;
        }
    }
    std::cout << a;
}


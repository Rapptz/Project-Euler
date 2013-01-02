/* Find the next triangle number that is also pentagonal and hexagonal.

Answer: 1533776805
*/

#include <iostream>
#include <cmath>

int main() {
    unsigned long long i = 1;
    unsigned long long answer = 0;
    while(true) {
        ++i;
        answer = i*(2*i - 1);
        double k = (1+std::sqrt(1+24*answer))/6;
        if(std::floor(k) == k && answer != 40755) {
            std::cout << answer;
            break;
        }
    }
}
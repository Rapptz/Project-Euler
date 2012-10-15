/* The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

Answer: 25164150
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v(100);
    std::iota(v.begin(),v.end(),1);
    std::vector<int> x = v;
    std::transform(v.begin(),v.end(),v.begin(),[](int a) { return a*a;});
    size_t totalOfV = std::accumulate(v.begin(),v.end(), 0);
    size_t totalOfX = std::accumulate(x.begin(),x.end(), 0);
    std::cout << (totalOfX*totalOfX) - totalOfV;
}



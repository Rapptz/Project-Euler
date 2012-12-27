/*
What is the first term in the Fibonacci sequence to contain 1000 digits?

Answer: 4782
*/

#include "gears/BigInteger.hpp"

int main() {
    gears::BigInteger b("0");
    std::string a;
    for(size_t i = 2000; i <= 6000; ++i) {
        b = gears::fibonacci(i);
        a = b.toString();
        //std::cout << "fib(" << i << "):" << " length: " << a.length() << '\n';
        if(a.length() == 1000) {
            std::cout << "fib(" << i << "): " << a;
            break;
        }
    }
}
/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

Answer: 4613732
*/

#include <iostream>

unsigned long long Fib(unsigned long long n) {
    unsigned long long a = 1;
    unsigned long long b = 0;
    unsigned long long c = 0;
 
    while (n--) {
        c = b;
        b = a;
        a = b+c;
    }
 
    return a;
}

int main() {
   size_t total = 0;
   for(int i = 0; i < 35; i++) {
      if((Fib(i) < 4000000) && (Fib(i) % 2 == 0)) {
         total += Fib(i);
      }
   }
   std::cout << total;
}

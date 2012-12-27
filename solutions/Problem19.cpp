/* How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

Answer: 171 
*/

#include <iostream>

int main() {
    const int century = 100;
    const int months = 12;
    const int weeks = 7;
    std::cout << (century*months)/weeks;
}
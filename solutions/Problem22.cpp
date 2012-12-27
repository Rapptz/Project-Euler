/* Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938  53 = 49714.

What is the total of all the name scores in the file?

Answer: 871198282
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

std::vector<std::string>& split(const std::string& str, char delimeter, std::vector<std::string>& vect) {
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delimeter)) {
        vect.push_back(item);
    }
    return vect;
}

int main() {
    std::ifstream in("names.txt");
    std::vector<std::string> names;
    std::string str;
    unsigned long long total = 0;
    while(std::getline(in,str)) {
        str.erase(std::remove_if(str.begin(),str.end(),[](char c) { return (c == ' ' || c == '\"');}),str.end());
        split(str,',',names);
    }
    std::sort(names.begin(),names.end());
    for(auto i = names.begin(); i != names.end(); ++i) {
        unsigned long long lTotal = 0;
        for(unsigned long long k = 0; k < (*i).length(); ++k) {
            lTotal += ((*i)[k] - 64);
        }
        unsigned long long a = std::distance(names.begin(),i)+1;
        lTotal *= a;
        total += lTotal;
    }
    std::cout << total;        
}
/*
Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

Answer: 7273
*/

#include <iostream>
#include <fstream>

int main () {
    int lines[100][100];
    std::ifstream in("triangle.txt");
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < i+1; j++) {
            in >> lines[i][j];
        }
    }
    for (int i = 98; i >= 0; i--) {
        for (int j = 0; j < i+1; j++) {
            if (lines[i+1][j] > lines[i+1][j+1]) 
                lines[i][j] += lines[i+1][j]; 
            else 
                lines[i][j] += lines[i+1][j+1];
        }
    }
    std::cout << lines[0][0];
}
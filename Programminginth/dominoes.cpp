/*
Problem find all possible to place dominoes (-- , |) in the size of 2 * n

Solution:
create recursive function
at the start of the function let current row of dominoes to 0 and empty string
recursive 2 time first increase current row of domino by 1 and add string "--\n" to string to make that row be vertical domino
second increase current row of domino by 2 and add string "||\n" require 2 row so i increase current row by 2
let the base case of recursive function be current row should be lower and equal to n
if current row is n then print the string
*/

#include <iostream>

int n;
void recursive(int start, std::string s) {
    if (start > n) return;
    if (start == n)std::cout << s << "E\n";
    recursive(start+1, s+"--\n");
    recursive(start+2, s+"||\n");
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    recursive(0,"");
}

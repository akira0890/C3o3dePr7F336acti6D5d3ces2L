#include <iostream>
#include <algorithm>

int main() {
    std::string n;
    std::cin >> n;

    int index = 0;
    int sum3 = 0;
    int sum11 = 0;
    for (char c : n) {
        int num = (c-'0');
        sum3 += num;

        sum11 = ((sum11 * 10) + num) % 11;
        index++;
    }

    std::cout << sum3%3 << ' ' << sum11;
}
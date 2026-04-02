#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Compare {
    bool operator()(const int & a , const int & b) {
        bool evenA = (a % 2);
        bool evenB = (b % 2);

        if (evenA != evenB) {
            return !evenA;
        } else if (evenA) {
            return a > b;
        } else {
            return a < b;
        }
        // if (std::abs(a%2) == std::abs(b%2)) {
        //     if (a % 2 == 0) return a < b;
        //     else return a > b;
        // } else if (a % 2 == 0) {
        //     return true;
        // } else {
        //     return false;
        // }
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<int> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    std::sort(v.begin() , v.end() , Compare());

    for (int i = 0 ; i < n ; i++) {
        std::cout << v[i] << ' ';
    }
}
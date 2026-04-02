#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n , t; std::cin >> n;
    bool f = false;
    for (int i = 0 ; i < n ; i ++) {std::cin >> t; if (t) { f = true; break; };}

    if (f) std::cout << "HARD";
    else   std::cout << "EASY";
}
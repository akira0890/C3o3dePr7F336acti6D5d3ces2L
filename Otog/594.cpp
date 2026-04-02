#include <iostream>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::string s[50005];
    int n; std::cin >> n;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> s[i];
    }

    std::sort(s , s + n);

    for (int i = 0 ; i < n ; i++) std::cout << s[i] << '\n';
}
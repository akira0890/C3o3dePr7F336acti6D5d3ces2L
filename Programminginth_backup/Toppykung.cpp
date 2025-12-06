#include <iostream>
#include <set>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::set<std::string> v;

    std::string temp = "";
    for (int i = 0 ; i < n ; i++) std::cin >> temp , v.emplace(temp);

    for (const std::string &s : v) {
        std::cout << s << '\n';
    }
}
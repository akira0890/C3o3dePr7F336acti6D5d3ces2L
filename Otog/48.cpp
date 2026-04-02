#include <iostream>
#include <vector>
#include <algorithm>

struct Compare {
    bool operator()(const std::string &a , const std::string &b) {

        return (a+b) < (b+a);
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<std::string> v(n);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    std::sort(v.begin() , v.end() , Compare());

    for (int i = 0 ; i < n ; i++) {
        std::cout << v[i];
    }
}
#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<unsigned int> v(n+2,0);
    for (int i = 1 ; i <= n ; i++) std::cin >> v[i];
    unsigned int size = 0;

    for (int i = 1 ; i <= n ; i++) {
        if (v[i-1] != v[i] && v[i] != v[i+1]) size = std::max(size , v[i]);
    }

    std::cout << size;
}
#include <iostream>
#include <algorithm>

int v[1000];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,cmd; std::cin >> n >> cmd;

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    if (cmd) std::sort(v , v+n , std::greater<int>());
    else std::sort(v, v+n);

    for (int i = 0 ; i < n ; i++) std::cout << v[i] << ' ';
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n , res = 0; std::cin >> n;
    std::vector<int> v1(n) , v2(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v1[i];
    for (int i = 0 ; i < n ; i++) std::cin >> v2[i];

    std::sort(v1.begin() , v1.end());
    std::sort(v2.begin() , v2.end());

    for (int i = 0 ; i < n ; i++) res += std::abs(v1[i] - v2[i]);

    std::cout << res;
}

/*
-100 80
90 -70
*/
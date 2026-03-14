#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];
    int max = 0 , l = 0 , r = n-1 , len = n-1;

    while (l < r) {
        max = std::max(max , std::min(v[l], v[r]) * len);
        if (v[l] < v[r]) l++;
        else r--;
        len--;
    }

    std::cout << max;
}
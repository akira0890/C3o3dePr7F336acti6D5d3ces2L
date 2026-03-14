#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    std::vector<int> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    std::sort(v.begin() , v.end());

    long long sum = 0;
    int l = 0 , r = n-1;

    while (r - l + 1 >= 4) {
        sum += v[r];
        r -= 2;

        sum += v[l]; l++;
        sum += v[l]; l++;
    }

    while (l <= r) {
        sum += v[l];
        l++;
    }

    std::cout << sum;
}
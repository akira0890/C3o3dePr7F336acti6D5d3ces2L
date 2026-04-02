#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<long long> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    long long res = 1;
    for (int i = 0 ; i < n ; i++) {
        if (v[i] <= res) {
            res += v[i];
        } else {
            break;
        }
    }
    std::cout << res;
}
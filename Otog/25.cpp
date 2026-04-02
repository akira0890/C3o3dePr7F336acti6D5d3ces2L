#include <iostream>
#include <vector>
#include <algorithm>

long long prev[100000];
long long curr[100000];
inline void pascal(int n) {
    prev[1] = 1;
    for (int i = 1 ; i <= n+1 ; i++) {
        curr[1] = 1;
        for (int j = 2 ; j <= i ; j++) {
            curr[j] = (prev[j] + prev[j-1]) % 55555;
        }
        std::swap(prev , curr);
    }
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    pascal(n);

    for (int i = 1 ; i <= n+1 ; i++) std::cout << prev[i] << ' ';
}
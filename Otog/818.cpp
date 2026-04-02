#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m;std::cin >> n >> m;
    std::vector<long long> v(n);

    long long posy,posx,posy2,posx2;
    std::cin >> posx >> posy;
    v[0] = 0;

    for (int i = 1 ; i < n; i++) {
        std::cin >> posx2 >> posy2;
        v[i] = posx2 - posx + posy2 - posy;
    }

    std::sort(v.begin() , v.end());

    int sum = 0;
    long long target;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> target;

        int idx = 0;
        long long curr = 0;
        while (idx < n-1) {
            int it = std::lower_bound(v.begin() , v.end() , curr + target) - v.begin() - 1;
            idx = it;
            if (it == n-1) break;
            curr = v[idx];
            sum++;
        }
    }
    std::cout << sum;
}
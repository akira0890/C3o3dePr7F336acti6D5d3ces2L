#include <iostream>
#include <vector>
#include <climits>

#define ull unsigned long long

ull n,m;
int p[1'000'001];

inline ull calculate_total(ull time) {
    ull sum = 0;
    for (int i = 0 ; i < n ; i++) {
        sum += (time / (ull)p[i]);
        if (sum >= m) return sum;
    }
    return sum;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m;

    int minp = INT_MAX;
    for (int i = 0 ; i < n ; i++) std::cin >> p[i], minp = (p[i]<minp?p[i]:minp);

    ull l   = 0;
    ull r   = (ull)minp * m;
    ull ans = 0;

    while (l <= r) {
        ull mid = l + (r-l)/2;

        // if (mid == 0) {
        //     if (m == 0) { ans = 0; break; }
        //     l = mid + 1;
        //     continue;
        // }

        if (calculate_total(mid) >= m) {
            r = mid-1;
            ans = mid;
        } else {
            l = mid+1;
        }
    }

    std::cout << ans;
}
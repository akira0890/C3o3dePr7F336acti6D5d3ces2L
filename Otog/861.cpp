#include <iostream>
#include <vector>
#include <algorithm>

int Time(const std::vector<long long> &v , long long target) {
    auto it = std::lower_bound(v.begin() , v.end() , target);

    if (it == v.end()) return v.size() - 1;

    return it - v.begin();
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q; std::cin >> n >> q;
    long long t , sumA = 0 , sumB = 0;
    std::vector<long long> p1(n+1,0) , p2(n+1,0);

    for (int i = 1 ; i <= n ; i++) {
        std::cin >> t;
        sumA += t;
        p1[i] = std::max(p1[i-1] , sumA);
    }

    for (int i = 1 ; i <= n ; i++) {
        std::cin >> t;
        sumB += t;
        p2[i] = std::max(p2[i-1] , sumB);
    }

    while (q--) {
        long long K;
        std::cin >> K;
        
        long long l = 0 , r = K;
        int ans = n;
        while (l <= r) {
            long long mid = l + (r-l)/2;

            int t1 = Time(p1 , mid);
            int t2 = Time(p2 , K - mid);

            int currmax = std::max(t1 , t2);
            if (currmax < ans) ans = currmax;

            if (t1 < t2) l = mid+1;
            else r = mid-1;
        }
        std::cout << ans << '\n';
    }

}

/*
1 3  9 14 11 15 8 16 25 27
1 -1 2 6  11 1  9 5  10 25
*/
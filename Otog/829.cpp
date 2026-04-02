#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

struct Compare {
    bool operator()(const std::pair<long long , int>& A , long long target) {
        return A.first < target;
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m;
    std::cin >> n >> m;

    long long v;
    std::vector<long long> sum(n+2,0);
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> v;
        sum[i-1] += v;
        sum[i] += v;
        sum[i+1] += v;
    }
    sum[n] += INT_MAX;
    sum[0] = 0;
    sum[n+1] = LLONG_MAX;

    long long target;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> target;

        auto it = std::lower_bound(sum.begin() , sum.end() , target);

        std::cout << it - sum.begin() << '\n';
    }

}
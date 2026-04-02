#include <iostream>
#include <vector>
#include <algorithm>

struct Compare {
    bool operator()(const std::pair<int,int> &a , const std::pair<int,int> &b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }
};

int main() {
    // std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,t; std::cin >> n;
    std::vector<int> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];
    std::sort(v.begin() , v.end());
    std::cin >> m;
    std::vector<int> lamp(m);
    for (int i = 0 ; i < m ; i++) {
        std::cin >> t;
        lamp[i] = v[t-1];
    }
    std::sort(lamp.begin() , lamp.end());

    int ans = 0;
    int l = 1 , r = 1e9+1000;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        int count = 0;
        // std::vector<std::pair<int,int>> interval;
        for (int i = 0 ; i < m ; i++) {
            int start = lamp[i] - mid;
            int end   = lamp[i] + mid;

            while (count < n && start <= v[count] && v[count] <= end) {
                count++;
            }
            // interval.emplace_back(start , end);
        }
        // std::sort(interval.begin() , interval.end() , Compare());
        
        // std::vector<std::pair<int,int>> merge;

        // int start = interval[0].first;
        // int end = interval[0].second;
        // for (int i = 1 ; i < interval.size() ; i++) {
        //     if (interval[i].first <= end) {
        //         end = std::max(end , interval[i].second);
        //     } else {
        //         merge.emplace_back(start , end);
        //         start = interval[i].first;
        //         end = interval[i].second;
        //     }
        // }

        // bool coverAll = false;
        // if (merge.size() == 0 && start <= v[0] && v[n-1] <= end) coverAll = true;

        if (count == n) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    std::cout << ans;
}
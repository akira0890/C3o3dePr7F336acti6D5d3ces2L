#include <iostream>
#include <vector>
#include <algorithm>

struct interval {
    int s,e;
    bool operator<(const interval& other) { return s < other.s; }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,k,l,t;
    std::cin >> n >> m >> k >> l;

    std::vector<int> v(n);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    std::sort(v.begin(), v.end());

    while (k--) {
        std::vector<interval> intervals;
        for (int i = 0 ; i < m ; i++) {
            std::cin >> t;
            intervals.push_back({t-l,t+l});
        }
        
        std::sort(intervals.begin(), intervals.end());
        
        std::vector<interval> merge;
        interval curr = intervals[0];
        for (int i=1 ; i<intervals.size() ; i++) {
            if (intervals[i].s <= curr.e) curr.e = std::max(curr.e, intervals[i].e);
            else { merge.emplace_back(curr); curr = intervals[i]; }
        }
        merge.emplace_back(curr);
        
        int sum = 0;
        for (auto& interval_ : merge) {
            auto l = std::lower_bound(v.begin(), v.end(), interval_.s);
            auto r = std::upper_bound(v.begin(), v.end(), interval_.e);
            sum += r-l;
        }
        std::cout << sum << '\n';
    }
}
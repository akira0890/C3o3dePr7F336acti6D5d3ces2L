#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<int> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    std::vector<int> tail;
    std::vector<int> lEnd(n);

    for (int i = 0 ; i < n ; i++) {
        auto it = std::lower_bound(tail.begin() , tail.end() , v[i]);
        int idx = it - tail.begin();

        if (it == tail.end()) {
            tail.emplace_back(v[i]);
        } else {
            *it = v[i];
        }

        lEnd[i] = idx + 1;
    }

    std::vector<int> lStart(n);
    std::vector<int> tail_rev;
    for (int i = n-1 ; i >= 0 ; i--) {
        auto it = std::lower_bound(tail_rev.begin() , tail_rev.end() , v[i] , std::greater<int>());
        int idx = it - tail_rev.begin();

        if (it == tail_rev.end()) {
            tail_rev.emplace_back(v[i]);
        } else {
            *it = v[i];
        }

        lStart[i] = idx + 1;
    }

    int maxLen = tail.size();
    std::vector<int> ans;
    int curr = 1;
    int lastval = -20000000;

    for (int i = 0 ; i < n && curr <= maxLen; i++) {
        if (lEnd[i] == curr && (lEnd[i] + lStart[i] - 1 == maxLen) && v[i] > lastval) {
            lastval = v[i];
            ans.emplace_back(v[i]);
            curr++;
        }
    }

    std::cout << ans.size() << '\n';
    for (int i = 0 ; i < ans.size() ; i++) std::cout << ans[i] << ' ';
}
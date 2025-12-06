#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

struct info {
    int start,height,end;
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;

    std::vector<std::pair<int,int>> events;
    info t[n];

    for (int i = 0 ; i < n ; i++) std::cin >> t[i].start >> t[i].height >> t[i].end;

    for (info &x : t) {
        events.emplace_back(std::make_pair(x.start, +x.height));
        events.emplace_back(std::make_pair(x.end,   -x.height));
    }

    std::sort(events.begin(), events.end(), [](const std::pair<int,int> &a, const std::pair<int,int> &b){
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    std::multiset<int> h;
    h.insert(0);
    int preMax = 0;

    for (auto &x : events) {
        int pos = x.first, height = x.second;

        if (height > 0) h.insert((height));
        else h.erase(h.find(-height));

        int currMax = *h.rbegin();

        if (preMax != currMax) {
            std::printf("%d %d ", pos, currMax);
            preMax = currMax;
        }
    }
}
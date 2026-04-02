#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define pdd std::pair<double , double>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    std::vector<pdd> v(n);

    double x1,y1,x2,y2;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> x1 >> y1 >> x2 >> y2;

        double a1 = std::atan2(y1 , x1);
        double a2 = std::atan2(y2 , x2);
        v[i].first = std::min(a1 , a2);
        v[i].second = std::max(a1 , a2);
        // if (v[i].second >= 100000000) {
        //     v[i].second = 100000000;
        // }
    }

    std::sort(v.begin() , v.end() , [](const pdd& a , const pdd& b){
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    int nonOverlap = 1;

    double lastend = v[0].second;
    for (int i = 1 ; i < n ; i++) {
        if (lastend < v[i].first) {
            nonOverlap++;
            lastend = v[i].second;
        }
    }

    std::cout << n - nonOverlap;
}
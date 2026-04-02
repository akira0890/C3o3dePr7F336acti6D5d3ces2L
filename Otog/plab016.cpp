#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<long long> v(n);

    int num = 0;
    while (num < n) {
        std::cin >> v[num];
        num++;
    }

    std::sort(v.begin() , v.end());

    int found = 0 , sum = 0;
    int q;
    std::cin >> q;
    while (q--) {
        long long target;
        std::cin >> target;

        int l=0 , r = n-1 , ans = 0;
        while (l <= r) {
            int mid = l + (r-l)/2;

            if (v[mid] <= target) {
                ans = mid;
                l = mid+1;
            } else {
                r=mid-1;
            }
        }
        if (v[ans] == target) {
            found++;
            sum += n-ans;
        }
    }

    std::cout << found << ' ' << sum;
}
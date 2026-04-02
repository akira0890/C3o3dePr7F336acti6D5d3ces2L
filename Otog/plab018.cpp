#include <iostream>
#include <vector>
#include <algorithm>

void binarySearch(const std::vector<int> &v , int target , int l , int r , int &ans) {
    if (l <= r) {
        int mid = l + (r-l)/2;
 
        if (v[mid] <= target) {
            ans = mid;
            binarySearch(v , target , mid+1 , r , ans);
        } else {
            binarySearch(v , target , l , mid-1 , ans);
        }
    }

}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<int> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    std::sort(v.begin() , v.end());

    int q,t; std::cin >> q;
    int found = 0, odd = 0;

    for (int i = 0 ; i < q ; i++) {
        std::cin >> t;
        int ans = -1;

        binarySearch(v , t , 0 , n-1 , ans);

        if (v[ans] == t) {
            found++;
            if (t%2 == 1) odd++;
        }
    }

    std::cout << found << ' ' << odd;
}
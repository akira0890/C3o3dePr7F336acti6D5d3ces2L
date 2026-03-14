#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,k; std::cin >> n >> k;

    std::vector<int> v(n);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    int max = 0;
    for (int i = 0 ; i < n ; i++) {
        int l = i , r = n-1;
        int target = v[i] + k;
        while (l <= r) {
            int mid = (l+r)/2;

            if (v[mid] <= target) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        max = std::max(max , l-i-1);
    }

    std::cout << max;
}

/*
1 2 3 4 5  6  7  8  9  10 11
3 6 7 9 10 11 13 16 18 19 20


*/
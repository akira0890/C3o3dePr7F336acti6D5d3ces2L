#include <iostream>
#include <algorithm>
#include <climits>

long long prefix[5'000'001];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    long long n,t;
    std::cin >> n;

    std::cin >> prefix[0];
    for (int i = 1 ; i < n ; i++) {
        std::cin >> t;
        prefix[i] = prefix[i-1] + t;
    }

    long long mindiff = LLONG_MAX;
    int l=0,h=n-2,ind=0;

    while (l <= h) {
        int mid = (l+h)/2;
        long long sum1 = prefix[mid], sum2 = prefix[n-1] - sum1;
        long long diff = (sum1 > sum2) ? (sum1-sum2) : (sum2-sum1);

        if (mindiff == -1 || mindiff > diff) {
            mindiff = diff;
            ind = mid;
        }

        if (sum1 == sum2) {
            ind = mid;
            break;
        } else if (sum1 < sum2) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    std::cout << prefix[ind] << '\n' << ind;
}
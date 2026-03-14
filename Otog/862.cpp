#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<bool> prime(1000005,true);

void primecheck() {
    prime[0] = prime[1] = false;

    for (int i = 2 ; i*i < 1000005 ; i++) {
        if (prime[i]) {
            for (int j = i*i ; j < 1000005 ; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,k,t; std::cin >> n >> k;
    std::vector<int> prefix(n+1);
    prefix[0] = 0;

    primecheck();

    for (int i = 1 ; i <= n ; i++) {
        std::cin >> t;
        prefix[i] = prefix[i-1] + (prime[t] ? 1 : 0);
    }

    int l = 1 , r = n, ans = 0;
    while (l <= r) {
        int W = (l+r)/2;

        bool canfit = false;
        for (int i = 1 ; i <= n-W+1 ; i++) {
            int cnt = prefix[i+W-1] - prefix[i-1];
            if (cnt >= k) {
                canfit = true;
                break;
            }
        }

        if (canfit) {
            ans = W;
            r = W-1;
        } else {
            l = W+1;
        }
    }

    std::cout << ans;
}
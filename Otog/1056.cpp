#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

inline int msb(int n) {
    int pos = 0;
    while (n > 0) {
        n >>= 1;
        pos++;
    }
    return pos;
}

int main() {
    // std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q; std::cin >> n;
    std::map<int,int> freq;
    int a;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> a;
        freq[a]++;
    }

    std::vector<long long> dc(40,0) , rep(40,0);
    for (auto & [val , count] : freq) {
        int msbs =  msb(val);
        dc[msbs]++;
        if (count >= 2) rep[msbs]++;
    }
    
    std::map<long long , long long> pairs_to_k;

    long long dcSum = 0;
    long long repSum = 0;

    for (int i = 1 ; i < 40 ; i++) {
        dcSum += dc[i];
        repSum += rep[i];

        long long totalPair = (dcSum * (dcSum-1)/2) + repSum;

        if (totalPair > 0 && pairs_to_k.find(totalPair) == pairs_to_k.end()) {
            pairs_to_k[totalPair] = (1LL << i);
        }
    }

    long long bj;
    std::cin >> q;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> bj;

        if (pairs_to_k.find(bj) == pairs_to_k.end()) std::cout << "-1\n";
        else std::cout << pairs_to_k[bj] << '\n';
    }
}
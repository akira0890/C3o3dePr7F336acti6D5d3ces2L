#include <iostream>
#include <climits>

int main() {
    int n,k,temp,w;
    std::cin >> n >> k;

    int maxmask = (1 << k);
    int maskcnt = maxmask - 1;

    int dpmask[257];
    std::fill(dpmask, dpmask + maxmask, INT_MAX);
    dpmask[0] = 0;

    for (int i = 0 ; i < n ; i++) {
        std::cin >> w;
        int bit = 0;
        for (int j = 0 ; j < k ; j++) {
            std::cin >> temp;
            if (temp) bit |= (1 << j);
        }

        int newdp[257];
        std::copy(dpmask, dpmask + maxmask, newdp);

        for (int oldmask = 0 ; oldmask < maxmask ; oldmask++) {
            if (dpmask[oldmask] == INT_MAX) continue;

            int newmask = oldmask | bit;
            newdp[newmask] = std::min(newdp[newmask], dpmask[oldmask] + w);
        }

        std::copy(newdp, newdp + maxmask, dpmask);
    }

    std::cout << dpmask[maskcnt];
}
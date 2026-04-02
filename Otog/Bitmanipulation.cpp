#include <iostream>
#include <vector>
#include <bitset>

std::bitset<30000> bit;

int main() {
    int n,pos,value;
    std::cin >> n;

    for (int i = 0 ; i < 30000 ; i++) {
        std::cin >> pos >> value;
        if (value) bit.set(pos);
        else bit.reset(pos);
    }

    for (int i = 0 ; i < n ; i++) {
        std::cin >> pos;
        bit.flip();
        bit.set(pos);
    }

    int l,r;
    std::cin >> n;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> l >> r;
        for (int j = l ; j <= r ; j++) {
            bit.flip(j);
        }
    }

    int longZero = 0 , longOne = 0;
    std::vector<int> startZero , startOne;

    int k; std::cin >> k;
}
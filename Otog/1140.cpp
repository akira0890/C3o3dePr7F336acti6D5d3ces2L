#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    
    int n,m;
    std::cin >> n >> m;
    int val[4] = {0,2,3,1} , tval[4] = {1,3,4,2};
    
    while (m--) {
        unsigned long long q,sum=0;
        std::cin >> q;
        unsigned long long currq = q;

        for (int i = n-1 ; i >= 0 ; i--) {
            unsigned long long blocksize = 1ULL << (2*i);

            unsigned long long quadrant = (currq - 1) / blocksize;
            sum += val[quadrant] * blocksize;

            currq = (currq-1)%blocksize+1;
        }
        std::cout << sum+1 << '\n';
    }
}
#include <iostream>
#include <vector>

int dpcurr[10005];
int dpprev[10005];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::string a,b; std::cin >> a >> b;
    int maxLen = 0;
    int idx;

    for (int i = 1 ; i <= a.length() ; i++) {
        for (int j = 1 ; j <= b.length() ; j++) {
            if (a[i-1] == b[j-1]) {
                dpcurr[j] = dpprev[j-1] + 1;

                if (dpcurr[j] > maxLen) {
                    maxLen = dpcurr[j];
                    idx = j;
                }
            } else {
                dpcurr[j] = 0;
            }
        }
        std::swap(dpprev , dpcurr);
    }

    std::cout << b.substr(idx - maxLen , maxLen);
}
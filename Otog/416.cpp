#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 3035; 
long long h[MAXN];
int stk[MAXN];

inline long long readLL() {
    long long x = 0;
    int c = getchar();

    while (c != EOF && (c < '0' || c > '9')) {
        if (c == EOF) return -1;
        c = getchar();
    }

    if (c == EOF) return -1;

    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

int main() {
    while (true) {
        long long n = readLL();
        if (n <= 0) break;

        for (int i = 0; i < n; i++) {
            h[i] = readLL();
        }
        h[n] = 0;

        int top = -1;
        long long max_area = 0;

        for (int i = 0; i <= n; i++) {
            while (top != -1 && h[stk[top]] >= h[i]) {
                long long height = h[stk[top--]];
                long long width = (top == -1) ? i : (i - stk[top] - 1);
                
                long long current_area = height * width;
                if (current_area > max_area) {
                    max_area = current_area;
                }
            }
            stk[++top] = i;
        }
        printf("%lld\n", max_area);
    }
    return 0;
}



// #include <iostream>
// #include <vector>
// #include <algorithm>

// #define ull unsigned long long

// int main() {
//     std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

//     int n;
//     while (std::cin >> n && n != 0) {
//         std::vector<ull> v(n+1);
//         std::vector<int> stk;
//         ull maxs = 0;
//         stk.reserve(n+1);

//         for (int i = 0 ; i < n ; i++) std::cin >> v[i];
//         v[n] = 0;

//         for (int i = 0 ; i <= n ; i++) {
//             while (!stk.empty() && v[i] <= v[stk.back()]) {
//                 ull heigth = v[stk.back()];
//                 stk.pop_back();

//                 ull width = (stk.empty())? i : i-stk.back()-1;
//                 maxs = std::max(maxs , heigth * width);
//             }
//             stk.emplace_back(i);
//         }

//         std::cout << maxs << '\n';
//     }
// }
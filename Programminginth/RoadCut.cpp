#include <iostream>
#include <climits>

int max(const int a, const int b) {
    if (a >= b) return a;
    return b;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    int n,m, sum = 0, temp, highest = INT_MIN;
    std::cin >> n >> m;
    
    int prefixX[m] = {0};
    int prefixY[n] = {0};
    int incX[m] = {0};
    int incY[n] = {0};

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            std::cin >> temp;
            prefixX[j] += temp;
            prefixY[i] += temp;
            sum += temp;
        }
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            std::cin >> temp;
            incX[j] += temp;
            incY[i] += temp;
        }
    }

    int tempsum;
    for (int i = 0 ; i < m ; i++) {
        tempsum = sum;
        tempsum -= prefixX[i];
        if (i-1 >= 0) tempsum += incX[i-1];
        if (i+1 < m) tempsum += incX[i+1];
        highest = max(highest, tempsum);
    }

    for (int i = 0 ; i < n ; i++) {
        tempsum = sum;
        tempsum -= prefixY[i];
        if (i-1 >= 0) tempsum += incY[i-1];
        if (i+1 < n) tempsum += incY[i+1];
        highest = max(highest, tempsum);
    }

    std::cout << highest;
}
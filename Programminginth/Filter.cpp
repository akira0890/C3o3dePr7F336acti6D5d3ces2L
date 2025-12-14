/*
the problem is to find value of heigth * length where there is no interval on that area and interval where it intersect one.

this code initialize 3000 element array accord to the max length, then loop through that range and plus all element in that range by one on every curtain.
then find every range where there is one curtain on that area and only one intersect curtain on that area and then print that 2 range * height;
*/

#include <iostream>

int window[3000] = {0};

int main() {
    int n,m,t,start,to;
    std::cin >> n >> m >> t;

    while (t--) {
        std::cin >> start >> to;
        for (int i = start ; i < start + to ; i++) window[i]++;
    }

    int zero = 0,half = 0;
    for (int i = 0 ; i < n ; i++) {
        if (window[i] == 0) zero++;
        else if (window[i] == 1) half++;
    }
    std::cout << zero*m << ' ' << half*m;
}
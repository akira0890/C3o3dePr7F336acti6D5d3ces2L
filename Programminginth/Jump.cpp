/*
The problem is to find the maximum value of skip point when jump to next position

Sol:
on every element find upper bound of that element value to jump position (value+jump power)
substract that index from the upper bound - 1. it till give the skip position and keep the maximum one.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n,h,best = 0;
    std::cin >> n >> h;

    std::vector<int> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    for (int i = 0 ; i < n ; i++) {
        int target = v[i] + h;
        int to = std::upper_bound(v.begin()+i , v.end() , target) - v.begin();
        best = std::max(best, to-i-1);
    }

    std::cout << best;
}
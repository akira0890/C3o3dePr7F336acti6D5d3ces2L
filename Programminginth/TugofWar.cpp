/*
The problem is to find smallest sum of difference between two array

Sol
sort two array first then find the difference of 2 array index by index.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;

    std::vector<int> a(n),b(n);

    for (int i = 0 ; i < n ; i++) std::cin >> a[i];
    for (int i = 0 ; i < n ; i++) std::cin >> b[i];

    std::sort(a.begin(),a.end());
    std::sort(b.begin(),b.end());

    int sum = 0;
    for (int i = 0 ; i < n ; i++) sum += std::abs(a[i]-b[i]);
    std::cout << sum;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,value; std::cin >> n;
    std::string s;
    std::vector<std::string> word(n);
    std::vector<long long> v(n);
    for (int i = 0 ; i < n ; i++) std::cin >> word[i];
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    std::sort(word.begin() , word.end());

    long long sum = 0;
    long long j = 0;

    do {
        for (int i = 0 ; i < n ; i++) {
            sum += v[i] * word[i].length();
        }
        j++;
    } while (std::next_permutation(word.begin() , word.end()));

    std::cout << j << ' ' << sum;
}
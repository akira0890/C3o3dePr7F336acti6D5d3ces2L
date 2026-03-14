#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int move , s; std::cin >> move >> s;

    std::vector<int> prefix(10);
    for (int i = 0 ; i < 10 ; i++) {
        int start1 = move/100;
        for (int j = 0 ; j < i ; j++) {
            start1 = (start1+1)%10;
        }
        int start2 = (move%100)/10;
        for (int j = 0 ; j < start1 ; j++) {
            start2 = (start2+1)%10;
        }
        int start3 = move%10;
        for (int j = 0 ; j < start2 ; j++) {
            start3 = (start3+1)%10;
        }
        prefix[i] = start3;
        std::cout << start1 << ' ' << start2 << ' ' << start3 << ' ' << prefix[i] << '\n';
    }
}
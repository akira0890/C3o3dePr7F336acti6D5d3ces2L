#include <iostream>

int val[] = {100,90,50,40,10,9,5,4,1};
std::string roman[] = {"C","XC","L","XL","X","IX","V","IV","I"};

inline std::string convertroman(int n) {
    int index = 0;
    std::string ans;
    while (n) {
        if (val[index] > n) index++;
        else {
            n -= val[index];
            ans += roman[index];
        }
    }
    return ans;
}

int main() {
    int ans[5] = {0,0,0,0,0};
    int n;
    std::cin >> n;

    for (int i = 1 ; i <= n ; i++) {
        std::string romans = convertroman(i);
        for (char c : romans) {
            if (c == 'I') ans[0]++;
            else if (c == 'V') ans[1]++;
            else if (c == 'X') ans[2]++;
            else if (c == 'L') ans[3]++;
            else if (c == 'C') ans[4]++;
        }
    }

    for (int x : ans) std::cout << x << ' ';
}
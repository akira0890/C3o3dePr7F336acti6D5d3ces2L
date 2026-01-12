#include <iostream>

inline int mod9(int N) {
    if (N > 9) return N-9;
    return N;
}

inline int nextindexup(int N, int k) {
    if (N-k < 0) return 9-k+N;
    return N-k;
}

inline int nextindexdown(int N, int k) {
    return (N+k)%9;
}

int main() {
    int key[3],num[256],n;
    std::string in,out = "";

    std::cin >> in; for (int i = 0 ; i < 3 ; i++) key[i] = in[i]-'0';
    std::cin >> in; for (int i = 0 ; i < in.length() ; i++) num[i] = in[i]-'0';
    n = in.length();

    int w1[9], w2[9], w3[9];
    for (int i = 1 ; i <= 9 ; i++)  w1[i-1] = mod9(key[0]+i-1),
                                    w2[i-1] = mod9(key[1]+i-1),
                                    w3[i-1] = mod9(key[2]+i-1);

    for (int i = 0 ; i < 9 ; i++) std::cout << w1[i]; std::cout << '\n';
    for (int i = 0 ; i < 9 ; i++) std::cout << w2[i]; std::cout << '\n';
    for (int i = 0 ; i < 9 ; i++) std::cout << w3[i]; std::cout << '\n';

    for (int i = 0 ; i < n ; i++) {
        char target,temp;
        target = w1[num[i]-1];
        target = w2[target-1];
        target = w3[target-1];

        out += target + '0';

        for (int j = 0 ; j < 9 ; j++) {std::swap(w1[j],w1[nextindexup(j,key[0])]);}

        for (int j = 0 ; j < 9 ; j++) {
            temp = 
            std::swap(w1[j],w1[nextindexdown(j,1)]);
        }

        for (int j = 0 ; j < 9 ; j++) {
            std::swap(w1[j],w1[nextindexup(j,key[2])]);
        }

        for (int j = 0 ; j < 9 ; j++) std::cout << w1[j]; std::cout << '\n';
        for (int j = 0 ; j < 9 ; j++) std::cout << w2[j]; std::cout << '\n';
        for (int j = 0 ; j < 9 ; j++) std::cout << w3[j]; std::cout << '\n';
    }
}
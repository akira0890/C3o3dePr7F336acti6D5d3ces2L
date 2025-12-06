#include <iostream>
#include <algorithm>

#define f first
#define s second

std::pair<std::pair<int,int>, std::string> t[4];
int res[4][4];
int sum[4];
int shoted[4];

struct compare {
    bool operator()(const std::pair<std::pair<int,int>, std::string> &a , const std::pair<std::pair<int,int>, std::string> &b) {
        if (a.f.f != b.f.f) return a.f.f > b.f.f;
        else if (sum[a.f.s] - shoted[a.f.s] != sum[b.f.s] - shoted[b.f.s]) return sum[a.f.s] - shoted[a.f.s] > sum[b.f.s] - shoted[b.f.s];
        else return sum[a.f.s] > sum[b.f.s];
    }
};

int main() {

    for (int i = 0 ; i < 4 ; i++) {
        std::cin >> t[i].second;
        t[i].first.first = 0;
        t[i].first.second = i;
    }

    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            std::cin >> res[i][j];
        }
    }

    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            sum[i] += res[i][j];
            shoted[i] += res[j][i];
        }
    }

    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            if (res[i][j] > res[j][i]) t[i].first.first += 3;
            else if (res[i][j] == res[j][i] && i != j) t[i].first.first += 1;
        }
    }

    std::sort(t , t + 4 , compare());

    for (int i = 0 ; i < 4 ; i++) {
        std::cout << t[i].second << ' ' << t[i].first.first << '\n';
    }
}
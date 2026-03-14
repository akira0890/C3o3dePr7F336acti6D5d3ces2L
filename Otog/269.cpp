#include <iostream>
#include <vector>

struct Node {
    int l =-1, r=2000;
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    std::vector<char> v(n);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    int score = 0;
    while (!v.empty()) {
        std::vector<Node> mindiff(4); // U B O N
        bool foundanypair = false;

        std::cout << "work1\n";

        int Ul = -1 , Ur = 2000;
        int Bl = -1 , Br = 2000;
        int Ol = -1 , Or = 2000;
        int Nl = -1 , Nr = 2000;
        for (int i = 0 ; i < v.size() ; i++) {
            if (v[i]=='U') {
                if (Ul == -1) Ul = i;
                else {
                    Ur = i;
                    if (mindiff[0].r - mindiff[0].l > Ur - Ul) {
                        mindiff[0].r = Ur;
                        mindiff[0].l = Ul;
                        foundanypair = true;
                    }
                    Ul = Ur;
                }
            }

            if (v[i]=='B') {
                if (Bl == -1) Bl = i;
                else {
                    Br = i;
                    if (mindiff[1].r - mindiff[1].l > Br - Bl) {
                        mindiff[1].r = Br;
                        mindiff[1].l = Bl;
                        foundanypair = true;
                    }
                    Bl = Br;
                }
            }

            if (v[i]=='O') {
                if (Ol == -1) Ol = i;
                else {
                    Or = i;
                    if (mindiff[2].r - mindiff[2].l > Or - Ol) {
                        mindiff[2].r = Or;
                        mindiff[2].l = Ol;
                        foundanypair = true;
                    }
                    Ol = Or;
                }
            }

            if (v[i]=='N') {
                if (Nl == -1) Nl = i;
                else {
                    Nr = i;
                    if (mindiff[3].r - mindiff[3].l > Nr - Nl) {
                        mindiff[3].r = Nr;
                        mindiff[3].l = Nl;
                        foundanypair = true;
                    }
                    Nl = Nr;
                }
            }
        }

        if (!foundanypair) {
            std::cout << "doesn't found\n";
            break;
        }

        std::cout << "work2\n";

        int minInd = 0 , diff = 2000;
        for (int i = 0 ; i < 4 ; i++) {
            if (mindiff[i].r - mindiff[i].l < diff) minInd = i , diff = mindiff[i].r - mindiff[i].l;
        }

        std::cout << "work3\n";

        for (int i = 0 ; i < v.size() ; i++) {
            std::cout << v[i] << ' ';
        }
        std::cout << '\n';

        std::cout << "work4\n";

        int l = mindiff[minInd].l , r = mindiff[minInd].r;
        for (int i = l ; i <= r ; i++) {
            v.erase(v.begin() + l);
        }

        std::cout << "work5\n";


        score++;
    }

    std::cout << score;
}
#include <iostream>

/*
บน หน้า ซ้าย หลัง ขวา ล่าง
1  2    3   5   4   6

                       บน หน้า ซ้าย หลัง ขวา ล่าง
หมุนมาทางด้านหน้า(F)      5   1   3   6   4   2
หมุนไปทางด้านหลัง(B)      2   6   3   1   4   5
หมุนไปทางซ้าย(L)         4   2   1   5   6   3
หมุนไปทางขวา(R)         3   2   6   5   1   4
หมุนตามเข็มนาฬิกา(C)      1   4   2   3   5   6
หมุนทวนเข็มนาฬิกา(D)      1   3   5   4   2   6

As you can see to turn dice any direction is just swap element
so to solve this. loop through every character in the turn string and swap element accord to the table then print the Front face
*/

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        int s[6] = {1,2,3,5,4,6};
        std::string turn;
        std::cin >> turn;

        for (char c : turn) {
            if (c == 'F') {
                int t1 = s[0], t2 = s[1], t4 = s[3], t6 = s[5];
                s[0] = t4; s[1] = t1; s[3] = t6; s[5] = t2;
            } else if (c == 'B') {
                int t1 = s[0], t2 = s[1], t4 = s[3], t6 = s[5];
                s[0] = t2; s[1] = t6; s[3] = t1; s[5] = t4;
            } else if (c == 'L') {
                int t1 = s[0], t3 = s[2], t5 = s[4], t6 = s[5];
                s[0] = t5; s[2] = t1; s[4] = t6; s[5] = t3;
            } else if (c == 'R') {
                int t1 = s[0], t3 = s[2], t5 = s[4], t6 = s[5];
                s[0] = t3; s[2] = t6; s[4] = t1; s[5] = t5;
            } else if (c == 'C') {
                int t2 = s[1], t3 = s[2], t4 = s[3], t5 = s[4];
                s[1] = t5; s[2] = t2; s[3] = t3; s[4] = t4;
            } else if (c == 'D') {
                int t2 = s[1], t3 = s[2], t4 = s[3], t5 = s[4];
                s[1] = t3; s[2] = t4; s[3] = t5; s[4] = t2;
            }
        }
        std::cout << s[1] << ' ';
    }
}
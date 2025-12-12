#include <iostream>
#include <vector>

/*
for each 3*3 square of string vector then find match pattern turn it into integer after process 2 string vector and get two return int value then plus them together
*/

inline long long process(std::vector<std::string> &a) {
    long long result = 0;

    for (int col = 0 ; col < a[0].length() ; col += 4) {
        if (a[0][col] == ' ' && a[0][col+1] == ' ' && a[0][col+2] == ' ' &&
            a[1][col] == ' ' && a[1][col+1] == ' ' && a[1][col+2] == '|' &&
            a[2][col] == ' ' && a[2][col+1] == ' ' && a[2][col+2] == '|')
            result = result * 10 + 1;
        else if (a[0][col] == ' ' && a[0][col+1] == '_' && a[0][col+2] == ' ' &&
                 a[1][col] == ' ' && a[1][col+1] == '_' && a[1][col+2] == '|' &&
                 a[2][col] == '|' && a[2][col+1] == '_' && a[2][col+2] == ' ')
                 result = result * 10 + 2;
        else if (a[0][col] == ' ' && a[0][col+1] == '_' && a[0][col+2] == ' ' &&
                 a[1][col] == ' ' && a[1][col+1] == '_' && a[1][col+2] == '|' &&
                 a[2][col] == ' ' && a[2][col+1] == '_' && a[2][col+2] == '|')
                 result = result * 10 + 3;
        else if (a[0][col] == ' ' && a[0][col+1] == ' ' && a[0][col+2] == ' ' &&
                 a[1][col] == '|' && a[1][col+1] == '_' && a[1][col+2] == '|' &&
                 a[2][col] == ' ' && a[2][col+1] == ' ' && a[2][col+2] == '|')
                 result = result * 10 + 4;
        else if (a[0][col] == ' ' && a[0][col+1] == '_' && a[0][col+2] == ' ' &&
                 a[1][col] == '|' && a[1][col+1] == '_' && a[1][col+2] == ' ' &&
                 a[2][col] == ' ' && a[2][col+1] == '_' && a[2][col+2] == '|')
                 result = result * 10 + 5;
        else if (a[0][col] == ' ' && a[0][col+1] == '_' && a[0][col+2] == ' ' &&
                 a[1][col] == '|' && a[1][col+1] == '_' && a[1][col+2] == ' ' &&
                 a[2][col] == '|' && a[2][col+1] == '_' && a[2][col+2] == '|')
                 result = result * 10 + 6;
        else if (a[0][col] == ' ' && a[0][col+1] == '_' && a[0][col+2] == ' ' &&
                 a[1][col] == ' ' && a[1][col+1] == ' ' && a[1][col+2] == '|' &&
                 a[2][col] == ' ' && a[2][col+1] == ' ' && a[2][col+2] == '|')
                 result = result * 10 + 7;
        else if (a[0][col] == ' ' && a[0][col+1] == '_' && a[0][col+2] == ' ' &&
                 a[1][col] == '|' && a[1][col+1] == '_' && a[1][col+2] == '|' &&
                 a[2][col] == '|' && a[2][col+1] == '_' && a[2][col+2] == '|')
                 result = result * 10 + 8;
        else if (a[0][col] == ' ' && a[0][col+1] == '_' && a[0][col+2] == ' ' &&
                 a[1][col] == '|' && a[1][col+1] == '_' && a[1][col+2] == '|' &&
                 a[2][col] == ' ' && a[2][col+1] == '_' && a[2][col+2] == '|')
                 result = result * 10 + 9;
        else result *= 10;
    }

    return result;
}

void print(std::string &s) {
    for (char c : s) {
        if (c == ' ') std::cout << '.';
        else std::cout << c;
    }
    std::cout << '\n';
}

int main() {
    int n,m;
    std::cin >> n >> m;

    std::vector<std::string> a(3),b(3);

    std::cin.ignore();

    std::getline(std::cin, a[0]);
    std::getline(std::cin, a[1]);
    std::getline(std::cin, a[2]);
    std::getline(std::cin, b[0]);
    std::getline(std::cin, b[1]);
    std::getline(std::cin, b[2]);

    print(a[0]);
    print(a[1]);
    print(a[2]);
    print(b[0]);
    print(b[1]);
    print(b[2]);

    std::cout << process(a) << ' ' << process(b) << '\n';

    std::cout << process(a) + process(b);
}
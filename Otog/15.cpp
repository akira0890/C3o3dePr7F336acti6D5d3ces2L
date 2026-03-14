#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n;
    std::string s;
    std::cin >> n;

    while (n--) {
        std::cin >> s;
        int array[6] = {1,2,3,5,4,6};
        int a,b,c,d;

        for (int i = 0 ; i < s.length() ; i++) {
            switch (s[i]) {
            case 'F':
                a = array[0] , b = array[1] , c = array[3] , d = array[5];
                array[0] = c;
                array[1] = a;
                array[3] = d;
                array[5] = b;
                break;
            case 'B':
                a = array[0] , b = array[1] , c = array[3] , d = array[5];
                array[0] = b;
                array[1] = d;
                array[3] = a;
                array[5] = c;
                break;
            case 'L':
                a = array[0] , b = array[2] , c = array[4] , d = array[5];
                array[0] = c;
                array[2] = a;
                array[4] = d;
                array[5] = b;
                break;
            case 'R':
                a = array[0] , b = array[2] , c = array[4] , d = array[5];
                array[0] = b;
                array[2] = d;
                array[4] = a;
                array[5] = c;
                break;
            case 'C':
                a = array[1] , b = array[2] , c = array[3] , d = array[4];
                array[1] = d;
                array[2] = a;
                array[3] = b;
                array[4] = c;
                break;
            case 'D':
                a = array[1] , b = array[2] , c = array[3] , d = array[4];
                array[1] = b;
                array[2] = c;
                array[3] = d;
                array[4] = a;
                break;
            
            default:
                break;
            }
        }
        std::cout << array[1] << ' ';
    }
}
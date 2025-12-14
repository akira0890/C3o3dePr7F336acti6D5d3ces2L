/*
the problem want to find the x,y destination and distance of origin point(0,0) to x,y destination

to find the answer at each input add the value to that x,y direction (if it diagonal multiply that value by cos45 = 1/sqrt(2))
repeat the process until the input is "*" then calculate and print the answer 
*/

// #include <iostream>
// #include <cmath>

// static double sqrt2 = std::sqrt(2);

// int main() {
//     double x=0,y=0, val;
//     std::string temp;

//     while (std::cin >> temp && temp != "*") {
//         val = 0;
//         std::string dir = "";
//         for (char c : temp) {
//             if (c >= '0' && c <= '9') val = val*10 + (c-'0');
//             else dir += c;
//         }

//         if      (dir == "N") y += val;
//         else if (dir == "E") x += val;
//         else if (dir == "S") y -= val;
//         else if (dir == "W") x -= val;
//         else if (dir == "NE") x+= val / sqrt2, y+= val / sqrt2;
//         else if (dir == "SE") x+= val / sqrt2, y-= val / sqrt2;
//         else if (dir == "SW") x-= val / sqrt2, y-= val / sqrt2;
//         else if (dir == "NW") x-= val / sqrt2, y+= val / sqrt2;
//         std::cout << x << ' ' << y << '\n';
//     }

//     std::printf("%.3f %.3f\n%.3f", x, y, std::sqrt(x*x + y*y));
// }

#include <iostream>
#include <cmath>

static double sqrt2 = std::sqrt(2);

int main() {
    double x = 0, y = 0;
    std::string info;
    while (std::cin >> info && info != "*") {
        int val = 0;
        std::string dir = "";
        for (int i = 0 ; i < info.length() ; i++) {
            if (isdigit(info[i]))val = val * 10 + info[i] - '0';
            else dir += info[i];
        }

        if (dir == "N") y += val;
        else if (dir == "NE") y += val / sqrt2, x += val / sqrt2;
        else if (dir == "E") x += val;
        else if (dir == "SE") y -= val / sqrt2, x += val / sqrt2;
        else if (dir == "S") y -= val;
        else if (dir == "SW") y-= val / sqrt2, x -= val / sqrt2;
        else if (dir == "W") x -= val;
        else if (dir == "NW") y += val / sqrt2, x -= val / sqrt2;
    }
    std::printf("%.3f %.3f\n%.3f",x,y,std::sqrt(x*x + y*y));
}
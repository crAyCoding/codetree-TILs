#include <iostream>

int main() {
    int a = 5, b = 6, c = 7, temp;
    temp = b;
    b = a;
    a = c;
    c = temp;
    std::cout << a << std::endl << b << std::endl << c;
    return 0;
}
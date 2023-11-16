#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a,b,c;
    cin >> a >> b >> c;
    if(a>b && a>c) {
        cout << ceil(a) << " ";
        if(b<c) {
            cout << floor(b) << " " << round(c);
        }
        else {
            cout << floor(c) << " " << round(b);
        }
    } else if(b>c && b>a) {
        cout << ceil(b) << " ";
        if(a<c) {
            cout << floor(a) << " " << round(c);
        }
        else {
            cout << floor(c) << " " << round(b);
        }
    } else {
        cout << ceil(c) << " ";
        if(b<a) {
            cout << floor(b) << " " << round(a);
        }
        else {
            cout << floor(a) << " " << round(b);
        }
    }
    return 0;
}
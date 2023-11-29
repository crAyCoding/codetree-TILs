#include <iostream>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int j=m,k=min(n,m-n);
    double result = 1.0;
    while(k>0) {
        result *= j;
        result /= (double)k;
        j--;
        k--;
    }
    cout << (int)result;
    return 0;
}
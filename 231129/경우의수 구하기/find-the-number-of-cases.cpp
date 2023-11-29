#include <iostream>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int j=m,k=min(n,m-n);
    long long int result = 1;
    for(int i=0;i<k;i++) result *= j--;
    for(int i=1;i<=k;i++) result /= i;
    cout << result;
    return 0;
}
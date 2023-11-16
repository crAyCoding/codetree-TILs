#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    long long n = 0, c = 1;
    for(int i=s.length()-1;i>=0;i--) {
        n += (int)(s[i] - 48) * c;
        c *= 2;
    }
    n *= 17;
    vector<int> v;
    while(n>0) {
        v.push_back(n%2);
        n /= 2;
    }
    for(int i=v.size()-1;i>=0;i--) {
        cout << v[i];
    }
    return 0;
}
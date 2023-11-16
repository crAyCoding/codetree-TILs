#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = 0, c = 1;
    for(int i=s.length()-1;i>=0;i--) {
        n += (int)(s[i] - 48) * c;
        c *= 2;
    }
    n *= 17;
    string result = "";
    while(n>0) {
        result += ('0' + n % 2);
        n /= 2;
    }
    reverse(result.begin(),result.end());
    cout << result;
    return 0;
}
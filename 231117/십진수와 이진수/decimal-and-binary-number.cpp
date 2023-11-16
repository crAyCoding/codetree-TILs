#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s,result;
    cin >> s;
    int slen = s.length();
    reverse(s.begin(),s.end());
    result = s + "0000";
    for(int i=0;i<slen;i++) {
        if(s[i] == '1') {
            result[i+4] += 1;
        }
    }
    for(int i=0;i<result.length();i++) {
        if(result[i] >= '2') {
            result[i+1] += 1;
            result[i] -= 2;
        }
    }
    reverse(result.begin(),result.end());
    cout << result;
    return 0;
}
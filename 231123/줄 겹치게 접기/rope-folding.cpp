#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,l,answer = 0;
    cin >> n >> l;
    vector<int> v(l+1);
    for(int i=0;i<n;i++) {
        int d;
        cin >> d;
        v[d] = 1;
    }
    for(int i=1;i<l;i++) {
        int cnt = i < l - i ? i : l - i;
        bool result = true;
        for(int j=0;j<cnt;j++) {
            if(v[i-j-1] != v[i+j+1]) {
                result = false;
                break;
            }
        }
        if(result) answer++;
    }
    cout << answer;
    return 0;
}
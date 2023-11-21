#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) 
    {
        cin >> v[i];
    }
    vector<int> vv = v;
    vv.erase(unique(vv.begin(), vv.end()), vv.end());
    int result = 0;
    for(int i : vv) {
        for(int j=0;j<n;j++) {
            int temp = v[j], cnt = 1;
            if(temp == i) continue;
            while(j < n - 1) {
                if(v[j+1] == i) {
                    j++;
                    continue;
                }
                if(v[j+1] != temp) break;
                cnt++;
                j++;
            }
            result = result > cnt ? result : cnt;
        }
    }
    cout << result;
    return 0;
}
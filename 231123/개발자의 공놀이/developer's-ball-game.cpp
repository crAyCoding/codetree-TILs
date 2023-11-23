#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,answer=0;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    for(int i=0;i<n-2;i++) {
        while(v[i] - v[i+1] >= v[i+1] - v[i+2]) {
            if(i==n-3) {
                answer++;
                break;
            }
            i++;
        }
        answer++;
    }
    cout << answer;
    return 0;
}
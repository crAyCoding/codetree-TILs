#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,answer=0;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<n-2;i++) {
        while(v[i] - v[i+1] >= v[i+1] - v[i+2]) {
            i++;
            if(i == n-2) break;
        }
        answer++;
        if(i==n-2 && v[i]-v[i+1] < v[i+1] - v[i+2]) answer++;
    }
    cout << answer;
    return 0;
}
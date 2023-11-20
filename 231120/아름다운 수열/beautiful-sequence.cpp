#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m;
    cin >> n;
    vector<int> N(n);
    for(int i=0;i<n;i++) cin >> N[i];
    cin >> m;
    vector<int> M(m);
    vector<int> result;
    for(int i=0;i<m;i++) cin >> M[i];
    sort(M.begin(),M.end());
    for(int i=0;i<n-m+1;i++) {
        vector<int> v(N.begin() + i, N.begin() + i + m);
        sort(v.begin(),v.end());
        int temp = v[0] - M[0];
        for(int j=0;j<m;j++) {
            if(v[j] - M[j] != temp) break;
            if(j==m-1) result.push_back(i+1);
        }
    }
    cout << result.size() << endl;
    for(int i=0;i<result.size();i++) {
        cout << result[i] << endl;
    }
    return 0;
}
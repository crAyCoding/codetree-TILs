#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(k),b(k);
    vector<int> result(n);
    for(int i=0;i<k;i++) {
        cin >> a[i] >> b[i];
        for(int j = a[i]-1;j<b[i];j++) {
            result[j]++;
        }
    }
    sort(result.begin(),result.end());
    cout << result[n/2];
    return 0;
}
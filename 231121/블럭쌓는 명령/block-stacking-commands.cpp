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
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ai = 0, bi = 0, cnt = 0;
    for(int i=1;i<=n;i++) {
        while(bi < k && b[bi] == i) {
            bi++;
            cnt--;
        }
        while(ai < k && a[ai] == i) {
            ai++;
            cnt++;
        }
        result[i-1] = cnt;
    }
    sort(result.begin(),result.end());
    cout << result[n/2];
    return 0;
}
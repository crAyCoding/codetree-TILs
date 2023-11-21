#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,min_num = 1e9,max_num = -1;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) 
    {
        cin >> v[i];
        min_num = v[i] < min_num ? v[i] : min_num;
        max_num = v[i] > max_num ? v[i] : max_num;
    }
    int result = 0;
    for(int i=min_num;i<=max_num;i++) {
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
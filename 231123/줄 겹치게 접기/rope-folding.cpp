#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,l,answer = 0;
    cin >> n >> l;
    vector<int> v(l+1),dots(n);
    for(int i=0;i<n;i++) {
        cin >> dots[i];
        v[dots[i]] = 1;
    }
    sort(dots.begin(),dots.end());
    int left = 0;
    for(int i=0;i<n;i++) {
        int temp = i < n-i-1 ? i : n-i-1;
        bool flag = false;
        for(int j=0;j<temp;j++) {
            if(dots[i] - dots[i-j-1] != dots[i+j+1] - dots[i]) break;
            if(j==temp-1) flag = true;
        }
        if(flag) answer++;
        if(i==n-1) break;
        float fp = (float)(dots[i+1] + dots[i]) / 2;
        int temp2 = i+1 < n-i-1 ? i+1 : n-i-1;
        bool flag2 = true;
        for(int j=0;j<temp2;j++) {
            float fpl = fp - dots[i-j];
            float fpr = dots[i+j+1] - fp;
            if(fpl != fpr) {
                flag2 = false;
                break;
            }
        }
        if(flag2) answer++;
    }
    cout << answer;
}
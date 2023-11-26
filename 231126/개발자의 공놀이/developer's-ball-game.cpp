#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<int> v, int i) {
    int count = 0, n = v.size();
    vector<bool> isTrue(n,false);
    while(true) {
        isTrue[i] = true;
        int prev = i-1, next = i+1;
        if(prev < 0) {
            i = next;
        } else if(next >= n) {
            i = prev;
        } else {
            if(v[prev] - v[i] < v[i] - v[next]) i = prev;
            else i = next; 
        }
        count++;
        if(isTrue[i]) return count;
    }
}

int main() {
    int n,answer = 0;
    cin >> n;
    vector<int> v(n),cnt(n),isBall(n,0);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<n;i++) {
        cnt[i] = check(v,i);
    }
    for(int k=n-1;k>=0;k--) {
        for(int i=0;i<n;i++) {
            if(cnt[i] == k && !isBall[i]) {
                int temp = i;
                while(true) {
                    int prev = temp-1, next = temp+1;
                    isBall[temp] = 1;
                    if(prev < 0) {
                        temp = next;
                    } else if(next >= n) {
                        temp = prev;
                    } else {
                        if(v[prev] - v[temp] < v[temp] - v[next]) temp = prev;
                        else temp = next; 
                    }
                    if(isBall[temp]) break;
                }
                answer++;
            }
        }
    }
    cout << answer;
    return 0;
}
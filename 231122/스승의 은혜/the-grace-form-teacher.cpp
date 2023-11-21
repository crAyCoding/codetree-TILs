#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    return a.first + a.second < b.first + b.second;
}

int check(vector<pair<int,int>> v, int i, int b) {
    int p = v[i].first, s = v[i].second;
    v.push_back(make_pair(p / 2, s));
    sort(v.begin(),v.end(),compare);
    int cnt = 0;
    for(int j=0;j<v.size();j++) {
        if(v[j].first == p && v[j].second == s) continue;
        b -= (v[j].first + v[j].second);
        if(b < 0) break;
        cnt++;
    }
    return cnt;
}

int main() {
    int n,b,answer = -1;
    cin >> n >> b;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) {
        int p,s;
        cin >> p >> s;
        v.push_back(make_pair(p,s));
    }
    for(int i=0;i<n;i++) {
        int result = check(v,i,b);
        answer = answer > result ? answer : result;
    }
    cout << answer;
    return 0;
}
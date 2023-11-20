#include <iostream>
#include <vector>

using namespace std;

bool checkCarry(int a, int b) {
    while(true) {
        if(a%10 + b%10 > 9) return true;
        a/=10;
        b/=10;
        if(a == 0 || b == 0) return false;
    }
}

bool checkNine(int num) {
    while(num>0) {
        if(num%10 == 9) return true;
        num /= 10;
        if(num == 0) return false;
    }
}

int max_answer = -1;

void find(int num,vector<int> v,int i,int cnt) {
    if(checkNine(num)) {
        max_answer = max_answer = max_answer > cnt ? max_answer : cnt;
        return;
    }
    for(int j=i;j<v.size();j++) {
        if(checkCarry(num,v[j])) {
            find(num,v,j+1,cnt);
            return;
        }
        if(j==v.size()-1) {
            max_answer = max_answer > cnt + 1 ? max_answer : cnt + 1;
            return;
        }
        find(num+v[j],v,j+1,cnt+1);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    find(0,v,0,0);
    cout << max_answer;
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int N,B;
    int maxNum = -1, sum = 0, answer = 0;
    bool flag = true, flag2 = false;
    cin >> N >> B;
    for(int i=0;i<N;i++)
    {
        int p,s;
        cin >> p >> s;
        if (flag2) {
            continue;
        }
        maxNum = maxNum < p ? p : maxNum;
        sum = sum + p + s;
        if(sum > B) {
            if(flag && sum - (maxNum / 2) <= B) {
                flag = false;
                sum -= maxNum / 2;
            }
            else {
                answer = i;
                flag2 = true;
            }
        }
    }
    cout << answer;
    return 0;
}
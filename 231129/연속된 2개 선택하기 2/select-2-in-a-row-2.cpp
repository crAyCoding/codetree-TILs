#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> v(n),dp(n);
    for(int i=0;i<n;i++) cin >> v[i];
    dp[0] = v[0];
    double result = dp[0];
    for(int i=1;i<n;i++) {
        dp[i] = max(v[i], dp[i-1]*v[i]);
        result = max(dp[i],result);
    }
    printf("%.3lf",round(result*1000)/1000);
    return 0;
}
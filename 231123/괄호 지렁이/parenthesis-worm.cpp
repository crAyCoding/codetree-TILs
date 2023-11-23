#include <iostream>
#include <vector>

using namespace std;

int n,answer = 0;
char** arr;

void check(vector<vector<bool>> isVisited,int x, int y, int l,int r, bool isLeft) {
    if(x < 0 || x >= n) return;
    if(y < 0 || y >= n) return;
    if(isVisited[x][y]) return;
    isVisited[x][y] = true;
    if(!isLeft && arr[x][y] == '(') return;
    if(isLeft && arr[x][y] == ')') isLeft = false;
    int nowL = isLeft == true ? l+1 : l;
    int nowR = isLeft != true ? r+1 : r;
    if(nowL == nowR) {
        answer = answer > nowL + nowR ? answer : nowL + nowR;
        return;
    }
    check(isVisited,x+1,y,nowL,nowR,isLeft);
    check(isVisited,x-1,y,nowL,nowR,isLeft);
    check(isVisited,x,y+1,nowL,nowR,isLeft);
    check(isVisited,x,y-1,nowL,nowR,isLeft);
}

int main() {
    cin >> n;
    arr = (char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++) arr[i] = (char*)malloc(n*sizeof(char));
    vector<vector<bool>> isVisited(n,vector<bool>(n,false));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cin >> arr[i][j];
    }
    check(isVisited,0,0,0,0,true);
    cout << answer;
    return 0;
}
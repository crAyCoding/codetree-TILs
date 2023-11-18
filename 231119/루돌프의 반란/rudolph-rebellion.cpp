#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct {
    int r,c,number,score;
    bool isStun,isFail,rudolphStun;
}santa;

vector<santa> santaVec;
int failedSanta = 0,n,m,p,rr,rc,c,d;

bool compareSanta(santa a, santa b) {
    return a.number < b.number;
}

santa findTarget() {
    int minDistance = 1e9, maxR = -1, maxC = -1;
    santa targetSanta;
    for(santa s : santaVec) {
        if(s.isFail == true) continue;
        int distance = (rr-s.r) * (rr-s.r) + (rc-s.c) * (rc-s.c);
        if(distance<minDistance) {
            minDistance = distance;
            maxR = s.r;
            maxC = s.c;
            targetSanta = s;
        }
        else if(distance==minDistance) {
            if(s.r > maxR) {
                maxR = s.r;
                targetSanta = s;
            }
            else if(s.r == maxR) {
                if(s.c > maxC) {
                    maxC = s.c;
                    targetSanta = s;
                }
            }
        }
    }
    return targetSanta;
}

int rudoplhRDirection(santa targetSanta) {
    if(targetSanta.r > rr) {
        return 1;
    }
    else if(targetSanta.r == rr) {
        return 0;
    }
    else return -1;
}

int rudoplhCDirection(santa targetSanta) {
    if(targetSanta.c > rc) {
        return 1;
    }
    else if(targetSanta.c == rc) {
        return 0;
    }
    else return -1;
}

void checkSantaCollision(int i,int dR, int dC) {
    if(santaVec[i].r < 1 || santaVec[i].r > n || santaVec[i].c < 1 || santaVec[i].c > n) {
        santaVec[i].isFail = true;
        return;
    }
    for(int j=0;j<santaVec.size();j++) {
        if(i==j) continue;
        if(santaVec[j].isFail == true) continue;
        if(santaVec[i].r == santaVec[j].r && santaVec[i].c == santaVec[j].c) {
            santaVec[j].r -= dR;
            santaVec[j].c -= dC;
            checkSantaCollision(j,dR,dC);
            return;
        }
    }
}

void rudolphSantaCollision(int i, int dR, int dC) {
    santaVec[i].score += c;
    santaVec[i].r += dR * c;
    santaVec[i].c += dC * c;
    santaVec[i].isStun = true;
    santaVec[i].rudolphStun = true;
    checkSantaCollision(i,-dR,-dC);
}

void santaRudolphCollision(int i, int dR, int dC) {
    santaVec[i].score += d;
    santaVec[i].r -= dR * d;
    santaVec[i].c -= dC * d;
    santaVec[i].isStun = true;
    checkSantaCollision(i,dR,dC);
}

bool isSanta(int i,int dr,int dc) {
    for(int j=0;j<santaVec.size();j++) {
        if(santaVec[j].r == santaVec[i].r + dr && santaVec[j].c == santaVec[i].c + dc) {
            return true;
        }
    }
    return false;
}

pair<int,int> santaDirection(santa s) {
    int rD = s.r - rr;
    int cD = s.c - rc;
    int dr = rD < 0 ? 1 : -1;
    int dc = cD < 0 ? 1 : -1;
    int i = s.number - 1;
    if(rD != 0 && cD != 0) {
        if(dr == -1 && !isSanta(i,dr,0)) return make_pair(dr,0);
        if(dc == 1 && !isSanta(i,0,dc)) return make_pair(0,dc);
        if(dr == 1 && !isSanta(i,dr,0)) return make_pair(dr,0);
        if(dc == -1 && !isSanta(i,0,dc)) return make_pair(0,dc);
    }
    if(rD != 0 && !isSanta(i,dr,0)) return make_pair(dr,0);
    if(cD != 0 && !isSanta(i,0,dc)) return make_pair(0,dc);
    return make_pair(0,0);
}

void rudolphMove() {
    santa targetSanta = findTarget();
    int dR = rudoplhRDirection(targetSanta);
    int dC = rudoplhCDirection(targetSanta);
    rr += dR;
    rc += dC;
    if(rr == targetSanta.r && rc == targetSanta.c) {
        rudolphSantaCollision(targetSanta.number - 1,dR,dC);
    }
    //cout << "RUDOLPH : " << rr << "," << rc << endl;
}

void santaMove() {
    for(int i=0;i<santaVec.size();i++) {    
        if(santaVec[i].isFail) continue;
        if(santaVec[i].rudolphStun)
        {
            santaVec[i].rudolphStun = false;
            continue;
        }
        else if(santaVec[i].isStun) {
            santaVec[i].isStun = false;
            continue;
        }
        pair<int,int> santaD = santaDirection(santaVec[i]);
        int dR = santaD.first, dC = santaD.second;
        santaVec[i].r += dR;
        santaVec[i].c += dC;
        if(rr == santaVec[i].r && rc == santaVec[i].c) {
            santaRudolphCollision(i,dR,dC);
        }
        //cout << "SANTA " << santaVec[i].number << ":" << santaVec[i].r << "," << santaVec[i].c << endl;
    }
}

bool isGameOver() {
    for(int i=0;i<santaVec.size();i++) {
        if(!santaVec[i].isFail) return false;
    }
    return true;
}

void endTurn() {
    for(int i=0;i<santaVec.size();i++) {
        if(!santaVec[i].isFail) {
            santaVec[i].score++;
        }
    }
}

int main() {
    cin >> n >> m >> p >> c >> d;
    cin >> rr >> rc;
    for(int i=0;i<p;i++) {
        santa newSanta;
        cin >> newSanta.number >> newSanta.r >> newSanta.c;
        newSanta.score = 0;
        newSanta.isFail = false;
        newSanta.isStun = false;
        newSanta.rudolphStun = false;
        santaVec.push_back(newSanta);
    }
    sort(santaVec.begin(),santaVec.end(),compareSanta);
    for(int k=1;k<=m;k++) {
        //cout << "TURN" << k << endl;
        rudolphMove();
        santaMove();
        if(isGameOver()) break;
        endTurn();
        for(int i=0;i<santaVec.size();i++) {
            //cout << santaVec[i].score << " ";
        }
        //cout << endl;
    }
    for(int i=0;i<santaVec.size();i++) {
        cout << santaVec[i].score;
        if(i == santaVec.size() - 1) break; 
        cout << " ";
    }
    return 0;
}
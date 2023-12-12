#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fileio() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define allr(x) x.rbegin(), x.rend()
#define cmprs(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define endl "\n"
#define sp " "
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define rz resize
#define sz(a) (int)(a.size())
#define clr(a) a.clear()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

// set<vector<vector<int>>> ans[4][4][4];
// void go(int st, int bw, pii lst, vector<int> &stk, vector<vector<int>> &cur) {
//     for (int i=0; i<4; i++) {
//         if (cur[i][1]!=-1 && cur[i][1]==cur[i][2] && (cur[i][0]==cur[i][1]||cur[i][3]==cur[i][1])) {
//             if (!bw && cur[i][1]==0) ans[st][lst.F][lst.S].insert(cur);
//             return;
//         }
//     }
//     for (int j=0; j<4; j++) {
//         if (cur[1][j]!=-1 && cur[1][j]==cur[2][j] && (cur[0][j]==cur[1][j]||cur[3][j]==cur[1][j])) {
//             if (!bw && cur[1][j]==0) ans[st][lst.F][lst.S].insert(cur);
//             return;
//         }
//     }
    
//     for (int i=1; i<=2; i++) {
//         for (int j=1; j<=2; j++) {
//             if (cur[i][j]!=-1 && cur[i][j]==cur[i-1][j-1] && cur[i][j]==cur[i+1][j+1]) {
//                 if (!bw && cur[i][j]==0) ans[st][lst.F][lst.S].insert(cur);
//                 return;
//             }
//             if (cur[i][j]!=-1 && cur[i][j]==cur[i-1][j+1] && cur[i][j]==cur[i+1][j-1]) {
//                 if (!bw && cur[i][j]==0) ans[st][lst.F][lst.S].insert(cur);
//                 return;
//             }
//         }
//     }

//     for (int j=0; j<4; j++) {
//         if (stk[j]==4) continue;

//         cur[stk[j]][j]=!bw;
//         stk[j]++;
//         go(st,!bw,{stk[j]-1,j},stk,cur);
//         stk[j]--;
//         cur[stk[j]][j]=-1;
//     }
// }

int ans[4][4][4]={
    {
        {0, 287, 311, 80},
        {96, 609, 675, 76},
        {315, 543, 455, 351},
        {342, 188, 204, 286}
    },

    {
        {47, 0, 175, 55},
        {94, 630, 516, 69},
        {431, 364, 615, 171},
        {177, 252, 116, 172}
    },

    {
        {55, 175, 0, 47},
        {69, 516, 630, 94},
        {171, 615, 364, 431},
        {172, 116, 252, 177}
    },

    {
        {80, 311, 287, 0},
        {76, 675, 609, 96},
        {351, 455, 543, 315},
        {286, 204, 188, 342}
    }
};
 
 
int main() {
    fio();
    int x,a,b;
    cin>>x>>a>>b;
    cout<<ans[--x][--a][--b];
    return 0;
}
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
const int MAX = 55; // PLZ CHK!



int main() {
    fio();
    int n,m;
    cin>>m>>n;
    
    pii s,e;
    string a[MAX];
    vector<pii> b;
    int c[MAX][MAX]={0};
    for (int i=0; i<n; i++) {
        cin>>a[i];
        for (int j=0; j<m; j++) {
            if (a[i][j]=='S') s={i,j};
            if (a[i][j]=='E') e={i,j};
            if (a[i][j]=='X') {
                c[i][j]=sz(b);
                b.pb({i,j});
            }
        }
    }
    
    queue<pair<pii,int>> q;
    int v[MAX][MAX][(1<<5)+1]={0}, d[MAX][MAX][(1<<5)+1]={0};
    q.push({s,0});
    v[s.F][s.S][0]=1;
    int cnt=sz(b);

    while (!q.empty()) {
        auto [cur, cst]=q.front(); q.pop();
        if (cur==e && cst==(1<<cnt)-1) {
            cout<<d[cur.F][cur.S][cst];
            break;
        }

        for (int i=0; i<4; i++) {
            pii nxt={cur.F+dx[i], cur.S+dy[i]};
            if (a[nxt.F][nxt.S]=='#' ||nxt.F<0||nxt.F>=n||nxt.S<0||nxt.S>=m) continue;

            int nst=cst;
            if (a[nxt.F][nxt.S]=='X' && !(cst&(1<<c[nxt.F][nxt.S]))) 
                nst|=(1<<c[nxt.F][nxt.S]);

            if (v[nxt.F][nxt.S][nst]) continue;
            q.push({nxt,nst});
            v[nxt.F][nxt.S][nst]=1;
            d[nxt.F][nxt.S][nst]=d[cur.F][cur.S][cst]+1;
        }
    }
    return 0;
}
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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010; // PLZ CHK!
const int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

int n,m;
pii s,e;
int a[MAX][MAX], d1[MAX][MAX], d2[MAX][MAX];
int mni[MAX], mnj[MAX];
vector<pii> g[MAX][MAX], rg[MAX][MAX];

bool ok(int i, int j) {return (1<=i&&i<=n&&1<=j&&j<=m);}

void bfs1() {
    queue<pii> q;
    int v[MAX][MAX]={0};
    for (int i=0; i<MAX; i++) for (int j=0; j<MAX; j++) d1[i][j]=INF;
    
    q.push(s), v[s.F][s.S]=1, d1[s.F][s.S]=0;
    while (!q.empty()) {
        auto [x,y]=q.front(); q.pop();
        for (auto [nx,ny]:g[x][y]) {
            if (!v[nx][ny]) {
                v[nx][ny]=1;
                d1[nx][ny]=d1[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}

void bfs2() {
    queue<pii> q;
    int v[MAX][MAX]={0};
    for (int i=0; i<MAX; i++) for (int j=0; j<MAX; j++) d2[i][j]=INF;

    q.push(e), v[e.F][e.S]=1, d2[e.F][e.S]=0;
    while (!q.empty()) {
        auto [x,y]=q.front(); q.pop();
        for (auto [nx,ny]:rg[x][y]) {
            if (!v[nx][ny]) {
                v[nx][ny]=1;
                d2[nx][ny]=d2[x][y]+1;
                q.push({nx,ny});
            }
        }
    }

    fill(mni, mni+MAX, INF), fill(mnj, mnj+MAX, INF);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            mni[i]=min(mni[i], d2[i][j]);
            mnj[j]=min(mnj[j], d2[i][j]);
        }
    }
}

void solve() {
    int ans=d2[s.F][s.S];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            ans=min(ans, d1[i][j]+mni[i]+1);
            ans=min(ans, d1[i][j]+mnj[j]+1);
        }
    }

    cout<<(ans>=INF?-1:ans);
}

int main() {
    fio();
    cin>>n>>m;
    cin>>s.F>>s.S>>e.F>>e.S;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin>>a[i][j];
            for (int k=0; k<4; k++) {
                int x=i+dx[k]*a[i][j], y=j+dy[k]*a[i][j];
                if (ok(x,y)) g[i][j].pb({x,y}), rg[x][y].pb({i,j});
            }
        }
    }

    bfs1();
    bfs2();
    solve();

    return 0;
}
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
const int dx[]={1,-1,0,0,-1,-1,1,1};
const int dy[]={0,0,1,-1,-1,1,-1,1};
int n;
char m[MAX][MAX];
vector<int> a(2);
vector<pii> g[MAX*MAX*2];
bool v[MAX][MAX];
int ii[MAX][MAX];
vector<pii> ed;

void dfs(int x, int y, int id) {
    ii[x][y]=id;
    v[x][y]=1;
    a[id]++;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (0>nx||nx>n+1||0>ny||ny>n+1) continue;
        if (!v[nx][ny] && m[x][y]==m[nx][ny]) dfs(nx,ny,id);
    }
}

void dij() {
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    int d[MAX*MAX*2];
    bool vst[MAX*MAX*2]={0};
    memset(d,INF,sizeof d);
    
    d[0]=0;
    pq.push({0,0});
    while (!pq.empty()) {
        auto [dst,cur]=pq.top(); pq.pop();
        if (dst!=d[cur]) continue;
        for (auto [nxt,cst]:g[cur]) {
            if (d[nxt]>d[cur]+cst) {
                d[nxt]=d[cur]+cst;
                pq.push({d[nxt],nxt});
            }
        }
    }
    
    cout<<d[2];
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) for (int j=0; j<MAX; j++) m[i][j]='x',ii[i][j]=-1;
    
    cin>>n;
    for (int i=1; i<=n; i++) {
        string t; cin>>t;
        for (int j=1; j<=n; j++) {
            m[i][j]=t[j-1];
        }   
    }
    
    for (int i=2; i<=n+1; i++) m[i][0]=m[0][i]='a';
    for (int i=0; i<n; i++) m[n+1][i]=m[i][n+1]='a';

    dfs(2,0,0),dfs(0,2,1);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (!v[i][j] && m[i][j]!='x' && m[i][j]!='.') {
                a.pb(0);
                dfs(i,j,sz(a)-1);
            }
        }
    }
    
    for (int i=0; i<=n+1; i++) {
        for (int j=0; j<=n+1; j++) {
            if (m[i][j]=='x'||m[i][j]=='.') continue;
            for (int k=0; k<8; k++) {
                int ni=i+dx[k],nj=j+dy[k];
                if (0>ni||ni>n+1||0>nj||nj>n+1||m[ni][nj]=='x'||m[ni][nj]=='.') continue;
                if (m[i][j]!=m[ni][nj]) ed.pb({ii[i][j],ii[ni][nj]});
            }
        }
    }
    cmprs(ed);

    for (int i=0; i<sz(a); i++) g[i<<1].pb({i<<1|1,(i==0||i==1?0:a[i])});
    
    for (auto [s,e]:ed) {
        s=s<<1|1, e=e<<1;
        g[s].pb({e,0});
    }

    dij();
    return 0;
}
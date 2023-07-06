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
const int MAX = 1010; // PLZ CHK!

int n,m;
int a[MAX][MAX];
int d[MAX][MAX][4], v[MAX][MAX][4];

int dfs(int x, int y, int dir) {
    if (a[x][y]==-1) return 0;
    v[x][y][dir]=1;

    int nx=x, ny=y, nd=dir;
    if (a[x][y]) {
        if (dir==0) nx--, nd=1;
        else if (dir==1) ny++, nd=0;
        else if (dir==2) nx++, nd=3;
        else ny--, nd=2;
    }
    else {
        if (dir==0) nx++, nd=3;
        else if (dir==1) ny--, nd=2;
        else if (dir==2) nx--, nd=1;
        else ny++, nd=0;
    }

    if (v[nx][ny][nd]) return d[x][y][dir]=1+d[nx][ny][nd];
    else return d[x][y][dir]=1+dfs(nx,ny,nd);
}

int main() {
    fio();
    
    cin>>n>>m;
    for (int i=0; i<MAX; i++) fill(a[i],a[i]+MAX,-1);

    for (int i=1; i<=n; i++) {
        string s; cin>>s;
        for (int j=1; j<=m; j++) {
            a[i][j]=(s[j-1]=='/');
        }
    }

    int ans=0;
    for (int i=1; i<=n; i++) {
        ans=max(ans, dfs(i,1,0));
        ans=max(ans, dfs(i,m,2));
    }
    for (int j=1; j<=m; j++) {
        ans=max(ans, dfs(1,j,3));
        ans=max(ans, dfs(n,j,1));
    }
    
    cout<<ans;
    return 0;
}
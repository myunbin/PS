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
const int MAX = 10101; // PLZ CHK!
int r,c;
string a[MAX];
bool v[MAX][555];
const int dx[]={-1,0,1}, dy[]={1,1,1};

int ans=0;
bool dfs(int x, int y) {
    v[x][y]=1;
    if (y==c-1) {
        ++ans;
        return 1;
    }

    for (int i=0; i<3; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (0>nx||nx>=r||0>ny||ny>=c||v[nx][ny]||a[nx][ny]=='x') continue;
        if (dfs(nx,ny)) return 1;
    }
    return 0;
}

int main() {
    fio();
    cin>>r>>c;
    for (int i=0; i<r; i++) cin>>a[i];

    for (int i=0; i<r; i++) dfs(i,0);
    cout<<ans;
    return 0;
}
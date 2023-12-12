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
const int MAX = 10101; // PLZ CHK!

int n,sz[MAX];
vector<int> g[MAX],ans;

void dfs(int cur, int prv) {
    sz[cur]=1;
    for (int nxt:g[cur]) {
        if (nxt==prv) continue;
        dfs(nxt, cur);
        sz[cur]+=sz[nxt];
    }

    bool ok=1;
    if (2*(n-sz[cur])>n) ok=0;
    for (int nxt:g[cur]) {
        if (2*sz[nxt]>n) {
            ok=0;
            break;
        }
    }

    if (ok) ans.pb(cur);
}

int main() {
    fio();
    cin>>n;
    for (int i=0; i<n-1; i++) {
        int u,v; cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }

    dfs(1,0);
    sort(all(ans));
    
    for (int x:ans) cout<<x<<endl;
    return 0;
}
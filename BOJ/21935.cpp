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
const int MAX = 202020; // PLZ CHK!
int n,m;
vector<int> g[MAX];
int nt[MAX], d[MAX];

void dfs(int cur, int prv) {
    bool ok=0;
    if (nt[cur]) {
        vector<int> vc;
        for (int nxt:g[cur]) {
            if (nxt==prv) continue;
            if (!nt[nxt]) {
                ok=1;
                vc.pb(nxt);
            }
        }
        if (sz(vc)==1) {
            nt[vc[0]]=1;
        }
    }
    else ok=1;

    if (!ok) return;

    d[cur]=1;
    for (int nxt:g[cur]) {
        if (nxt==prv) continue;
        dfs(nxt, cur);
        d[cur]+=d[nxt];
    }
}

int main() {
    fio();
    cin>>n>>m;
    for (int i=0; i<n-1; i++) {
        int u,v; cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }
    for (int i=0; i<m; i++) {
        int x; cin>>x;
        nt[x]=1;
    }

    dfs(1,0);
    cout<<d[1];

    return 0;
}
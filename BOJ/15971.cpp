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
const int MAX = 101010; // PLZ CHK!

int n,s,t,mx[MAX],sm[MAX];
vector<pii> g[MAX];

void dfs(int cur, int prv) {
    for (auto [nxt, cst]:g[cur]) {
        if (nxt==prv) continue;
        sm[nxt]=sm[cur]+cst;
        mx[nxt]=max(mx[cur], cst);
        dfs(nxt, cur);
    }
}

int main() {
    fio();
    cin>>n>>s>>t;
    for (int i=0; i<n-1; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w}), g[v].pb({u,w});
    } 
    dfs(s,0);
    cout<<sm[t]-mx[t];
    return 0;
}
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

void dfs1(int cur, int prv, vector<vector<pii>> &g, vector<int> &cst) {
    for (auto [nxt, cc]:g[cur]) {
        if (nxt==prv) continue;
        cst[nxt]=cc;
        dfs1(nxt,cur,g,cst);
    }    
}

void dfs2(int cur, int prv, vector<vector<pii>> &g, vector<int> &cst, vector<int> &dp) {
    dp[cur]=cst[cur];
    int sum=0;
    for (auto [nxt,cc]:g[cur]) {
        if (nxt==prv) continue;
        dfs2(nxt,cur,g,cst,dp);
        sum+=dp[nxt];
    }
    if (sum) dp[cur]=min(dp[cur],sum);
}

void solve(int n, int c) {
    vector<vector<pii>> g(n+1);
    for (int i=0; i<n-1; i++) {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        g[u].pb({v,w}), g[v].pb({u,w});
    }
    vector<int> cst(n+1);
    cst[c]=INF;
    dfs1(c,0,g,cst);

    vector<int> dp(n+1);
    dfs2(c,0,g,cst,dp);

    printf("%d\n",dp[c]);
}

int main() {
    fio();
    int n,c;
    while (scanf("%d %d",&n,&c)!=EOF) solve(n,c);
    return 0;
}
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

struct edge{
    int v,w,i;
};

int n;
vector<edge> g[MAX];

int dfs(int cur, int prv) {
    int ret=0;
    for (auto [nxt, cst, idx]:g[cur]) {
        if (nxt==prv) continue;
        ret+=dfs(nxt, cur)+cst;
    }
    return ret;
}

int d[MAX];

void dfs2(int cur, int prv) {
    for (auto [nxt, cst, idx]:g[cur]) {
        if (nxt==prv) continue;
        if (!cst) d[nxt]=d[cur]+1;
        else d[nxt]=d[cur]-1;
        dfs2(nxt, cur);
    }
}


int ans[MAX];

void dfs3(int cur, int prv) {
    for (auto [nxt, cst, idx]:g[cur]) {
        if (nxt==prv) continue;
        ans[idx]=cst;
        dfs3(nxt, cur);
    }
}

int main() {
    fio();

    cin>>n;
    for (int i=0; i<n-1; i++) {
        int u,v;
        cin>>u>>v;
        g[u].pb({v,0,i});
        g[v].pb({u,1,i});
    }

    memset(d,-1,sizeof d);
    d[1]=dfs(1,0);
    
    dfs2(1,0);
    
    int mi=min_element(d+1, d+n+1)-d;
    dfs3(mi, 0);
    
    for (int i=0; i<n-1; i++) cout<<ans[i];
    return 0;
}
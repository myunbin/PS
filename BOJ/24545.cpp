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

int N,P[MAX],D[MAX];
vector<int> G[MAX];

void dfs(int cur, int prv) {
    P[cur]=prv;
    D[cur]=D[prv]+1;
    for (int nxt:G[cur]) {
        if (nxt==prv) continue;
        dfs(nxt,cur);
    }
}

int V[MAX];

int f(int cur) {
    V[cur]=1;
    int ret=0;
    for (int nxt:G[cur]) {
        if (V[nxt]) continue;
        ret=max(ret, 1+f(nxt));
    }
    return ret;
}

int main() {
    fio();
    cin>>N;
    for (int i=0; i<N-1; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v), G[v].pb(u);
    }

    dfs(1,0);
    pii mx={0,0};
    for (int i=1; i<=N; i++) mx=max(mx, {D[i],i}), D[i]=P[i]=0;
    
    dfs(mx.S,0);
    mx={0,0};
    for (int i=1; i<=N; i++) mx=max(mx, {D[i],i});

    vector<int> dia;
    for (int i=mx.S; i; i=P[i]) dia.pb(i), V[i]=1;
    
    int SZ=sz(dia), ans=0;
    for (int i=1; i<SZ-1; i++) {
        int t=f(dia[i]);
        if (t>0) ans=max(ans, SZ+t);
    }

    cout<<ans;
    
    return 0;
}
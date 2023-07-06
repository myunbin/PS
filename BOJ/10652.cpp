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
const int MAX = 40404; // PLZ CHK!

vector<int> g[MAX];
ll b,e,p;
int n,m;

int v[MAX];

void bfs(int st, vector<int> &d) {
    queue<int> q;
    q.push(st);
    v[st]=1;
    d[st]=0;
    while (!q.empty()) {
        int cur=q.front();
        q.pop();
        for (int nxt:g[cur]) {
            if (v[nxt]) continue;
            v[nxt]=1;
            d[nxt]=d[cur]+1;
            q.push(nxt);
        }
    }
}

int main() {
    fio();
    cin>>b>>e>>p>>n>>m;
    
    for (int i=0; i<m; i++) {
        int u,v; cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }

    vector<int> d1(n+1), d2(n+1), d3(n+1);

    memset(v,0,sizeof v);
    bfs(1, d1);
    
    memset(v,0,sizeof v);
    bfs(2, d2);
    
    memset(v,0,sizeof v);
    bfs(n, d3);

    ll ans=b*d1[n]+e*d2[n];
    for (int i=1; i<=n; i++) {
        ll t=1ll*b*d1[i]+1ll*e*d2[i]+1ll*p*d3[i];
        ans=min(ans, t);
    }

    cout<<ans;
    return 0;
}
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
const int MAX = 303030; // PLZ CHK!
int n;
vector<int> g[MAX];
ll D,G;
int v[MAX],s[MAX][4];

void dfs(int cur) {
    s[cur][0]=1;
    v[cur]=1;
    for (int nxt:g[cur]) {
        if (v[nxt]) continue;
        dfs(nxt);
        s[cur][1]+=s[nxt][0];
        s[cur][2]+=s[nxt][1];
        s[cur][3]+=s[nxt][2];
    }
    D+=1ll*s[cur][3]+1ll*s[cur][2]*(s[cur][1]-1);
}
int main() {
    fio();
    cin>>n;
    for (int i=0; i<n-1; i++) {
        int u,v; cin>>u>>v;
        g[u].pb(v),g[v].pb(u);
    }
    
    for (int i=1; i<=n; i++) {
        ll x=sz(g[i]);
        if (x>=3) G+=1ll*x*(x-1)*(x-2)/6;
    }

    dfs(1);
    // cout<<D<<sp<<G<<endl;

    if (D>3*G) cout<<"D";
    else if (D<3*G) cout<<"G";
    else cout<<"DUDUDUNGA";
    return 0;
}